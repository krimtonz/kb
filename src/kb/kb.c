#include <startup.h>
#include <stdlib.h>
#include <libundermine.h>
#include "kb.h"
#include "bk.h"
#include "commands.h"
#include "kbresource.h"
#include "start.h"

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
    
    menu_submenu_add(main_menu, 0, 1, "warps", create_warps_menu());
    menu_submenu_add(main_menu, 0, 2, "watches", create_watches_menu());
    menu_submenu_add(main_menu, 0, 4, "moves", create_moves_menu());

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
    _entry_data.exit_func = game_update;
    int ret = (int)_kb_exit();
    kb_main();
    return ret;
}

void kb_gfx_append(Gfx **p_gfx_p){
    gfx_finish_set(p_gfx_p);
    gfx_finish();
    bk_gfx_finish(p_gfx_p);
}

void kb_load_stage2(void){
    load_code_stage2();

    uint32_t main_p = (uint32_t)&_kb_entry;
    main_p = ((main_p & 0xFFFFFF) >> 2) | 0xC000000;
    game_update_hook = main_p;

    uint32_t overlay_p = (uint32_t)&kb_gfx_append;
    overlay_p = ((overlay_p & 0xFFFFFF) >> 2 ) | 0xC000000;
    gfx_finish_hook = overlay_p;

    osInvalICache((void*)&game_update_hook, 4);
    osInvalICache((void*)&gfx_finish_hook, 4);
}

void kb_load_stage1(void){
    load_code_stage1();

    uint32_t kb_load_stage2_p = (uint32_t)&kb_load_stage2;
    kb_load_stage2_p = ((kb_load_stage2_p & 0xFFFFFF) >> 2) | 0xC000000;
    load_code_stage2_hook = kb_load_stage2_p;

    osInvalICache((void*)&load_code_stage2_hook, 4);
}