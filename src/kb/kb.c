#include <startup.h>
#include <stdlib.h>
#include <libundermine/gfx.h>
#include <libundermine/menu.h>
#include <libundermine/input.h>
#include <libundermine/resource.h>
#include "kb.h"
#include "bk.h"
#include "commands.h"
#include "kbresource.h"

__attribute__((section(".data")))
kb_ctxt_t kb = {
    .ready = 0
};

void kb_main(void){
    gfx_begin();
    input_update();

    {
        int x = 16;
        int y = 200;
        gfx_printf(x, y, "%4i %4i", input_x(), input_y());
        gfx_texture *btn_tex = resource_get(resource_handles[R_KB_BUTTON]);
        static const int8_t btns[] = { 15, 14, 12, 13, 3, 2, 0, 1, 5, 4, 11, 10, 8, 9};
        uint16_t pad = input_pressed_raw();
        for(int i = 0;i < sizeof(btns) / sizeof(*btns);i++){
            int8_t btn = btns[i];
            if(!(pad & (1 << btn))){
                continue;
            }
            gfx_draw_sprite_color(btn_tex, x + 80 + (i * 10), y, btn, 8, 8, button_colors[btn]);
        }
    }

    void *event_data = NULL;
    if(kb.menu_active){
        menu_t *kb_menu = &kb.main_menu;
        if(input_bind_pressed_raw(KB_CMD_TOGGLE_MENU)){
            kb.menu_active = 1;
            free_buttons(BUTTON_L | BUTTON_D_DOWN | BUTTON_D_UP | BUTTON_D_LEFT | BUTTON_D_RIGHT);
        }else if(input_bind_pressed_raw(KB_CMD_RETURN)){
            menu_trigger_event(kb_menu, MENU_EVENT_RETURN, &event_data);
        }else{
            uint16_t pressed = input_pressed();
            if(pressed & BUTTON_D_DOWN){
                menu_trigger_event(kb_menu, MENU_EVENT_NAVIGATE, (void*)MENU_NAV_DOWN);
            }
            if(pressed & BUTTON_D_UP){
                menu_trigger_event(kb_menu, MENU_EVENT_NAVIGATE, (void*)MENU_NAV_UP);
            }
            if(pressed & BUTTON_D_LEFT){
                menu_trigger_event(kb_menu, MENU_EVENT_NAVIGATE, (void*)MENU_NAV_LEFT);
            }
            if(pressed & BUTTON_D_RIGHT){
                menu_trigger_event(kb_menu, MENU_EVENT_NAVIGATE, (void*)MENU_NAV_RIGHT);
            }
            if(pressed & BUTTON_L){
                menu_trigger_event(kb_menu, MENU_EVENT_ACTIVATE, &event_data);
            }
        }
        menu_trigger_event(kb_menu, MENU_EVENT_UPDATE, &event_data);
        menu_draw(kb_menu);
    }else if(input_bind_pressed_raw(KB_CMD_TOGGLE_MENU)){
        kb.menu_active = 1;
        reserve_buttons(BUTTON_L | BUTTON_D_DOWN | BUTTON_D_UP | BUTTON_D_LEFT | BUTTON_D_RIGHT);
    }
}

static int main_menu_on_activate(event_handler_t *handler, menu_event_t event, void **event_data){
    kb.menu_active = 0;
    return 1;
}

void init(void){
    clear_bss();
    do_global_ctors();

    input_init(&bk_controller_raw.pad, &bk_controller_raw.x, &bk_controller_raw.y, kb_binds, KB_CMD_MAX);
    bind_override(KB_CMD_TOGGLE_MENU);
    bind_override(KB_CMD_RETURN);

    kb_resource_init();
    gfx_init(0x32800, resource_get(resource_handles[R_KB_FONT]), NULL);

    list_init(&kb.watches, sizeof(watch_t));

    menu_t *main_menu = &kb.main_menu;
    menu_ctx_init(main_menu, NULL);
    menu_init(main_menu, 20, 30);

    main_menu->selected_item = menu_button_add(main_menu, 0, 0, "return", main_menu_on_activate, NULL);
    menu_submenu_add(main_menu, 0, 1, "watches", create_watches_menu());

    kb.menu_active = 0;
    kb.ready = 1;
    kb_binds[KB_CMD_TOGGLE_MENU] = make_bind(2, BUTTON_R, BUTTON_L);
    kb_binds[KB_CMD_RETURN] = make_bind(2, BUTTON_R, BUTTON_D_LEFT);
}

int _main(void){
    init_gp();
    if(!kb.ready){
        init();
    }
    int ret = game_update();
    kb_main();
    return ret;
}

void kb_overlay_append(Gfx **p_gfx_p, MtxF **p_mtx_p, void *a2){
    overlay_append(p_gfx_p, p_mtx_p, a2);
    gfx_finish_set(p_gfx_p);
    gfx_finish();
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

ENTRY void _start(){
    uint32_t kb_load_stage1_p = (uint32_t)&kb_load_stage1;
    kb_load_stage1_p = ((kb_load_stage1_p & 0xFFFFFF) >> 2) | 0xC000000;
    load_code_stage1_hook = kb_load_stage1_p;

    // Should probably clear inst cache here?

    // continue to loader
    __asm__ volatile("j 0x80400000;"
                    ::);
}