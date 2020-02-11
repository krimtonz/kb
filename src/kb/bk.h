#ifndef _BK_H
#define _BK_H

#include <stdint.h>
#include <libundermine.h>

typedef struct{
    union{
        struct{
            uint16_t    a   : 1;
            uint16_t    b   : 1;
            uint16_t    z   : 1;
            uint16_t    s   : 1;
            uint16_t    du  : 1;
            uint16_t    dd  : 1;
            uint16_t    dl  : 1;
            uint16_t    dr  : 1;
            uint16_t        : 2;
            uint16_t    l   : 1;
            uint16_t    r   : 1;
            uint16_t    cu  : 1;
            uint16_t    cd  : 1;
            uint16_t    cl  : 1;
            uint16_t    cr  : 1;
        };
        uint16_t pad;
    };
    int8_t x;
    int8_t y;
} bk_controller_t;

typedef enum moves{
    bk_moves_beakBarge = 0,
    bk_moves_beakBomb = 1,
    bk_moves_beakBuster = 2,
    bk_moves_cameraControls = 3,
    bk_moves_bearPunch = 4,
    bk_moves_climbTrees = 5,
    bk_moves_eggs = 6,
    bk_moves_featheryFlap = 7,
    bk_moves_flapFlip = 8,
    bk_moves_flying = 9,
    bk_moves_holdAToJumpHigher = 10,
    bk_moves_ratATatRap = 11,
    bk_moves_roll = 12,
    bk_moves_shockSpringJump = 13,
    bk_moves_wadingBoots = 14,
    bk_moves_dive = 15,
    bk_moves_talonTrot = 16,
    bk_moves_turboTalonTrainers = 17,
    bk_moves_wonderwing = 18,
    bk_moves_firstNoteDoorMolehill = 19,
} bk_moves_t;

#define bk_extern       extern __attribute__ ((section(".data")))

bk_extern   uint32_t        load_code_stage2_hook;
bk_extern   uint32_t        game_update_hook;
bk_extern   uint32_t        load_code_stage1_hook;
bk_extern   uint32_t        gfx_finish_hook;
bk_extern   int32_t         bk_vi_counter;
bk_extern   bk_controller_t bk_controller_raw;

bk_extern   int         game_update         (void);
bk_extern   void        load_code_stage2    (void);
bk_extern   void        load_code_stage1    (void);
bk_extern   void        bk_gfx_finish       (Gfx **p_gfx_p);
bk_extern   void        bk_take_me_there    (uint32_t map, uint32_t exit, uint32_t warp_type);

bk_extern   void        bk_moves_unlocked_set (uint32_t move_index, uint32_t boolean);
bk_extern   bool        bk_moves_unlocked_get (uint32_t move_index);
bk_extern   void        bk_moves_has_used_set (uint32_t move_index); //code clear method
bk_extern   bool        bk_moves_has_used_get (uint32_t move_index);

#endif
