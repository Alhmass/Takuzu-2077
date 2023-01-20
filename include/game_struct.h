#ifndef __GAME_STRUCT_H__
#define __GAME_STRUCT_H__

#include "game.h"
#include "move.h"
#include "move_stack.h"

/**
 * @brief Structure of a game.
 * @details This structure contains all the properties of a game.
 * @see game
 **/
struct game_s {
    square *game;
    uint nb_rows;
    uint nb_cols;
    bool wrapping;
    bool unique;
    ms history;
    ms backup;
    uint version;
};

#endif  // __GAME_STRUCT_H__
