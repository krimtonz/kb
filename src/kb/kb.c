#include <startup.h>
#include <stdlib.h>
#include "kb.h"
#include "bk.h"
#include "gfx.h"

Gfx **gfx_p = NULL;

__attribute__((section(".data")))
kb_ctxt_t kb = {
    .ready = 0
};

void kb_main(void){
    gfx_begin();
    gfx_printf(100, 100, "Hello");
    gfx_finish();
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
    gfx_p = a0;
    game_update(a0, a1, a2);
    kb_main();
    gfx_p = NULL;
}

void kb_load_stage2(void *a0, void *a1, void *a2){
    load_code_stage2(a0, a1, a2);

    uint32_t main_p = (uint32_t)&_main;
    main_p = ((main_p & 0xFFFFFF) >> 2) | 0xC000000;
    game_update_hook = main_p;
   
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