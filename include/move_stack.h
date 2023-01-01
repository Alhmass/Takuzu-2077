#ifndef _MOVE_STACK_H_
#define _MOVE_STACK_H_

#include "move.h"

struct move_stack_s {
    move *data;
    uint size;
    uint capacity;
};

typedef struct move_stack_s *ms;

ms ms_create(uint capacity);
void ms_delete(ms stack);

move ms_top(ms stack);
ms ms_push(ms stack, move m);
ms ms_pop(ms stack);
ms ms_clear(ms stack);

bool ms_is_empty(ms stack);
bool ms_is_full(ms stack);

#endif /* _MOVE_STACK_H_ */