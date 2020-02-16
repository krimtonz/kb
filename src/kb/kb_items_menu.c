#include <stdlib.h>
#include <libundermine.h>
#include "kb.h"
#include "bk.h"

static struct items_data {
    uint32_t    item_index;
    char       *tooltip;
};

static struct items_data items_table[]={
    { BK_ITEM_MUSIC_NOTE        , "music notes"},
    { BK_ITEM_EGG               , "eggs"},
    { BK_ITEM_JIGGY_LEVEL       , "jiggies"},
    { BK_ITEM_RED_FEATHER       , "red feathers"},
    { BK_ITEM_GOLD_FEATHER      , "gold feathers"},
    //{ BK_ITEM_JINJO                  = 0x12, ""}, //handle differently
    { BK_ITEM_EMPTY_HONEYCOMB   , "empty honeycomb"},
    { BK_ITEM_HEALTH            , "health"},
    { BK_ITEM_HEALTH_MAX        , "health (total)"},
    { BK_ITEM_LIFE              , "lives"},
    { BK_ITEM_AIR               , "air"},
    { BK_ITEM_MUMBO_TOKEN_UNUSED, "mumbo tokens"},
    { BK_ITEM_MUMBO_TOKEN_TOTAL , "mumbo tokens (total)"},
    { BK_ITEM_JIGGY_TOTAL       , "jiggies (total)"},
    { 0, NULL},
};

static struct items_data level_items_table[]={
    { BK_ITEM_BLUBBERS_GOLD     , "blubber's gold"},
    { BK_ITEM_CHIMPYS_ORANGE    , "chimpy's orange"},
    //{ BK_ITEM_VILE_SCORE_PLAYER , "player's vile score"},
    //{ BK_ITEM_VILE_SCORE_VILE   , "vile's vile score"},
    //{ BK_ITEM_GRUMBLIE          , "grumblie"},
    //{ BK_ITEM_YUMBLIE           , "yumblie"},
    { BK_ITEM_PRESENT_GREEN     , "present (green)"},
    { BK_ITEM_PRESENT_BLUE      , "present (blue)"},
    { BK_ITEM_PRESENT_RED       , "present (red)"},
    { BK_ITEM_CATEPILLAR        , "caterpillars"},
    { BK_ITEM_ACORN             , "acorns"},
    //{ BK_ITEM_TWINKLIE          , "twinklie score"},
    { BK_ITEM_JOKER_CARD        , "joker cards"},
    { 0, NULL},
};

static struct items_data timer_items_table[]={
    { BK_ITEM_SKULL_HOURGLASS   , "skull hourglass"},
    { BK_ITEM_PROPELLOR_TIMER   , "propellor timer"},
    //{ BK_ITEM_CHRISTMAS_TREE_TIMER   = 0x5, ""}, //crashes game
    { BK_ITEM_HOURGLASS         , "hourglass"},
    { 0, NULL},
};


static void item_set_count(bk_item_t item, uint32_t count){
    uint32_t clamped_cnt = count;
    uint32_t max_health = 0; 
    switch (item)
    {
    case BK_ITEM_HEALTH_MAX:
        if(count > 8) {
            bk_global_flag_set(BK_G_FLAG_DOUBLE_HEALTH,0x01);
            clamped_cnt = 16;
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
        if( count > 200) clamped_cnt = 200;
        break;
    case BK_ITEM_GOLD_FEATHER:
        if( count > 10) bk_global_flag_set(BK_G_FLAG_DOUBLE_GOLD_FEATHERS, 0x01);
        if( count > 20) clamped_cnt = 20;
        break;
    case BK_ITEM_RED_FEATHER:
        if( count > 50) bk_global_flag_set(BK_G_FLAG_DOUBLE_RED_FEATHERS, 0x01);
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

menu_t* create_level_items_menu(){
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

menu_t* create_items_menu(){
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