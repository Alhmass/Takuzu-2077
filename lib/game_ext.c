#include "game_ext.h"

#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "game_struct.h"
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

game game_new_ext(uint nb_rows, uint nb_cols, square *squares, bool wrapping, bool unique) {
    game g = malloc(sizeof(struct game_s));
    test_pointer(g, "game_nex_ext: game_ext malloc failed");
    test_pointer(squares, "game_nex_ext: squares is NULL");
    g->game = malloc(sizeof(square) * (nb_rows * nb_cols));
    test_pointer(g->game, "game_nex_ext: game malloc failed");
    memcpy(g->game, squares, sizeof(square) * (nb_rows * nb_cols));
    g->history = ms_create(1);
    g->nb_rows = nb_rows;
    g->nb_cols = nb_cols;
    g->wrapping = wrapping;
    g->unique = unique;
    return g;
}

game game_new_empty_ext(uint nb_rows, uint nb_cols, bool wrapping, bool unique) {
    (void)nb_rows;
    (void)nb_cols;
    (void)wrapping;
    (void)unique;

    return (NULL);
}

uint game_nb_rows(cgame g) {
    cgame_test(g, "g is NULL");
    return (0);
}

uint game_nb_cols(cgame g) {
    cgame_test(g, "g is NULL");
    return (0);
}

bool game_is_wrapping(cgame g) {
    cgame_test(g, "g is NULL");
    return (true);
}

bool game_is_unique(cgame g) {
    cgame_test(g, "g is NULL");
    return (true);
}

void game_undo(game g) {
    cgame_test(g, "g is NULL");
    return;
}

void game_redo(game g) {
    cgame_test(g, "g is NULL");
    return;
}