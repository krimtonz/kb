#include <startup.h>
#include <stdlib.h>
#include "kb.h"
#include "bk.h"
#include "gfx.h"

__attribute__((section(".data")))
kb_ctxt_t kb = {
    .ready = 0
};

void kb_main(void){
    gfx_begin();
    int x = 0;
    int y = 200;
    gfx_printf(x, y, "%4i %4i", bk_controller_raw.x, bk_controller_raw.y);
    static const int8_t btns[] = { 15, 14, 12, 13, 3, 2, 0, 1, 5, 4, 11, 10, 8, 9};
    static const char *s_btns[] = {"a", "b", "s", "z", "cu", "cd", "cr", "cl", "l", "r", "du", "dd", "dr", "dl"};
    uint16_t pad = bk_controller_raw.pad;
    for(int i = 0;i < sizeof(btns) / sizeof(*btns);i++){
        const int8_t btn = btns[i];
        if(!(pad & (1 << btn))){
            continue;
        }
        gfx_printf(x + 80 + (i * 10), y, "%s", s_btns[i]);
        //gfx_draw_sprite_color(btn_tex, x + 80 + (i * 10), y, btn, 8, 8, button_colors[btn]);
    }
}

void init(void){
    gfx_init();
    kb.ready = 1;
}

void _main(Gfx **a0, void *a1, void *a2){
    init_gp();
    if(!kb.ready){
        init();
    }
    game_update(a0, a1, a2);
    kb_main();
}

void kb_overlay_append(Gfx **p_gfx_p, MtxF **p_mtx_p, void *a2){
    overlay_append(p_gfx_p, p_mtx_p, a2);
    gfx_finish(p_gfx_p);
}

void kb_load_stage2(void *a0, void *a1, void *a2){
    load_code_stage2(a0, a1, a2);

    uint32_t main_p = (uint32_t)&_main;
    main_p = ((main_p & 0xFFFFFF) >> 2) | 0xC000000;
    game_update_hook = main_p;

    uint32_t overlay_p = (uint32_t)&kb_overlay_append;
    overlay_p = ((overlay_p & 0xFFFFFF) >> 2 ) | 0xC000000;
    overlay_append_hook = overlay_p;
   
    // Should probably clear inst cache here? 
}

void kb_load_stage1(void *a0, void *a1, void *a2, void *a3){
    load_code_stage1(a0, a1, a2, a3);

    uint32_t kb_load_stage2_p = (uint32_t)&kb_load_stage2;
    kb_load_stage2_p = ((kb_load_stage2_p & 0xFFFFFF) >> 2) | 0xC000000;
    load_code_stage2_hook = kb_load_stage2_p;

    // should probably clear inst cache here.
}

ENTRY _Noreturn void _start(){
    uint32_t kb_load_stage1_p = (uint32_t)&kb_load_stage1;
    kb_load_stage1_p = ((kb_load_stage1_p & 0xFFFFFF) >> 2) | 0xC000000;
    load_code_stage1_hook = kb_load_stage1_p;
    
    // Should probably clear inst cache here?

    // continue to loader
    __asm__ volatile("j 0x80400000;"
                    ::);

    // Tell gcc that were never coming back here.
    for(;;);
}

#include <startup.c>