#ifndef _MOVE_H_
#define _MOVE_H_

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "game.h"

struct move_s {
    uint row;
    uint col;
    square s;
};

typedef struct move_s *move;

move move_create(uint row, uint col, square s);
void move_delete(move m);
void move_print(move m);

#endif /* _MOVE_H_ */