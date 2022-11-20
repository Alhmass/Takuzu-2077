#include "game.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct game_s {
    square *init;
    square *game;
};

uint game_index(cgame g, uint i, uint j) { return DEFAULT_SIZE * i + j; }

void throw_error(char *msg) {
    fprintf(stderr, "[error] %s\n", msg);
    exit(EXIT_FAILURE);
}

game game_new(square *squares) {
    game g = malloc(sizeof(struct game_s));
    if (g == NULL)
        throw_error("malloc failed");
    g->init = malloc(sizeof(square) * DEFAULT_SIZE * DEFAULT_SIZE);
    if (g->init == NULL)
        throw_error("malloc failed");
    g->game = malloc(sizeof(square) * DEFAULT_SIZE * DEFAULT_SIZE);
    if (g->game == NULL)
        throw_error("malloc failed");
    memcpy(g->init, squares, sizeof(square) * DEFAULT_SIZE * DEFAULT_SIZE);
    memcpy(g->game, squares, sizeof(square) * DEFAULT_SIZE * DEFAULT_SIZE);
    return g;
}

game game_new_empty(void) { return game_new((square *)calloc(DEFAULT_SIZE * DEFAULT_SIZE, sizeof(square))); }

game game_copy(cgame g) {
    game copy = memcpy(malloc(sizeof(struct game_s)), g, sizeof(struct game_s));
    if (copy == NULL)
        throw_error("malloc failed");
    copy->init = memcpy(malloc(sizeof(square) * DEFAULT_SIZE * DEFAULT_SIZE), g->init,
                        sizeof(square) * DEFAULT_SIZE * DEFAULT_SIZE);
    if (copy->init == NULL)
        throw_error("malloc failed");
    copy->game = memcpy(malloc(sizeof(square) * DEFAULT_SIZE * DEFAULT_SIZE), g->game,
                        sizeof(square) * DEFAULT_SIZE * DEFAULT_SIZE);
    if (copy->game == NULL)
        throw_error("malloc failed");
    return copy;
}

bool game_equal(cgame g1, cgame g2) {
    if (g1 == NULL || g2 == NULL)
        return false;
    for (uint i = 0; i < DEFAULT_SIZE; i++) {
        for (uint j = 0; j < DEFAULT_SIZE; j++) {
            if (game_get_square(g1, i, j) != game_get_square(g2, i, j))
                return false;
        }
    }
    return true;
}

void game_delete(game g) {
    free(g->init);
    free(g->game);
    free(g);
}

void game_set_square(game g, uint i, uint j, square s) {
    if (i >= DEFAULT_SIZE || j >= DEFAULT_SIZE)
        return;
    g->game[game_index(g, i, j)] = s;
}

square game_get_square(cgame g, uint i, uint j) { return g->game[game_index(g, i, j)]; }

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
