#ifndef _KB_H
#define _KB_H

#include <list/list.h>
#include <libundermine.h>

typedef struct {
    _Bool       ready;
    menu_t      main_menu;
    int         menu_active;
    char       *tooltip;
    struct list watches;
} kb_ctxt_t;

extern kb_ctxt_t kb;

menu_t *create_warps_menu(void);
menu_t *create_watches_menu (void);
menu_t *create_moves_menu(void);
#endif
