#include <stdlib.h>
#include <libundermine.h>
#include "kb.h"
#include "scenes.h"
#include "bk.h"

static int activate_warp_proc(event_handler_t *handler, menu_event_t event, void **data){
    if(event == MENU_EVENT_ACTIVATE){
        uint32_t exit = (uint32_t)handler->callback_data & 0xFF;
        uint32_t map = ((uint32_t)handler->callback_data >> 8) & 0xFF;
        bk_take_me_there(map,exit,1);

        //todo, add return?

        return 1;
    }
    return 0;
}

menu_t *create_warps_menu(){
    static menu_t warps;
    uint32_t data;
    menu_init(&warps,0,0);
    warps.selected_item = menu_button_add(&warps,0,0,"return",menu_return,NULL);
    for(int i = 0; i<sizeof(scene_categories)/sizeof(kb_scene_category_t); i++){
        kb_scene_category_t *cat = &scene_categories[i];
        if(cat->scene_cnt == 1 && cat->scenes->entrance_cnt == 1){
            data = (((uint32_t) cat->scenes->index) & 0xFF) << 8;
            data |= ((uint32_t)(cat->scenes->entrances->index)) && 0xFF;
            menu_button_add(&warps,0,i+1,cat->name, activate_warp_proc, (void *)data);
        } else {
            
            menu_t *cat_menu = malloc(sizeof(*cat_menu));
            menu_init(cat_menu,0,0);
            cat_menu->selected_item = menu_button_add(cat_menu,0,0,"return",menu_return,NULL);
            menu_submenu_add(&warps,0,i+1,cat->name,cat_menu);
            for(int j = 0; j<cat->scene_cnt; j++){ 
                kb_scene_t *scene = &((cat->scenes)[j]); 
                data = (((uint32_t) scene->index) & 0xFF) << 8;  
                if(scene->entrance_cnt == 1){
                    data |= ((uint32_t)(scene->entrances->index)) && 0xFF;
                    menu_button_add(cat_menu,0,j+1,scene->name, activate_warp_proc, (void *)data);
                } else {

                    menu_t *scene_menu = malloc(sizeof(*scene_menu));
                    menu_init(scene_menu,0,0);
                    scene_menu->selected_item = menu_button_add(scene_menu,0,0,"return",menu_return,NULL);
                    menu_submenu_add(cat_menu,0,j+1,scene->name,scene_menu);
                    for (int k = 0; k < scene->entrance_cnt; k++){
                        kb_entrance_t *ent = &((scene->entrances)[k]);     
                        menu_button_add(scene_menu,0,k+1,ent->name, activate_warp_proc, (void *)(data |((ent->index) & 0xFF)));
                    }
                }
            }
        }
    }
    return &warps;
}