#ifndef _START_H
#define _START_H

typedef struct {
    void   *ra;
    void   *sp;
    void   *exit_func;
} start_ctxt_t;

void _start();
void _kb_entry();
void *_kb_exit();

__attribute__ ((section(".data")))
extern start_ctxt_t _entry_data;

#endif