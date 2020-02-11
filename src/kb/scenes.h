#ifndef _SCENES_H
#define _SCENES_H
#include <stdint.h>

typedef struct kb_scene_category       kb_scene_category_t;
typedef struct kb_entrance             kb_entrance_t;
typedef struct kb_scene                kb_scene_t;

struct kb_scene_category {
    char        *name;
    uint32_t    scene_cnt; //0 if subcategory
    uint32_t    subcategory_type; //0 if scene, 1 if category
    union {
        kb_scene_category_t    *categories;
        kb_scene_t             *scenes;
    };
};

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

#endif