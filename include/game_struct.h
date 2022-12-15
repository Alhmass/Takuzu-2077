#ifndef __GAME_STRUCT_H__
#define __GAME_STRUCT_H__

#include "game.h"
#include "move.h"
#include "move_stack.h"

struct game_s {
    square *game;
};

struct game_ext_s {
    game *g;
    uint nb_rows;
    uint nb_cols;
    bool wrapping;
    bool unique;
    moves *history;
    moves *backup;
};

#endif // __GAME_STRUCT_H__