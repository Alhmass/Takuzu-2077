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
    g->game = malloc(sizeof(square) * (DEFAULT_SIZE * DEFAULT_SIZE));
    test_pointer(g->game, "malloc failed");
    memcpy(g->game, squares, sizeof(square) * (DEFAULT_SIZE * DEFAULT_SIZE));
    g->version = 1;
    return g;
}

game game_new_empty(void) {
    square *squares = (square *)calloc(DEFAULT_SIZE * DEFAULT_SIZE, sizeof(square));
    test_pointer(squares, "malloc failed");
    game g = game_new(squares);
    cgame_test(g, "malloc failed");
    free(squares);
    g->version = 1;
    return g;
}

game game_copy(cgame g) {
    game copy = memcpy(malloc(sizeof(struct game_s)), g, sizeof(struct game_s));
    cgame_test(copy, "malloc failed");
    uint rows_g = (g->version == 1) ? DEFAULT_SIZE : game_nb_rows(g);
    uint cols_g = (g->version == 1) ? DEFAULT_SIZE : game_nb_cols(g);
    copy->game = memcpy(malloc(sizeof(square) * rows_g * cols_g), g->game,
                        sizeof(square) * rows_g * cols_g);
    test_pointer(copy->game, "malloc failed");
    return copy;
}

bool game_equal(cgame g1, cgame g2) {
    if (g1 == NULL || g2 == NULL || g1->game == NULL || g2->game == NULL)
        return false;
    uint rows_g1 = (g1->version == 1) ? DEFAULT_SIZE : game_nb_rows(g1);
    uint cols_g1 = (g1->version == 1) ? DEFAULT_SIZE : game_nb_cols(g1);
    uint rows_g2 = (g2->version == 1) ? DEFAULT_SIZE : game_nb_rows(g2);
    uint cols_g2 = (g2->version == 1) ? DEFAULT_SIZE : game_nb_cols(g2);
    if (rows_g1 != rows_g2 || cols_g1 != cols_g2)
        return false;
    for (uint i = 0; i < rows_g1; i++) {
        for (uint j = 0; j < cols_g1; j++) {
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
    if (g->history != NULL)
        ms_delete(g->history);
    if (g->backup != NULL)
        ms_delete(g->backup);
    free(g);
}

void game_set_square(game g, uint i, uint j, square s) {
    uint rows_g = (g->version == 1) ? DEFAULT_SIZE : game_nb_rows(g);
    uint cols_g = (g->version == 1) ? DEFAULT_SIZE : game_nb_cols(g);
    if (i >= rows_g || j >= cols_g)
        return;
    g->game[rows_g * i + j] = s;
}

square game_get_square(cgame g, uint i, uint j) {
    cgame_test(g, "g is not initialized\n");
    uint rows_g = (g->version == 1) ? DEFAULT_SIZE : game_nb_rows(g);
    uint cols_g = (g->version == 1) ? DEFAULT_SIZE : game_nb_cols(g);
    if (i >= rows_g || j >= cols_g)
        throw_error("invalid index");
    return g->game[rows_g * i + j];
}

int game_get_number(cgame g, uint i, uint j) {
    cgame_test(g, "g is not initialized\n");
    uint rows_g = (g->version == 1) ? DEFAULT_SIZE : game_nb_rows(g);
    uint cols_g = (g->version == 1) ? DEFAULT_SIZE : game_nb_cols(g);
    if (i >= rows_g || j >= cols_g)
        throw_error("i or j value is out of bounds!\n");
    uint index = rows_g * i + j;
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
    uint rows_g = (g->version == 1) ? DEFAULT_SIZE : game_nb_rows(g);
    uint cols_g = (g->version == 1) ? DEFAULT_SIZE : game_nb_cols(g);
    if (g->version == 2 && game_is_wrapping(g)) {
        if (dir == LEFT)
            j = (j - dist) % cols_g;
        else if (dir == RIGHT)
            j = (j + dist) % cols_g;
        else if (dir == UP)
            i = (i - dist) % rows_g;
        else
            i = (i + dist) % rows_g;
    } else {
        if (dir == LEFT && dist <= j)
            j -= dist;
        else if (dir == RIGHT && (j + dist) < cols_g)
            j += dist;
        else if (dir == UP && dist <= i)
            i -= dist;
        else if (dir == DOWN && (i + dist) < rows_g)
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
    uint rows_g = (g->version == 1) ? DEFAULT_SIZE : game_nb_rows(g);
    uint cols_g = (g->version == 1) ? DEFAULT_SIZE : game_nb_cols(g);
    if (g->version == 2 && game_is_wrapping(g)) {
        if (dir == LEFT)
            j = (j - dist) % cols_g;
        else if (dir == RIGHT)
            j = (j + dist) % cols_g;
        else if (dir == UP)
            i = (i - dist) % rows_g;
        else
            i = (i + dist) % rows_g;
    } else {
        if (dir == LEFT && dist <= j)
            j -= dist;
        else if (dir == RIGHT && (j + dist) < cols_g)
            j += dist;
        else if (dir == UP && dist <= i)
            i -= dist;
        else if (dir == DOWN && (i + dist) < rows_g)
            i += dist;
        else
            return (-1);
    }
    return (game_get_number(g, i, j));
}

bool game_is_empty(cgame g, uint i, uint j) {
    cgame_test(g, "g is not initialized\n");
    uint rows_g = (g->version == 1) ? DEFAULT_SIZE : game_nb_rows(g);
    uint cols_g = (g->version == 1) ? DEFAULT_SIZE : game_nb_cols(g);
    assert(((i < rows_g) && (j < cols_g)));
    return (game_get_square(g, i, j) == S_EMPTY);
}

bool game_is_immutable(cgame g, uint i, uint j) {
    cgame_test(g, "g is not initialized\n");
    uint rows_g = (g->version == 1) ? DEFAULT_SIZE : game_nb_rows(g);
    uint cols_g = (g->version == 1) ? DEFAULT_SIZE : game_nb_cols(g);
    assert(((i < rows_g) && (j < cols_g)));
    square s = game_get_square(g, i, j);
    if (s == 3 || s == 4) {
        return true;
    }
    return false;
}

bool game_check_move(cgame g, uint i, uint j, square s) {
    cgame_test(g, "g is not initialized\n");
    uint rows_g = (g->version == 1) ? DEFAULT_SIZE : game_nb_rows(g);
    uint cols_g = (g->version == 1) ? DEFAULT_SIZE : game_nb_cols(g);
    assert(((i < rows_g) && (j < cols_g)));
    if (s == S_IMMUTABLE_ONE || s == S_IMMUTABLE_ZERO)
        throw_error("[invalid parameter] square must not be immutable");

    square c = game_get_square(g, i, j);
    if (c == S_IMMUTABLE_ONE || c == S_IMMUTABLE_ZERO)
        return false;

    return true;
}

void game_play_move(game g, uint i, uint j, square s) {
    cgame_test(g, "g is not initialized\n");
    uint rows_g = (g->version == 1) ? DEFAULT_SIZE : game_nb_rows(g);
    uint cols_g = (g->version == 1) ? DEFAULT_SIZE : game_nb_cols(g);
    assert(((i < rows_g) && (j < cols_g)));
    if (game_check_move(g, i, j, s)) {
        if (g->backup != NULL && g->history != NULL) {
            move m = move_create(i, j, s, game_get_square(g, i, j));
            ms_push(g->history, m);
            ms_clear(g->backup);
            free(m);
        }
        game_set_square(g, i, j, s);
    }
}

bool game_is_over(cgame g) {
    cgame_test(g, "g is not initialized\n");
    uint rows_g = (g->version == 1) ? DEFAULT_SIZE : game_nb_rows(g);
    uint cols_g = (g->version == 1) ? DEFAULT_SIZE : game_nb_cols(g);
    for (uint i = 0; i < rows_g; i++)
        for (uint j = 0; j < cols_g; j++)
            if (game_is_empty(g, i, j) || game_has_error(g, i, j))
                return false;
    return true;
}

void game_restart(game g) {
    test_pointer(g, "g is not initialized\n");
    uint rows_g = (g->version == 1) ? DEFAULT_SIZE : game_nb_rows(g);
    uint cols_g = (g->version == 1) ? DEFAULT_SIZE : game_nb_cols(g);
    for (uint i = 0; i < rows_g; i++)
        for (uint j = 0; j < cols_g; j++)
            if (!game_is_immutable(g, i, j))
                game_set_square(g, i, j, S_EMPTY);
    if (g->history != NULL)
        ms_clear(g->history);
    if (g->backup != NULL)
        ms_clear(g->backup);
}