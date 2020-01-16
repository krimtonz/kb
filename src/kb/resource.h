/*
* resource.h
*
* definitions for loading graphic resources
*/

#ifndef _RESOURCE_H
#define _RESOURCE_H
#include "gfx.h"

enum resource {
    R_KB_FONT,
    R_END
};

void           *resource_get        (enum resource resource);

#endif