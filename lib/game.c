#include <stddef.h>
#include "game.h"

struct game_s {
    int **init;
    int **tab;
};

game game_new(square* squares) {
    return NULL;
}

game game_new_empty(void) { return NULL; }

game game_copy(cgame g) { return NULL; }

bool game_equal(cgame g1, cgame g2) { return false; }

void game_delete(game g) { return; }

void game_set_square(game g, uint i, uint j, square s) { return; }

square game_get_square(cgame g, uint i, uint j) { return 0; }

int game_get_number(cgame g, uint i, uint j) { return 0; }

int game_get_next_square(cgame g, uint i, uint j, direction dir, uint dist) { return 0; }

int game_get_next_number(cgame g, uint i, uint j, direction dir, uint dist) { return 0; }

bool game_is_empty(cgame g, uint i, uint j) { return false; }

bool game_is_immutable(cgame g, uint i, uint j) { return false; }

int game_has_error(cgame g, uint i, uint j) { return 0; }

bool game_check_move(cgame g, uint i, uint j, square s) { return false; }

void game_play_move(game g, uint i, uint j, square s) { return; }

bool game_is_over(cgame g) { return false; }

void game_restart(game g) { return; }
