#include "takuzu.h"

/* ************************************************************************** */
/*                                 GAME EXT                                   */
/* ************************************************************************** */

game game_new_ext(uint nb_rows, uint nb_cols, square* squares, bool wrapping, bool unique) {
    game g = game_new_empty_ext(nb_rows, nb_cols, wrapping, unique);
    assert(g);

    // set squares
    for (uint i = 0; i < g->nb_rows; i++) {
        for (uint j = 0; j < g->nb_cols; j++) {
            square s = squares[i * nb_cols + j];
            SQUARE(g, i, j) = s;

            if (s == S_EMPTY) {
                g->nb_empty++;
            } else if (s == S_IMMUTABLE_ZERO) {
                g->nb_zero++;
            } else if (s == S_IMMUTABLE_ONE) {
                g->nb_one++;
            }
        }
    }

    return g;
}

/* ************************************************************************** */

game game_new_empty_ext(uint nb_rows, uint nb_cols, bool wrapping, bool unique) {
    game g = (game)malloc(sizeof(struct game_s));
    assert(g);
    assert(nb_cols % 2 == 0);
    assert(nb_rows % 2 == 0);
    g->nb_rows = nb_rows;
    g->nb_cols = nb_cols;
    g->wrapping = wrapping;
    g->unique = unique;
    g->squares = (square*)calloc(g->nb_rows * g->nb_cols, sizeof(uint));
    assert(g->squares);

    // initialize history
    g->undo_stack = queue_new();
    assert(g->undo_stack);
    g->redo_stack = queue_new();
    assert(g->redo_stack);

    // initialize counters
    g->nb_empty = nb_rows * nb_cols;
    g->nb_zero = 0;
    g->nb_one = 0;
    return g;
}

/* ************************************************************************** */

uint game_nb_rows(cgame g) { return g->nb_rows; }

/* ************************************************************************** */

uint game_nb_cols(cgame g) { return g->nb_cols; }

/* ************************************************************************** */

bool game_is_wrapping(cgame g) { return g->wrapping; }

/* ************************************************************************** */

bool game_is_unique(cgame g) { return g->unique; }

/* ************************************************************************** */

void game_undo(game g) {
    assert(g);
    if (_stack_is_empty(g->undo_stack))
        return;
    move m = _stack_pop_move(g->undo_stack);
    game_set_square(g, m.i, m.j, m.old);
    _stack_push_move(g->redo_stack, m);
}

/* ************************************************************************** */

void game_redo(game g) {
    assert(g);
    if (_stack_is_empty(g->redo_stack))
        return;
    move m = _stack_pop_move(g->redo_stack);
    game_set_square(g, m.i, m.j, m.new);
    _stack_push_move(g->undo_stack, m);
}

/* ************************************************************************** */

uint game_nb_empty(cgame g) { return g->nb_empty; }

/* ************************************************************************** */

uint game_nb_zero(cgame g) { return g->nb_zero; }

/* ************************************************************************** */

uint game_nb_one(cgame g) { return g->nb_one; }

/* ************************************************************************** */

void update_counters(game g) {
    g->nb_empty = 0;
    g->nb_zero = 0;
    g->nb_one = 0;

    for (uint i = 0; i < g->nb_rows; i++) {
        for (uint j = 0; j < g->nb_cols; j++) {
            if (SQUARE(g, i, j) == S_EMPTY) {
                g->nb_empty++;
            } else if (SQUARE(g, i, j) == S_IMMUTABLE_ZERO) {
                g->nb_zero++;
            } else if (SQUARE(g, i, j) == S_IMMUTABLE_ONE) {
                g->nb_one++;
            }
        }
    }
}