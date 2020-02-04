#ifndef _SCENES_H
#define _SCENES_H
#include <stdint.h>

typedef struct kb_entrance  kb_entrance_t;
typedef struct kb_scene     kb_scene_t;

typedef struct kb_scene_category {
    char        *name;
    int          scene_cnt;
    kb_scene_t  *scenes;
} kb_scene_category_t;

struct kb_scene {
    char             *name;
    uint32_t           index;
    uint32_t           entrance_cnt;
    kb_entrance_t    *entrances;
};

struct kb_entrance {
    uint32_t     index;
    char       *name;
} ;

extern kb_scene_category_t    scene_categories[13];
extern kb_scene_category_t    CCW_categories[5];

#endif