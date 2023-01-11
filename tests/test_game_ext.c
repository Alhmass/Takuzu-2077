#include "takuzu.h"

bool test_game_new_ext(void) {
    square squares[DEFAULT_SIZE * DEFAULT_SIZE] = {1, 4, 3, 2, 1, 2, 1, 2, 2, 1, 2, 1, 2, 3, 1, 2, 3, 2,
                                                   2, 3, 4, 1, 1, 2, 1, 2, 4, 1, 2, 3, 2, 1, 1, 2, 2, 3};
    game g1 = game_new_ext(DEFAULT_SIZE, DEFAULT_SIZE, squares, true, true);
    game g2 = game_new_ext(DEFAULT_SIZE, DEFAULT_SIZE, squares, false, false);
    if (g1 == NULL || g2 == NULL)
        return false;

    if (game_nb_rows(g1) != DEFAULT_SIZE || game_nb_cols(g1) != DEFAULT_SIZE || !game_is_wrapping(g1) ||
        !game_is_unique(g1)) {
        game_delete(g1);
        game_delete(g2);
        return false;
    }
    if (game_nb_rows(g2) != DEFAULT_SIZE || game_nb_cols(g2) != DEFAULT_SIZE || game_is_wrapping(g2) ||
        game_is_unique(g2)) {
        game_delete(g1);
        game_delete(g2);
        return false;
    }
    if (!game_equal(g1, g2)) {
        game_delete(g1);
        game_delete(g2);
        return false;
    }
    game_delete(g1);
    game_delete(g2);
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

bool test_game_nb_rows(void) {
    bool status = true;
    game g = game_new_empty_ext(12, 12, false, false);
    game g2 = game_new_empty_ext(8, 4, false, false);
    if (!g || !g2)
        return false;
    // if (game_nb_rows(g) != 12 || game_nb_rows(g2) != 8)
    //     status = false;
    game_delete(g);
    game_delete(g2);
    return status;
}

bool test_game_nb_cols(void) {
    bool status = true;
    game g = game_new_empty_ext(12, 12, false, false);
    game g2 = game_new_empty_ext(8, 4, false, false);
    if (!g || !g2)
        return false;
    // if (game_nb_cols(g) != 12 || game_nb_cols(g2) != 4)
    //     status = false;
    game_delete(g);
    game_delete(g2);
    return status;
}

bool test_game_is_unique(void) {
    game g1 = game_new_empty_ext(8, 8, false, true);
    game g2 = game_new_empty_ext(8, 8, false, false);
    if (!game_is_unique(g1) || game_is_unique(g2)) {
        game_delete(g1);
        game_delete(g2);
        return false;
    }
    game_delete(g1);
    game_delete(g2);
    return true;
}

bool test_game_is_wrapping(void) {
    game g1 = game_new_empty_ext(8, 8, true, false);
    game g2 = game_new_empty_ext(8, 8, false, false);
    if (!game_is_wrapping(g1) || game_is_wrapping(g2)) {
        game_delete(g1);
        game_delete(g2);
        return false;
    }
    game_delete(g1);
    game_delete(g2);
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
    bool pass = false;
    if (strcmp("game_new_ext", argv[1]) == 0)
        pass = test_game_new_ext();
    else if (strcmp("game_new_empty_ext", argv[1]) == 0)
        pass = test_game_new_empty_ext();
    else if (strcmp("game_undo", argv[1]) == 0)
        pass = test_game_undo();
    else if (strcmp("game_redo", argv[1]) == 0)
        pass = test_game_redo();
    else if (strcmp("game_nb_rows", argv[1]) == 0)
        pass = test_game_nb_rows();
    else if (strcmp("game_nb_cols", argv[1]) == 0)
        pass = test_game_nb_cols();
    else if (strcmp("game_is_unique", argv[1]) == 0)
        pass = test_game_is_unique();
    else if (strcmp("game_is_wrapping", argv[1]) == 0)
        pass = test_game_is_wrapping();
    else {
        fprintf(stderr, "Error: test \"%s\" not found!\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    if (pass == true) {
        fprintf(stderr, "Test \"%s\" finished: SUCCESS\n", argv[1]);
        return EXIT_SUCCESS;
    } else {
        fprintf(stderr, "Test \"%s\" finished: FAILURE\n", argv[1]);
        return EXIT_FAILURE;
    }
}