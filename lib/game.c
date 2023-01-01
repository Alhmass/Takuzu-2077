#include "game.h"

#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "game_ext.h"
#include "game_struct.h"
#include "move.h"
#include "move_stack.h"

static void throw_error(char *msg) {
    fprintf(stderr, "[error] %s\n", msg);
    exit(EXIT_FAILURE);
}
static void test_pointer(void *p, char *msg) {
    if (p == NULL)
        throw_error(msg);
}
static void cgame_test(cgame g, char *msg) {
    if (g == NULL)
        throw_error(msg);
}

game game_new(square *squares) {
    game g = malloc(sizeof(struct game_s));
    test_pointer(g, "malloc failed");
    g->game = malloc(sizeof(square) * game_nb_rows(g) * game_nb_cols(g));
    test_pointer(g->game, "malloc failed");
    memcpy(g->game, squares, sizeof(square) * game_nb_rows(g) * game_nb_cols(g));
    return g;
}

game game_new_empty(void) {
    square *squares = (square *)calloc(DEFAULT_SIZE * DEFAULT_SIZE, sizeof(square));
    test_pointer(squares, "malloc failed");
    game g = game_new(squares);
    cgame_test(g, "malloc failed");
    free(squares);
    return g;
}

game game_copy(cgame g) {
    game copy = memcpy(malloc(sizeof(struct game_s)), g, sizeof(struct game_s));
    cgame_test(copy, "malloc failed");
    copy->game = memcpy(malloc(sizeof(square) * game_nb_rows(g) * game_nb_cols(g)), g->game,
                        sizeof(square) * game_nb_rows(g) * game_nb_cols(g));
    test_pointer(copy->game, "malloc failed");
    return copy;
}

bool game_equal(cgame g1, cgame g2) {
    if (g1 == NULL || g2 == NULL || g1->game == NULL || g2->game == NULL)
        return false;
    if (game_nb_rows(g1) != game_nb_rows(g2) || game_nb_cols(g1) != game_nb_cols(g2))
        return false;
    for (uint i = 0; i < game_nb_rows(g1); i++) {
        for (uint j = 0; j < game_nb_cols(g1); j++) {
            if (game_get_square(g1, i, j) != game_get_square(g2, i, j))
                return false;
        }
    }
    return true;
}

void game_delete(game g) {
    if (g == NULL)
        return;
    if (g->game != NULL)
        free(g->game);
    free(g);
}

void game_set_square(game g, uint i, uint j, square s) {
    if (i >= game_nb_rows(g) || j >= game_nb_cols(g))
        return;
    g->game[game_nb_rows(g) * i + j] = s;
}

square game_get_square(cgame g, uint i, uint j) {
    cgame_test(g, "g is not initialized\n");
    if (i >= game_nb_rows(g) || j >= game_nb_cols(g))
        throw_error("invalid index");
    return g->game[game_nb_rows(g) * i + j];
}

int game_get_number(cgame g, uint i, uint j) {
    cgame_test(g, "g is not initialized\n");
    if (i >= game_nb_rows(g) || j >= game_nb_cols(g))
        throw_error("i or j value is out of bounds!\n");
    uint index = game_nb_rows(g) * i + j;
    if (g->game[index] == S_EMPTY)
        return (-1);
    else if (g->game[index] == S_ZERO || g->game[index] == S_IMMUTABLE_ZERO)
        return (0);
    else
        return (1);
}

int game_get_next_square(cgame g, uint i, uint j, direction dir, uint dist) {
    cgame_test(g, "g is not initialized\n");
    if (dist > 2)
        throw_error("the distance value must be <=2!\n");
    if (game_is_wrapping(g)) {
        if (dir == LEFT)
            j -= dist % game_nb_cols(g);
        else if (dir == RIGHT)
            j += dist % game_nb_cols(g);
        else if (dir == UP)
            i -= dist % game_nb_rows(g);
        else
            i += dist % game_nb_rows(g);
    } else {
        if (dir == LEFT && dist <= j)
            j -= dist;
        else if (dir == RIGHT && (j + dist) < game_nb_cols(g))
            j += dist;
        else if (dir == UP && dist <= i)
            i -= dist;
        else if (dir == DOWN && (i + dist) < game_nb_rows(g))
            i += dist;
        else
            return (-1);
    }
    return (game_get_square(g, i, j));
}

int game_get_next_number(cgame g, uint i, uint j, direction dir, uint dist) {
    cgame_test(g, "g is not initialized\n");
    if (dist > 2)
        throw_error("the distance value must be <=2!\n");
    if (dir == LEFT && dist <= j)
        return (game_get_number(g, i, j - dist));
    else if (dir == RIGHT && (j + dist) < game_nb_cols(g))
        return (game_get_number(g, i, j + dist));
    else if (dir == UP && dist <= i)
        return (game_get_number(g, i - dist, j));
    else if (dir == DOWN && (i + dist) < game_nb_rows(g))
        return (game_get_number(g, i + dist, j));
    return (-1);
}

bool game_is_empty(cgame g, uint i, uint j) {
    cgame_test(g, "g is not initialized\n");
    assert(((i < game_nb_rows(g)) && (j < game_nb_cols(g))));
    return (game_get_square(g, i, j) == S_EMPTY);
}

bool game_is_immutable(cgame g, uint i, uint j) {
    cgame_test(g, "g is not initialized\n");
    assert(((i < game_nb_rows(g)) && (j < game_nb_cols(g))));
    square s = game_get_square(g, i, j);
    if (s == 3 || s == 4) {
        return true;
    }
    return false;
}

bool game_check_move(cgame g, uint i, uint j, square s) {
    cgame_test(g, "g is not initialized\n");
    assert(((i < game_nb_rows(g)) && (j < game_nb_cols(g))));
    if (s == S_IMMUTABLE_ONE || s == S_IMMUTABLE_ZERO)
        throw_error("[invalid parameter] square must not be immutable");

    square c = game_get_square(g, i, j);
    if (c == S_IMMUTABLE_ONE || c == S_IMMUTABLE_ZERO)
        return false;

    return true;
}

void game_play_move(game g, uint i, uint j, square s) {
    cgame_test(g, "g is not initialized\n");
    assert(((i < game_nb_rows(g)) && (j < game_nb_cols(g))));
    if (game_check_move(g, i, j, s))
        game_set_square(g, i, j, s);
    move m = move_create(i, j, s);
    g->history = ms_push(g->history, m);
    g->backup = ms_clear(g->backup);
}

bool game_is_over(cgame g) {
    cgame_test(g, "g is not initialized\n");
    for (uint i = 0; i < game_nb_rows(g); i++)
        for (uint j = 0; j < game_nb_cols(g); j++)
            if (game_is_empty(g, i, j) || game_has_error(g, i, j))
                return false;
    return true;
}

void game_restart(game g) {
    test_pointer(g, "g is not initialized\n");

    for (uint i = 0; i < game_nb_rows(g); i++)
        for (uint j = 0; j < game_nb_cols(g); j++)
            if (!game_is_immutable(g, i, j))
                game_set_square(g, i, j, S_EMPTY);

    g->history = ms_clear(g->history);
    g->backup = ms_clear(g->backup);
}