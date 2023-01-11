#ifndef _MOVE_STACK_H_
#define _MOVE_STACK_H_

#include "game.h"
#include "move.h"

struct move_stack_s {
    move *data;
    uint size;
    uint capacity;
};

typedef struct move_stack_s *ms;

ms ms_create(uint capacity);
void ms_delete(ms stack);
void ms_double_capacity(ms stack);

move ms_top(ms stack);
void ms_push(ms stack, move m);
void ms_pop(ms stack);
void ms_clear(ms stack);

int ms_top_row(ms stack);
int ms_top_col(ms stack);
int ms_top_s(ms stack);
int ms_top_p(ms stack);

bool ms_is_empty(ms stack);
bool ms_is_full(ms stack);

void ms_print(ms stack);

#endif /* _MOVE_STACK_H_ */