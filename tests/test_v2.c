#include "takuzu.h"

bool test_new_ext() { return true; }

bool test_new_empty_ext() { return true; }

bool test_equal_ext() { return true; }

bool test_copy_ext() { return true; }

bool test_get_next_square_wrapping() { return true; }

bool test_get_next_number_wrapping() { return true; }

bool test_has_error_wrapping() {
    bool status = true;
    square squares[4 * 8] = {3, 1, 2, 2, 1, 2, 2, 1, 1, 1, 2, 2, 1, 2, 2, 1,
                             2, 2, 1, 1, 2, 1, 1, 2, 2, 2, 1, 1, 2, 1, 1, 2};
    game g1 = game_new_ext(4, 8, squares, false, false);
    game g2 = game_new_ext(4, 8, squares, true, false);

    if (!g1 || !g2)
        return false;
    if (!game_has_error(g2, 0, 0) || game_has_error(g1, 0, 0))
        status = false;
    game_delete(g1);
    game_delete(g2);
    return status;
}

bool test_is_over_wrapping() {
    bool status = true;
    square squares[4 * 8] = {3, 1, 2, 2, 1, 2, 2, 1, 1, 1, 2, 2, 1, 2, 2, 1,
                             2, 2, 1, 1, 2, 1, 1, 2, 2, 2, 1, 1, 2, 1, 1, 2};
    game g1 = game_new_ext(4, 8, squares, false, false);
    game g2 = game_new_ext(4, 8, squares, true, false);

    if (!g1 || !g2)
        return false;

    if (!game_is_over(g1) || game_is_over(g2))
        status = false;
    game_delete(g1);
    game_delete(g2);
    return status;
}

bool test_has_error_unique() {
    bool status = false;
    square squares[4 * 8] = {3, 1, 2, 2, 1, 2, 2, 1, 1, 1, 2, 2, 1, 2, 2, 1,
                             2, 2, 1, 1, 2, 1, 1, 2, 2, 2, 1, 1, 2, 1, 1, 2};
    game g2 = game_new_ext(4, 8, squares, false, true);

    if (!g2)
        return false;
    for (uint i = 0; i < 4; i++)
        for (uint j = 0; j < 8; j++)
            if (game_has_error(g2, i, j))
                status = true;
    game_delete(g2);
    return status;
}

bool test_is_over_unique() {
    bool status = true;
    square squares[4 * 8] = {3, 1, 2, 2, 1, 2, 2, 1, 1, 1, 2, 2, 1, 2, 2, 1,
                             2, 2, 1, 1, 2, 1, 1, 2, 2, 2, 1, 1, 2, 1, 1, 2};
    game g1 = game_new_ext(4, 8, squares, false, false);
    game g2 = game_new_ext(4, 8, squares, false, true);
    game g3 = game_new_ext(4, 8, squares, true, true);

    if (!g1 || !g2 || !g3)
        return false;
    if (!game_is_over(g1) || game_is_over(g2) || game_is_over(g3))
        status = false;
    game_delete(g1);
    game_delete(g2);
    game_delete(g3);
    return status;
}

bool test_undo_one() {
    bool pass = true;
    game g1 = game_new_empty_ext(4, 4, false, false);
    game_undo(g1);
    game_delete(g1);

    game g2 = game_new_empty_ext(4, 4, false, false);
    game_play_move(g2, 0, 0, S_ONE);
    game_undo(g2);
    if (game_get_square(g2, 0, 0) != S_EMPTY)
        pass = false;
    game_delete(g2);

    game g3 = game_new_empty_ext(4, 4, false, false);
    game_play_move(g3, 0, 0, S_ONE);
    game_play_move(g3, 0, 1, S_ONE);
    game_undo(g3);
    if (game_get_square(g3, 0, 0) != S_ONE || game_get_square(g3, 0, 1) != S_EMPTY)
        pass = false;
    game_delete(g3);

    game g4 = game_new_empty_ext(4, 4, false, false);
    for (int i = 0; i < 20; i++) {
        game_play_move(g4, 2, 2, S_ONE);
        game_undo(g4);
    }
    if (game_get_square(g4, 2, 2) != S_EMPTY)
        pass = false;
    game_delete(g4);
    return pass;
}

bool test_undo_redo_some() {
    bool pass = true;
    game g1 = game_new_empty_ext(4, 4, false, false);
    game_play_move(g1, 0, 0, S_ONE);
    game_play_move(g1, 0, 1, S_ONE);
    game_play_move(g1, 0, 2, S_ONE);
    game_play_move(g1, 0, 3, S_ONE);
    game_undo(g1);
    game_undo(g1);
    game_undo(g1);
    if (game_get_square(g1, 0, 0) != S_ONE || game_get_square(g1, 0, 1) != S_EMPTY ||
        game_get_square(g1, 0, 2) != S_EMPTY || game_get_square(g1, 0, 3) != S_EMPTY)
        pass = false;
    game_redo(g1);
    game_redo(g1);
    game_redo(g1);
    if (game_get_square(g1, 0, 0) != S_ONE || game_get_square(g1, 0, 1) != S_ONE ||
        game_get_square(g1, 0, 2) != S_ONE || game_get_square(g1, 0, 3) != S_ONE)
        pass = false;
    game_delete(g1);
    return pass;
}

bool test_undo_redo_all() {
    bool pass = true;
    game g1 = game_new_empty_ext(4, 4, false, false);
    for (int i = 0; i < 20; i++) {
        game_play_move(g1, 2, 2, S_ONE);
    }
    game_play_move(g1, 2, 2, S_ZERO);
    for (int i = 0; i < 22; i++) {
        game_undo(g1);
    }
    if (game_get_square(g1, 2, 2) != S_EMPTY)
        pass = false;
    for (int i = 0; i < 22; i++) {
        game_redo(g1);
    }
    if (game_get_square(g1, 2, 2) != S_ZERO)
        pass = false;
    game_delete(g1);
    return pass;
}

bool test_restart_undo() {
    bool pass = true;
    game g1 = game_new_empty_ext(4, 4, false, false);
    game_play_move(g1, 0, 0, S_ONE);
    game_play_move(g1, 0, 1, S_ONE);
    game_play_move(g1, 0, 2, S_ONE);
    game_restart(g1);
    game_undo(g1);
    if (game_get_square(g1, 0, 0) != S_EMPTY || game_get_square(g1, 0, 1) != S_EMPTY ||
        game_get_square(g1, 0, 2) != S_EMPTY)
        pass = false;
    game_delete(g1);
    return pass;
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
    if (strcmp("new_ext", argv[1]) == 0)
        pass = test_new_ext();
    else if (strcmp("new_empty_ext", argv[1]) == 0)
        pass = test_new_empty_ext();
    else if (strcmp("equal_ext", argv[1]) == 0)
        pass = test_equal_ext();
    else if (strcmp("copy_ext", argv[1]) == 0)
        pass = test_copy_ext();
    else if (strcmp("get_next_square_wrapping", argv[1]) == 0)
        pass = test_get_next_square_wrapping();
    else if (strcmp("get_next_number_wrapping", argv[1]) == 0)
        pass = test_get_next_number_wrapping();
    else if (strcmp("has_error_wrapping", argv[1]) == 0)
        pass = test_has_error_wrapping();
    else if (strcmp("is_over_wrapping", argv[1]) == 0)
        pass = test_is_over_wrapping();
    else if (strcmp("has_error_unique", argv[1]) == 0)
        pass = test_has_error_unique();
    else if (strcmp("is_over_unique", argv[1]) == 0)
        pass = test_is_over_unique();
    else if (strcmp("undo_one", argv[1]) == 0)
        pass = test_undo_one();
    else if (strcmp("undo_redo_some", argv[1]) == 0)
        pass = test_undo_redo_some();
    else if (strcmp("undo_redo_all", argv[1]) == 0)
        pass = test_undo_redo_all();
    else if (strcmp("restart_undo", argv[1]) == 0)
        pass = test_restart_undo();
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
