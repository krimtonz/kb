#ifndef _BK_H
#define _BK_H

#include <stdint.h>
#include <libundermine/gu.h>

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

#define bk_extern       extern __attribute__ ((section(".data")))

bk_extern   uint32_t        load_code_stage2_hook;
bk_extern   uint32_t        game_update_hook;
bk_extern   uint32_t        load_code_stage1_hook;
bk_extern   uint32_t        overlay_append_hook;
bk_extern   int32_t         bk_vi_counter;
bk_extern   bk_controller_t bk_controller_raw;

bk_extern   int         game_update         (void);
bk_extern   void        load_code_stage2    (void*, void*, void*);
bk_extern   void        load_code_stage1    (void *, void *, void*, void*);
bk_extern   void        overlay_append      (Gfx **p_gfx_p, MtxF **p_mtx_p, void*);
#endif