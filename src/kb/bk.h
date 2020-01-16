#ifndef _BK_H
#define _BK_H

#define bk_extern       extern __attribute__ ((section(".data")))

bk_extern   uint32_t    load_code_stage2_hook;
bk_extern   uint32_t    game_update_hook;
bk_extern   uint32_t    load_code_stage1_hook;

bk_extern   void        game_update         (void*, void*, void*);
bk_extern   void        load_code_stage2    (void*, void*, void*);
bk_extern   void        load_code_stage1    (void *, void *, void*, void*);

#endif