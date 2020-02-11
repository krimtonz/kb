#include <stdlib.h>
#include <libundermine.h>
#include "kb.h"
#include "bk.h"

static int set_transformation_proc(event_handler_t *handler, menu_event_t event, void **data){
    uint32_t transformation = (uint32_t)handler->callback_data & 0xFF;
    bk_transformation_set(transformation);
    bk_player_model_update();
    uint32_t idle = bk_idle_movement_index_get();
    bk_player_movement_state_set(idle);
    //todo: force control if washing machine

    return 1;
}

menu_t *create_transformations_menu(){
    menu_t *trans_menu = malloc(sizeof(*trans_menu));
    menu_init(trans_menu,0,0);
    trans_menu->selected_item = menu_button_add(trans_menu,0,0,"return",menu_return,NULL);
    menu_button_add(trans_menu, 0, 1, "banjo", set_transformation_proc, (void*)BK_TRANS_BANJO);
    menu_button_add(trans_menu, 0, 2, "termite", set_transformation_proc, (void*)BK_TRANS_TERMITE);
    menu_button_add(trans_menu, 0, 3, "crocodile", set_transformation_proc, (void*)BK_TRANS_CROC);
    menu_button_add(trans_menu, 0, 4, "walrus", set_transformation_proc, (void*)BK_TRANS_WALRUS);
    menu_button_add(trans_menu, 0, 5, "pumpkin", set_transformation_proc, (void*)BK_TRANS_PUMPKIN);
    menu_button_add(trans_menu, 0, 6, "bee", set_transformation_proc, (void*)BK_TRANS_BEE);
    menu_button_add(trans_menu, 0, 7, "washing machine", set_transformation_proc, (void*)BK_TRANS_WISHYWASHY);
    return trans_menu;
}