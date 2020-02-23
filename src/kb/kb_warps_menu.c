#include <stdlib.h>
#include <libundermine.h>
#include "kb.h"
#include "scenes.h"
#include "bk.h"

static int activate_warp_proc(event_handler_t *handler, menu_event_t event, void **data){
    uint32_t exit = (uint32_t)handler->callback_data & 0xFF;
    uint32_t map = ((uint32_t)handler->callback_data >> 8) & 0xFF;
    bk_take_me_there(map, exit, 1);

    //todo, add return?

    return 1;
}

static menu_t *create_entrance_submenu(kb_scene_t * scene, uint32_t data){
    menu_t *ent_menu = malloc(sizeof(*ent_menu));
    menu_init(ent_menu, 0, 0);
    ent_menu->selected_item = menu_button_add(ent_menu, 0, 0, "return",  menu_return, NULL);
    for (int i = 0; i < scene->entrance_cnt; i++){
        kb_entrance_t *ent = &((scene->entrances)[i]);
        menu_button_add(ent_menu, 0, i+1, ent->name, activate_warp_proc, (void *)(data | ((ent->index) & 0xFF)));
    }
    return ent_menu;
}

static menu_t *create_scene_submenu(kb_scene_category_t * cat){
    menu_t *scene_menu = malloc(sizeof(*scene_menu));
    menu_init(scene_menu, 0, 0);
    scene_menu->selected_item = menu_button_add(scene_menu, 0, 0, "return",  menu_return, NULL);
    for (int i = 0; i < cat->scene_cnt; i++){
        kb_scene_t *scene = &((cat->scenes)[i]);
        uint32_t data = (((uint32_t)scene->index) & 0xFF) << 8;
        if(scene->entrance_cnt == 1){
            menu_button_add(scene_menu, 0, i+1, scene->name, activate_warp_proc, (void *)(data | ((scene->entrances->index) & 0xFF)));
        } else {
            menu_t *ent_menu = create_entrance_submenu(scene, data);
            menu_submenu_add(scene_menu, 0, i+1, scene->name, ent_menu);
        }
    }
    return scene_menu;
}

static menu_t *create_warps_submenu(kb_scene_category_t * scene_categories, int size){
    menu_t *warps_submenu = malloc(sizeof(*warps_submenu));
    uint32_t data;
    menu_init(warps_submenu, 0, 0);
    warps_submenu->selected_item = menu_button_add(warps_submenu, 0, 0, "return", menu_return, NULL);
    for(int i = 0; i<size; i++){
        kb_scene_category_t *cat = &scene_categories[i];
        if(cat->subcategory_type == 1){
            menu_t* cat_menu = create_warps_submenu(cat->categories, cat->scene_cnt);
            menu_submenu_add(warps_submenu, 0, i+1, cat->name, cat_menu);
        } else {
            if (cat->scene_cnt == 1){
                data = (((uint32_t)cat->scenes->index) & 0xFF) << 8;
                if(cat->scenes->entrance_cnt == 1){
                    data |= ((uint32_t)(cat->scenes->entrances->index)) && 0xFF;
                    menu_button_add(warps_submenu, 0, i+1, cat->name, activate_warp_proc, (void *)data);
                } else {
                    menu_t *ent_menu = create_entrance_submenu(cat->scenes, data);
                    menu_submenu_add(warps_submenu, 0, i+1, cat->name, ent_menu);
                }
            } else {
                menu_t *scene_menu = create_scene_submenu(cat);
                menu_submenu_add(warps_submenu, 0, i+1, cat->name, scene_menu);
            }
        }
    }
    return warps_submenu;
}

menu_t *create_warps_menu(){
    return create_warps_submenu(scene_categories, sizeof(scene_categories)/sizeof(kb_scene_category_t));
}