#include "kbresource.h"

static const char *resource_names[R_KB_END] = {
    "font",
    "buttons",
};

static resource_ctor resource_ctors[R_KB_END] = {
    grc_ctor,
    grc_ctor,
};

int resource_handles[R_KB_END] = { -1 };

void kb_resource_init(){
    for(int i = 0;i < R_KB_END;i++){
        resource_ent_t *res = resource_create(resource_names[i], resource_ctors[i], NULL);
        if(res){
            resource_handles[i] = res->resource_id;
        }
    }
}