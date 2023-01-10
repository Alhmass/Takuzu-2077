#ifndef _MOVE_H_
#define _MOVE_H_

#include "game.h"

struct move_s {
    uint row;
    uint col;
    square s;
    square p;
};

typedef struct move_s *move;

uint move_row(move m);
uint move_col(move m);
square move_s(move m);
square move_p(move m);

move move_create(uint row, uint col, square s, square p);
void move_delete(move m);
void move_print(move m);

#endif /* _MOVE_H_ */