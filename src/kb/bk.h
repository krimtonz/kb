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

typedef enum bK_item{
    BK_ITEM_SKULL_HOURGLASS        = 0x1,
    BK_ITEM_PROPELLOR_TIMER        = 0x3,
    BK_ITEM_CHRISTMAS_TREE_TIMER   = 0x5, //crashes game
    BK_ITEM_HOURGLASS              = 0x6,
    BK_ITEM_MUSIC_NOTE             = 0xC,
    BK_ITEM_EGG                    = 0xD,
    BK_ITEM_JIGGY_LEVEL            = 0xE,
    BK_ITEM_RED_FEATHER            = 0xF,
    BK_ITEM_GOLD_FEATHER           = 0x10,
    BK_ITEM_JINJO                  = 0x12,
    BK_ITEM_EMPTY_HONEYCOMB        = 0x13,
    BK_ITEM_HEALTH                 = 0x14,
    BK_ITEM_HEALTH_MAX             = 0x15,
    BK_ITEM_LIFE                   = 0x16,
    BK_ITEM_AIR                    = 0x17,
    BK_ITEM_BLUBBERS_GOLD          = 0x18,
    BK_ITEM_CHIMPYS_ORANGE         = 0x19,
    BK_ITEM_VILE_SCORE_PLAYER      = 0x1A,
    BK_ITEM_VILE_SCORE_VILE        = 0x1B,
    BK_ITEM_MUMBO_TOKEN_UNUSED     = 0x1C,
    BK_ITEM_GRUMBLIE               = 0x1D,
    BK_ITEM_YUMBLIE                = 0x1E,
    BK_ITEM_PRESENT_GREEN          = 0x1F,
    BK_ITEM_PRESENT_BLUE           = 0x20,
    BK_ITEM_PRESENT_RED            = 0x21,
    BK_ITEM_CATEPILLAR             = 0x22,
    BK_ITEM_ACORN                  = 0x23,
    BK_ITEM_TWINKLIE               = 0x24,
    BK_ITEM_MUMBO_TOKEN_TOTAL      = 0x25,
    BK_ITEM_JIGGY_TOTAL            = 0x26,
    BK_ITEM_JOKER_CARD             = 0x27,
}bk_item_t;

typedef enum bk_global_flag{
    BK_G_FLAG_DOUBLE_HEALTH          = 0xB9,

    BK_G_FLAG_DOUBLE_EGGS            = 0xBE,
    BK_G_FLAG_DOUBLE_RED_FEATHERS    = 0xBF,
    BK_G_FLAG_DOUBLE_GOLD_FEATHERS   = 0xC0,
} bk_global_flag_t;

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

bk_extern   uint32_t    bk_item_get_count   (uint32_t item_index);
bk_extern   uint32_t    bk_item_array;

bk_extern   bool        bk_global_flag_get  (uint32_t g_flag_indx);
bk_extern   void        bk_global_flag_set  (uint32_t g_flag_indx, bool val);

bk_extern   bool        bk_jiggy_flag_get   (uint32_t jiggy_index);
bk_extern   void        bk_jiggy_flag_set   (uint32_t jiggy_index, bool val);

bk_extern   bool        bk_mumbo_token_flag_get   (uint32_t mt_index);
bk_extern   void        bk_mumbo_token_flag_set   (uint32_t mt_index, bool val);
#endif
