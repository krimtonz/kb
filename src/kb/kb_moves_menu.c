#include <stdlib.h>
#include <libundermine.h>
#include "kb.h"
#include "bk.h"

struct moves_data {
    uint32_t   moves_indx;
    char       *tooltip;
};

static struct moves_data moves_table[]={
    { bk_moves_beakBarge, "beak barge"}, 
    { bk_moves_beakBomb, "beak bomb"},
    { bk_moves_beakBuster, "beak buster"},
    { bk_moves_cameraControls, "camera controls"},
    { bk_moves_bearPunch, "bear punch"},
    { bk_moves_climbTrees, "climb trees"},
    { bk_moves_eggs, "eggs"},
    { bk_moves_featheryFlap,"feathery flap"},
    { bk_moves_flapFlip, "flap flip"},
    { bk_moves_flying, "flying"},
    { bk_moves_holdAToJumpHigher, "variable jump height"},
    { bk_moves_ratATatRap, "rat-a-tat rap"},
    { bk_moves_roll, "roll"},
    { bk_moves_shockSpringJump, "shock spring jump"},
    { bk_moves_wadingBoots, "wading boots"},
    { bk_moves_dive, "dive" },
    { bk_moves_talonTrot, "talon trot"},
    { bk_moves_turboTalonTrainers, "turbo talon trainers"},
    { bk_moves_wonderwing, "wonderwing"},
    { bk_moves_firstNoteDoorMolehill, "1st note door molehill"}, //move to other flags?
};


static int has_move_callback(event_handler_t *handler, menu_event_t callback, void *data){
    uint32_t moves_index = (uint32_t)handler->callback_data & 0xFF;
    if(callback == MENU_EVENT_ACTIVATE){   
        bool is_unlocked =  bk_moves_unlocked_get_bit(moves_index);
        if(is_unlocked){
            bk_moves_unlocked_set_bit(moves_index, 0);
        } else {
            bk_moves_unlocked_set_bit(moves_index, 1);
        }
        bk_moves_has_used_set(bk_moves_unlocked_get());
        return 1;
    } else if(callback == MENU_EVENT_UPDATE) {
        menu_checkbox_set(handler->subscriber,bk_moves_unlocked_get_bit(moves_index));
        return 1;
    }
    return 0;
}

menu_t *create_moves_menu(){
    static menu_t moves_menu;
    uint32_t data;
    menu_init(&moves_menu, 0, 0);
    moves_menu.selected_item = menu_button_add(&moves_menu, 0, 0, "return", menu_return, NULL);
    
    for (int i = 0; i < sizeof(moves_table)/sizeof(struct moves_data); i++)
    {   //add visual elements
        menu_item_t* unlock_move_item = menu_checkbox_add(&moves_menu,0,i+1);
        menu_label_add(&moves_menu, 1,i+1,moves_table[i].tooltip);
        
        //set callback process
        menu_item_register_event(unlock_move_item,MENU_EVENT_ACTIVATE | MENU_EVENT_UPDATE, has_move_callback, (void*)moves_table[i].moves_indx);
    }


    


    return &moves_menu;
}