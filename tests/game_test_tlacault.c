#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "game.h"
#include "game_aux.h"
#include "game_ext.h"
#include "move_stack.h"

/*  TEST  */
bool test_game_new(void) {
    square squares[DEFAULT_SIZE * DEFAULT_SIZE] = {0, 4, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 3, 0,
                                                   0, 3, 4, 0, 0, 0, 0, 0, 4, 0, 0, 3, 0, 0, 0, 0, 0, 3};
    game g = game_new(squares);
    game g2 = game_default();

    if (g == NULL || g2 == NULL)
        return false;
    if (!game_equal(g, g2)) {
        game_delete(g);
        game_delete(g2);
        return false;
    }
    game_delete(g);
    game_delete(g2);
    return true;
}

bool test_game_new_empty(void) {
    square squares[DEFAULT_SIZE * DEFAULT_SIZE] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                                   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    game g1 = game_new(squares);
    game g2 = game_new_empty();

    if (g1 == NULL || g2 == NULL)
        return false;
    if (!game_equal(g1, g2)) {
        game_delete(g1);
        game_delete(g2);
        return false;
    }
    game_delete(g1);
    game_delete(g2);
    return true;
}

bool test_game_copy(void) {
    game g1 = game_default();
    game g1_copy = game_copy(g1);

    if (g1 == NULL || g1_copy == NULL)
        return false;
    if (!game_equal(g1, g1_copy)) {
        game_delete(g1);
        game_delete(g1_copy);
        return false;
    }
    game_set_square(g1, 0, 0, 1);
    if (game_equal(g1, g1_copy)) {
        game_delete(g1);
        game_delete(g1_copy);
        return false;
    }
    game_delete(g1);
    game_delete(g1_copy);
    return true;
}

bool test_game_equal(void) {
    square squares_1[DEFAULT_SIZE * DEFAULT_SIZE] = {0, 4, 3, 0, 1, 0, 1, 0, 2, 0, 0, 0, 0, 3, 0, 2, 3, 0,
                                                     0, 3, 4, 0, 1, 0, 0, 1, 4, 0, 2, 3, 0, 0, 0, 2, 0, 3};
    game g1 = game_new(squares_1);
    square squares_2[DEFAULT_SIZE * DEFAULT_SIZE] = {0, 2, 3, 0, 1, 0, 1, 0, 2, 0, 0, 0, 0, 3, 0, 2, 1, 0,
                                                     0, 3, 4, 0, 1, 0, 0, 1, 4, 0, 2, 3, 0, 0, 0, 2, 0, 3};
    game g2 = game_new(squares_2);

    if (g1 == NULL || g2 == NULL)
        return false;
    if (game_equal(g1, g2)) {
        game_delete(g1);
        game_delete(g2);
        return false;
    }
    game_delete(g1);
    game_delete(g2);
    return true;
}

bool test_game_delete(void) { return true; }

bool test_game_is_empty(void) {
    square squares[DEFAULT_SIZE * DEFAULT_SIZE] = {0, 4, 3, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 3, 0, 0, 3, 0,
                                                   0, 3, 4, 1, 0, 0, 0, 0, 4, 0, 1, 3, 0, 1, 0, 0, 0, 3};
    game g = game_new(squares);

    if (!g)
        return false;

    for (uint j = 0; j < DEFAULT_SIZE; j++) {
        for (uint i = 0; i < DEFAULT_SIZE; i++) {
            if (game_get_square(g, i, j) == 0 && !game_is_empty(g, i, j)) {
                game_delete(g);
                return false;
            }
            if (game_get_square(g, i, j) == 1 && game_is_empty(g, i, j)) {
                game_delete(g);
                return false;
            }
        }
    }
    game_delete(g);
    return true;
}

bool test_game_restart(void) {
    square squares[DEFAULT_SIZE * DEFAULT_SIZE] = {0, 4, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 3, 0,
                                                   0, 3, 4, 0, 0, 0, 0, 0, 4, 0, 0, 3, 0, 0, 0, 0, 0, 3};
    game g = game_new(squares);

    if (!g)
        return false;

    game_set_square(g, 0, 0, S_ZERO);
    game_set_square(g, 3, 5, S_ONE);
    game_restart(g);

    for (uint i = 0; i < DEFAULT_SIZE; i++) {
        for (uint j = 0; j < DEFAULT_SIZE; j++) {
            if (game_get_square(g, i, j) != game_get_square(g, i, j)) {
                game_delete(g);
                return false;
            }
        }
    }
    game_delete(g);
    return true;
}

bool test_game_default(void) {
    square squares[DEFAULT_SIZE * DEFAULT_SIZE] = {0, 4, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 3, 0,
                                                   0, 3, 4, 0, 0, 0, 0, 0, 4, 0, 0, 3, 0, 0, 0, 0, 0, 3};
    game g = game_new(squares);
    game g2 = game_default();

    if (g == NULL || g2 == NULL)
        return false;
    if (!game_equal(g, g2)) {
        game_delete(g);
        game_delete(g2);
        return false;
    }
    game_delete(g);
    game_delete(g2);
    return true;
}

bool test_game_default_solution(void) {
    square squares[DEFAULT_SIZE * DEFAULT_SIZE] = {1, 4, 3, 2, 1, 2, 1, 2, 2, 1, 2, 1, 2, 3, 1, 2, 3, 2,
                                                   2, 3, 4, 1, 1, 2, 1, 2, 4, 1, 2, 3, 2, 1, 1, 2, 2, 3};
    game g = game_new(squares);
    game g2 = game_default_solution();

    if (g == NULL || g2 == NULL)
        return false;
    if (!game_equal(g, g2)) {
        game_delete(g);
        game_delete(g2);
        return false;
    }
    game_delete(g);
    game_delete(g2);
    return true;
}

bool test_game_new_ext(void) {
    square squares[DEFAULT_SIZE * DEFAULT_SIZE] = {1, 4, 3, 2, 1, 2, 1, 2, 2, 1, 2, 1, 2, 3, 1, 2, 3, 2,
                                                   2, 3, 4, 1, 1, 2, 1, 2, 4, 1, 2, 3, 2, 1, 1, 2, 2, 3};
    game g = game_new_ext(DEFAULT_SIZE, DEFAULT_SIZE, squares, 1, 1);
    if (g == NULL)
        return false;
    if (game_nb_rows(g) != DEFAULT_SIZE || game_nb_cols(g) != DEFAULT_SIZE || !game_is_wrapping(g) ||
        !game_is_unique(g)) {
        game_delete(g);
        return false;
    }
    game def_solution = game_default_solution();
    if (def_solution == NULL) {
        game_delete(g);
        return false;
    }
    if (!game_equal(g, def_solution)) {
        game_delete(def_solution);
        game_delete(g);
        return false;
    }
    game_delete(def_solution);
    game_delete(g);
    return true;
}

bool test_game_new_empty_ext(void) {
    game g = game_new_empty_ext(DEFAULT_SIZE, DEFAULT_SIZE, 1, 1);
    game empty = game_new_empty();
    if (g == NULL || empty == NULL)
        return false;
    if (game_nb_rows(g) != DEFAULT_SIZE || game_nb_cols(g) != DEFAULT_SIZE || !game_is_wrapping(g) ||
        !game_is_unique(g)) {
        game_delete(empty);
        game_delete(g);
        return false;
    }
    if (!game_equal(g, empty)) {
        game_delete(empty);
        game_delete(g);
        return false;
    }
    game_delete(empty);
    game_delete(g);
    return true;
}

bool test_game_undo(void) {
    game g = game_new_empty();
    game_play_move(g, 0, 0, S_ONE);
    square before = game_get_square(g, 0, 0);
    game_undo(g);
    square after = game_get_square(g, 0, 0);
    if (before != after) {
        game_delete(g);
        return false;
    }

    game_play_move(g, 0, 0, S_ONE);
    game_play_move(g, 0, 1, S_ONE);
    game_play_move(g, 0, 2, S_ONE);
    square before2 = game_get_square(g, 0, 1);
    square before3 = game_get_square(g, 0, 2);
    game_undo(g);
    game_undo(g);
    square after2 = game_get_square(g, 0, 1);
    square after3 = game_get_square(g, 0, 2);
    if (before2 != after2 || before3 != after3) {
        game_delete(g);
        return false;
    }

    game_delete(g);
    return true;
}

bool test_game_redo(void) {
    game g = game_new_empty();
    game_play_move(g, 0, 0, S_ONE);
    game_play_move(g, 0, 1, S_ONE);
    game_play_move(g, 0, 2, S_ONE);
    game_undo(g);
    game_undo(g);
    square before = game_get_square(g, 0, 1);
    square before2 = game_get_square(g, 0, 2);
    game_redo(g);
    game_redo(g);
    square after = game_get_square(g, 0, 1);
    square after2 = game_get_square(g, 0, 2);
    if (before != after || before2 != after2) {
        game_delete(g);
        return false;
    }

    game_play_move(g, 1, 0, S_ONE);
    game_play_move(g, 1, 1, S_ONE);
    game_play_move(g, 1, 2, S_ONE);
    game_undo(g);
    game_undo(g);
    game_play_move(g, 2, 0, S_ONE);
    square before3 = game_get_square(g, 1, 1);
    game_redo(g);
    square after3 = game_get_square(g, 1, 1);
    if (before3 != after3) {
        game_delete(g);
        return false;
    }
    game_delete(g);
    return true;
}

/*  USAGE  */
void usage(char *argv[]) {
    fprintf(stderr, "Usage: %s <testname> [<...>]\n", argv[0]);
    exit(EXIT_FAILURE);
}

/*  MAIN ROUTINE  */
int main(int argc, char *argv[]) {
    if (argc == 1)
        usage(argv);

    fprintf(stderr, "=> Start test \"%s\"\n", argv[1]);
    bool ok = false;
    if (strcmp("game_new", argv[1]) == 0)
        ok = test_game_new();
    else if (strcmp("game_new_empty", argv[1]) == 0)
        ok = test_game_new_empty();
    else if (strcmp("game_copy", argv[1]) == 0)
        ok = test_game_copy();
    else if (strcmp("game_equal", argv[1]) == 0)
        ok = test_game_equal();
    else if (strcmp("game_delete", argv[1]) == 0)
        ok = test_game_delete();
    else if (strcmp("game_is_empty", argv[1]) == 0)
        ok = test_game_is_empty();
    else if (strcmp("game_restart", argv[1]) == 0)
        ok = test_game_restart();
    else if (strcmp("game_default", argv[1]) == 0)
        ok = test_game_default();
    else if (strcmp("game_default_solution", argv[1]) == 0)
        ok = test_game_default_solution();
    else if (strcmp("game_new_ext", argv[1]) == 0)
        ok = test_game_new_ext();
    else if (strcmp("game_new_empty_ext", argv[1]) == 0)
        ok = test_game_new_empty_ext();
    else if (strcmp("game_undo", argv[1]) == 0)
        ok = test_game_undo();
    else if (strcmp("game_redo", argv[1]) == 0)
        ok = test_game_redo();
    else {
        fprintf(stderr, "Error: test \"%s\" not found!\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    if (ok) {
        fprintf(stderr, "Test \"%s\" finished: SUCCESS\n", argv[1]);
        return EXIT_SUCCESS;
    } else {
        fprintf(stderr, "Test \"%s\" finished: FAILURE\n", argv[1]);
        return EXIT_FAILURE;
    }
}
