/*
* resource.h
*
* definitions for loading graphic resources
*/

#ifndef _KZRESOURCE_H
#define _KZRESOURCE_H
#include <libundermine/gfx.h>
#include <libundermine/menu.h>
#include <libundermine/resource.h>

enum resource {
    R_KB_FONT,
    R_KB_BUTTON,
    R_KB_END
};

void            kb_resource_init    (void);

extern int resource_handles[R_KB_END];

#endif