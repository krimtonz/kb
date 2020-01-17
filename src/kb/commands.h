/*
* commands.h
*
* definitions for kz commands
*/

#ifndef _COMMANDS_H
#define _COMMANDS_H

#include <stdint.h>

enum {
    KB_CMD_TOGGLE_MENU,
    KB_CMD_RETURN,
    KB_CMD_MAX
};

enum command_type {
    COMMAND_HOLD,
    COMMAND_PRESS
};

struct command {
    char               *text;
    enum command_type   type;
    void              (*proc)();
};

void    command_return          (void);

extern struct command kb_commands[KB_CMD_MAX];
extern uint16_t kb_binds[KB_CMD_MAX];
#endif