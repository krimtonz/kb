#include <stddef.h>
#include <libundermine/input.h>
#include "commands.h"

struct command kb_commands[KB_CMD_MAX] = {
    { "toggle menu",    COMMAND_PRESS,  NULL },
    { "return",         COMMAND_PRESS,  NULL }
};

uint16_t kb_binds[KB_CMD_MAX] = { 0 };