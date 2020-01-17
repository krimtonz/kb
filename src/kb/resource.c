#include <grc.h>
#include <stdlib.h>
#include "resource.h"

static const char *resource_names[R_END] = {
    "font",
    "icons",
    "buttons",
};

static void *resource_load_kb_texture(enum resource resource){
    if(resource_names[resource]){
        gfx_texture *kbtext = malloc(sizeof(*kbtext));
        if(!kbtext){
            return kbtext;
        }
        memset(kbtext, 0, sizeof(*kbtext));
        void *grctexture;
        if(!grc_resource_get(resource_names[resource], &grctexture, NULL)){
            return kbtext;
        }
        struct grc_texture *gtext = grctexture;
        kbtext->data = gtext->texture_data;
        kbtext->img_fmt = gtext->im_fmt;
        kbtext->img_size = gtext->im_siz;
        kbtext->tile_width = gtext->tile_width;
        kbtext->tile_height = gtext->tile_height;
        kbtext->x_tiles = gtext->tiles_x;
        kbtext->y_tiles = gtext->tiles_y;
        kbtext->tile_size = (kbtext->tile_width * kbtext->tile_height * G_SIZ_BITS(kbtext->img_size) + 63) / 64 * 8;
        return kbtext;
    }
    return NULL;
}

static void *resource_table[R_END] = { NULL };
static void *(*resource_ctors[R_END])(enum resource) = {
    resource_load_kb_texture,
    resource_load_kb_texture,
    resource_load_kb_texture,
};

void *resource_get(enum resource resource){
    if(!resource_table[resource]){
        if(resource_ctors[resource]){
            resource_table[resource] = resource_ctors[resource](resource);
        }
    }
    return resource_table[resource];
}

#include <grc.c>