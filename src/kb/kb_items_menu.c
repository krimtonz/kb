#include <stdlib.h>
#include <libundermine.h>
#include "kb.h"
#include "bk.h"
#include "items.h"

/*ITEM QUANTITIES*/
static void item_set_count(bk_item_t item, uint32_t count){
    uint32_t clamped_cnt = count;
    uint32_t max_health = 0; 
    switch (item)
    {
    case BK_ITEM_HEALTH_MAX:
        if(count > 8) {
            bk_global_flag_set(BK_G_FLAG_DOUBLE_HEALTH,0x01);
            clamped_cnt = 16;
        }else{
            bk_global_flag_set(BK_G_FLAG_DOUBLE_HEALTH,0x00);
        }

        if(count < 16 && bk_item_get_count(BK_ITEM_HEALTH) > count){
            item_set_count(BK_ITEM_HEALTH, count);
        }
        else if(bk_item_get_count(BK_ITEM_HEALTH) > clamped_cnt){
            item_set_count(BK_ITEM_HEALTH, clamped_cnt);
        }
        break;
    case BK_ITEM_HEALTH:
        max_health =  bk_item_get_count(BK_ITEM_HEALTH_MAX);
        if(count > max_health) item_set_count(BK_ITEM_HEALTH_MAX, count);
        max_health =  bk_item_get_count(BK_ITEM_HEALTH_MAX);
        if(count > max_health) clamped_cnt = max_health;
        break;
    case BK_ITEM_AIR:
        clamped_cnt = count * 600;
        if(count > 6) clamped_cnt = 6*600;
        break;
    case BK_ITEM_EMPTY_HONEYCOMB:
        if(count > 5) clamped_cnt = 5;
        break; 
    case BK_ITEM_EGG:
        if( count > 100) bk_global_flag_set(BK_G_FLAG_DOUBLE_EGGS, 0x01);
        else bk_global_flag_set(BK_G_FLAG_DOUBLE_EGGS, 0x00);

        if( count > 200) clamped_cnt = 200;
        break;
    case BK_ITEM_GOLD_FEATHER:
        if( count > 10) bk_global_flag_set(BK_G_FLAG_DOUBLE_GOLD_FEATHERS, 0x01);
        else bk_global_flag_set(BK_G_FLAG_DOUBLE_GOLD_FEATHERS, 0x010);
        if( count > 20) clamped_cnt = 20;
        break;
    case BK_ITEM_RED_FEATHER:
        if( count > 50) bk_global_flag_set(BK_G_FLAG_DOUBLE_RED_FEATHERS, 0x01);
        else bk_global_flag_set(BK_G_FLAG_DOUBLE_RED_FEATHERS, 0x010);
        if( count > 100) clamped_cnt = 100;
        break;
    case BK_ITEM_JIGGY_LEVEL:
        if(count >10) clamped_cnt = 10;
        break;
    case BK_ITEM_JIGGY_TOTAL:
        if(count >100) clamped_cnt = 100;
        break;
    default:
        break;
    }
    (&bk_item_array)[item] = clamped_cnt;
}

static int item_count_update(event_handler_t *handler, menu_event_t event, void **event_data){
    uint32_t item_indx = handler->callback_data;
    if(event == MENU_EVENT_NUMBER){
        uint32_t value = (uint32_t)*event_data;
        item_set_count(item_indx,value);
        if(item_indx == BK_ITEM_AIR){
            uint32_t air_count = bk_item_get_count(item_indx);
            if (air_count % 600 == 0) air_count = air_count/600;
            else air_count = air_count/600 + 1;
            menu_number_set(handler->subscriber, air_count);
        }else{
            menu_number_set(handler->subscriber, bk_item_get_count(item_indx));
        }
        
        return 1;
    }
    else if (event == MENU_EVENT_UPDATE){
        if(item_indx == BK_ITEM_AIR){
            uint32_t air_count = bk_item_get_count(item_indx);
            if (air_count % 600 == 0) air_count = air_count/600;
            else air_count = air_count/600 + 1;
            menu_number_set(handler->subscriber, air_count);
        }else{
            menu_number_set(handler->subscriber, bk_item_get_count(item_indx));
        }
        return 1;
    }
    return 0;
}

static menu_t* create_level_items_menu(){
    menu_t *items_submenu = malloc(sizeof(*items_submenu));;
    menu_init(items_submenu,0,0);
    items_submenu->selected_item = menu_button_add(items_submenu,0,0,"return", menu_return, NULL);

    for (int i = 0; level_items_table[i].item_index != 0; i++)
    {
        menu_label_add(items_submenu,4,i+1,level_items_table[i].tooltip);
        menu_item_t* val_input = menu_number_input_add(items_submenu, 0, i+1, 10, 3);
        menu_number_set(val_input, bk_item_get_count(level_items_table[i].item_index));
        menu_item_register_event(val_input, MENU_EVENT_NUMBER | MENU_EVENT_UPDATE,item_count_update, level_items_table[i].item_index);
    }
    return items_submenu;
}

static menu_t* create_inventory_menu(){
    menu_t *items_menu = malloc(sizeof(*items_menu));;
    menu_init(items_menu,0,0);
    items_menu->selected_item = menu_button_add(items_menu,0,0,"return", menu_return, NULL);
    int end_count = 0;
    for (int i = 0; items_table[i].item_index != 0; i++)
    {
        menu_label_add(items_menu,4,i+1,items_table[i].tooltip);
        menu_item_t* val_input;
        if(items_table[i].item_index != BK_ITEM_AIR){
            val_input = menu_number_input_add(items_menu, 0, i+1, 10, 3);
        }else{
            val_input = menu_number_input_add(items_menu, 0, i+1, 16, 3);
        }
        menu_item_register_event(val_input, MENU_EVENT_NUMBER | MENU_EVENT_UPDATE,item_count_update, items_table[i].item_index);
        end_count = i+2;
    }
    menu_submenu_add(items_menu,0,end_count,"level specific items",create_level_items_menu());
    
    return items_menu;
}


/*JIGGIES*/
static int jiggy_callback(event_handler_t *handler, menu_event_t event, void *data){
    uint32_t jiggy_index = handler->callback_data;
    if(event == MENU_EVENT_ACTIVATE){
        bool has_jiggy = bk_jiggy_flag_get(jiggy_index);
        if(has_jiggy){
            bk_jiggy_flag_set(jiggy_index, 0);
        } else {
            bk_jiggy_flag_set(jiggy_index, 1);
        }
        return 1;
    } else if (event == MENU_EVENT_UPDATE) {
        menu_checkbox_set(handler->subscriber, bk_jiggy_flag_get(jiggy_index));
        return 1;
    }
    return 0;
}

static menu_t *create_jiggy_level_menu(uint32_t lvl){
    menu_t *jiggy_submenu = malloc(sizeof(*jiggy_submenu));;
    menu_init(jiggy_submenu,0,0);
    jiggy_submenu->selected_item = menu_button_add(jiggy_submenu, 0, 0, "return", menu_return, NULL);
    int y_pos = 1;
    for(int i = 0; jiggy_table[i].jiggy_index != 0; i++){
        if(jiggy_table[i].level == lvl){
            menu_item_t *checkbox =  menu_checkbox_add(jiggy_submenu,0,y_pos);
            menu_item_register_event(checkbox, MENU_EVENT_UPDATE | MENU_EVENT_ACTIVATE, jiggy_callback, jiggy_table[i].jiggy_index);
            menu_label_add(jiggy_submenu,2,y_pos,jiggy_table[i].tooltip);
            y_pos++;
        }
    }
    return jiggy_submenu;
}

static menu_t *create_jiggy_menu(){
    menu_t *jiggy_submenu = malloc(sizeof(*jiggy_submenu));;
    menu_init(jiggy_submenu,0,0);
    jiggy_submenu->selected_item = menu_button_add(jiggy_submenu, 0, 0, "return", menu_return, NULL);
    menu_submenu_add(jiggy_submenu, 0,  1, "mumbo's mountain",      create_jiggy_level_menu(1));
    menu_submenu_add(jiggy_submenu, 0,  2, "treasure trove cove",   create_jiggy_level_menu(2));
    menu_submenu_add(jiggy_submenu, 0,  3, "clanker's cavern",      create_jiggy_level_menu(3));
    menu_submenu_add(jiggy_submenu, 0,  4, "bubblegloop swamp",     create_jiggy_level_menu(4));
    menu_submenu_add(jiggy_submenu, 0,  5, "freezeezy peak",        create_jiggy_level_menu(5));
    menu_submenu_add(jiggy_submenu, 0,  6, "gobi's valley",         create_jiggy_level_menu(7));
    menu_submenu_add(jiggy_submenu, 0,  7, "mad monster mansion",   create_jiggy_level_menu(10));
    menu_submenu_add(jiggy_submenu, 0,  8, "rusty bucket bay",      create_jiggy_level_menu(9));
    menu_submenu_add(jiggy_submenu, 0,  9, "click clock wood",      create_jiggy_level_menu(8));
    menu_submenu_add(jiggy_submenu, 0, 10, "gruntilda's lair",      create_jiggy_level_menu(6));
    return jiggy_submenu;
}


/*MUMBO TOKENS*/
static int mumbo_token_callback(event_handler_t *handler, menu_event_t event, void *data){
    uint32_t mumbo_token_index = handler->callback_data;
    if(event == MENU_EVENT_ACTIVATE){
        bool has_mumbo_token = bk_mumbo_token_flag_get(mumbo_token_index);
        if(has_mumbo_token){
            bk_mumbo_token_flag_set(mumbo_token_index, 0);
        } else {
            bk_mumbo_token_flag_set(mumbo_token_index, 1);
        }
        return 1;
    } else if (event == MENU_EVENT_UPDATE) {
        menu_checkbox_set(handler->subscriber, bk_mumbo_token_flag_get(mumbo_token_index));
        return 1;
    }
    return 0;
}

static menu_t *create_mumbo_token_level_menu(uint32_t lvl){
    menu_t *mumbo_token_submenu = malloc(sizeof(*mumbo_token_submenu));;
    menu_init(mumbo_token_submenu,0,0);
    mumbo_token_submenu->selected_item = menu_button_add(mumbo_token_submenu, 0, 0, "return", menu_return, NULL);
    int y_pos = 1;
    for(int i = 0; mumbo_token_table[i].mt_index != 0; i++){
        if(mumbo_token_table[i].level == lvl){
            menu_item_t *checkbox =  menu_checkbox_add(mumbo_token_submenu,0,y_pos);
            menu_item_register_event(checkbox, MENU_EVENT_UPDATE | MENU_EVENT_ACTIVATE, mumbo_token_callback, mumbo_token_table[i].mt_index);
            menu_label_add(mumbo_token_submenu,2,y_pos,mumbo_token_table[i].tooltip);
            y_pos++;
        }
    }
    return mumbo_token_submenu;
}

static menu_t *create_mumbo_token_menu(){
    menu_t *mumbo_token_submenu = malloc(sizeof(*mumbo_token_submenu));;
    menu_init(mumbo_token_submenu,0,0);
    mumbo_token_submenu->selected_item = menu_button_add(mumbo_token_submenu, 0, 0, "return", menu_return, NULL);
    menu_submenu_add(mumbo_token_submenu, 0,  1, "mumbo's mountain",      create_mumbo_token_level_menu(1));
    menu_submenu_add(mumbo_token_submenu, 0,  2, "treasure trove cove",   create_mumbo_token_level_menu(2));
    menu_submenu_add(mumbo_token_submenu, 0,  3, "clanker's cavern",      create_mumbo_token_level_menu(3));
    menu_submenu_add(mumbo_token_submenu, 0,  4, "bubblegloop swamp",     create_mumbo_token_level_menu(4));
    menu_submenu_add(mumbo_token_submenu, 0,  5, "freezeezy peak",        create_mumbo_token_level_menu(5));
    menu_submenu_add(mumbo_token_submenu, 0,  6, "gobi's valley",         create_mumbo_token_level_menu(7));
    menu_submenu_add(mumbo_token_submenu, 0,  7, "mad monster mansion",   create_mumbo_token_level_menu(10));
    menu_submenu_add(mumbo_token_submenu, 0,  8, "rusty bucket bay",      create_mumbo_token_level_menu(9));
    menu_submenu_add(mumbo_token_submenu, 0,  9, "click clock wood",      create_mumbo_token_level_menu(8));
    menu_submenu_add(mumbo_token_submenu, 0, 10, "gruntilda's lair",      create_mumbo_token_level_menu(6));
    return mumbo_token_submenu;
}


/*EMPTY HONEYCOMBS*/
static int empty_honeycomb_callback(event_handler_t *handler, menu_event_t event, void *data){
    uint32_t honeycomb_index = handler->callback_data;
    if(event == MENU_EVENT_ACTIVATE){
        bool has_honeycomb = bk_empty_honeycomb_flag_get(honeycomb_index);
        if(has_honeycomb){
            bk_empty_honeycomb_flag_set(honeycomb_index, 0);
        } else {
            bk_empty_honeycomb_flag_set(honeycomb_index, 1);
        }
        return 1;
    } else if (event == MENU_EVENT_UPDATE) {
        menu_checkbox_set(handler->subscriber, bk_empty_honeycomb_flag_get(honeycomb_index));
        return 1;
    }
    return 0;
}

static menu_t *create_empty_honeycomb_level_menu(uint32_t lvl){
    menu_t *honeycomb_submenu = malloc(sizeof(*honeycomb_submenu));;
    menu_init(honeycomb_submenu,0,0);
    honeycomb_submenu->selected_item = menu_button_add(honeycomb_submenu, 0, 0, "return", menu_return, NULL);
    int y_pos = 1;
    for(int i = 0; empty_honeycomb_table[i].index != 0; i++){
        if(empty_honeycomb_table[i].level == lvl){
            menu_item_t *checkbox =  menu_checkbox_add(honeycomb_submenu,0,y_pos);
            menu_item_register_event(checkbox, MENU_EVENT_UPDATE | MENU_EVENT_ACTIVATE, empty_honeycomb_callback, empty_honeycomb_table[i].index);
            menu_label_add(honeycomb_submenu,2,y_pos,empty_honeycomb_table[i].tooltip);
            y_pos++;
        }
    }
    return honeycomb_submenu;
}

static menu_t *create_empty_honeycomb_menu(){
    menu_t *empty_honeycomb_submenu = malloc(sizeof(*empty_honeycomb_submenu));;
    menu_init(empty_honeycomb_submenu,0,0);
    empty_honeycomb_submenu->selected_item = menu_button_add(empty_honeycomb_submenu, 0, 0, "return", menu_return, NULL);
    menu_submenu_add(empty_honeycomb_submenu, 0,  1, "spiral mountain",       create_empty_honeycomb_level_menu(11));
    menu_submenu_add(empty_honeycomb_submenu, 0,  2, "mumbo's mountain",      create_empty_honeycomb_level_menu(1));
    menu_submenu_add(empty_honeycomb_submenu, 0,  3, "treasure trove cove",   create_empty_honeycomb_level_menu(2));
    menu_submenu_add(empty_honeycomb_submenu, 0,  4, "clanker's cavern",      create_empty_honeycomb_level_menu(3));
    menu_submenu_add(empty_honeycomb_submenu, 0,  5, "bubblegloop swamp",     create_empty_honeycomb_level_menu(4));
    menu_submenu_add(empty_honeycomb_submenu, 0,  6, "freezeezy peak",        create_empty_honeycomb_level_menu(5));
    menu_submenu_add(empty_honeycomb_submenu, 0,  7, "gobi's valley",         create_empty_honeycomb_level_menu(7));
    menu_submenu_add(empty_honeycomb_submenu, 0,  8, "mad monster mansion",   create_empty_honeycomb_level_menu(10));
    menu_submenu_add(empty_honeycomb_submenu, 0,  9, "rusty bucket bay",      create_empty_honeycomb_level_menu(9));
    menu_submenu_add(empty_honeycomb_submenu, 0, 10, "click clock wood",      create_empty_honeycomb_level_menu(8));
    return empty_honeycomb_submenu;
}
menu_t *create_items_menu(){
    menu_t *items_menu = malloc(sizeof(*items_menu));;
    menu_init(items_menu,0,0);
    items_menu->selected_item = menu_button_add(items_menu, 0, 0, "return", menu_return, NULL);
    menu_submenu_add( items_menu, 0, 1, "inventory", create_inventory_menu());
    menu_submenu_add( items_menu, 0, 2, "jiggies", create_jiggy_menu());
    //menu_submenu_add( items_menu, 0, 3, "note scores", create_note_scores_menu());
    menu_submenu_add( items_menu, 0, 4, "mumbo tokens", create_mumbo_token_menu());
    menu_submenu_add( items_menu, 0, 5, "empty honeycombs", create_empty_honeycomb_menu());
    //menu_submenu_add( items_menu, 0, 6, "in-game timers", create_ig_timers_menu());
    return items_menu;
}