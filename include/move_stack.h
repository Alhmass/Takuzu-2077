#ifndef _MOVE_STACK_H_
#define _MOVE_STACK_H_

#include "move.h"

struct move_stack_s {
    move *data;
    uint size;
    uint capacity;
};

typedef struct move_stack_s *moves;

moves ms_create(uint capacity);
void ms_delete(moves stack);
moves ms_double_capacity(moves stack);

move ms_top(moves stack);
moves ms_push(moves stack, move m);
moves ms_pop(moves stack);
moves ms_clear(moves stack);

bool ms_is_empty(moves stack);
bool ms_is_full(moves stack);

#endif /* _MOVE_STACK_H_ */