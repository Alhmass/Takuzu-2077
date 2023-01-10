#include "takuzu.h"

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

bool test_game_set_square() {
    square squares[DEFAULT_SIZE * DEFAULT_SIZE] = {0, 4, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 3, 0,
                                                   0, 3, 4, 0, 0, 0, 0, 0, 4, 0, 0, 3, 0, 0, 0, 0, 0, 3};
    game g = game_new(squares);

    if (!g)
        return (false);
    game_set_square(g, 0, 0, S_ZERO);
    squares[DEFAULT_SIZE * 0 + 0] = S_ZERO;
    game_set_square(g, 1, 0, S_ONE);
    squares[DEFAULT_SIZE * 1 + 0] = S_ONE;
    game_set_square(g, 0, 3, S_IMMUTABLE_ZERO);
    squares[DEFAULT_SIZE * 0 + 3] = S_IMMUTABLE_ZERO;
    game_set_square(g, 1, 5, S_IMMUTABLE_ONE);
    squares[DEFAULT_SIZE * 1 + 5] = S_IMMUTABLE_ONE;
    game_set_square(g, 0, 1, S_EMPTY);
    squares[DEFAULT_SIZE * 0 + 1] = S_EMPTY;
    for (int i = 0; i < DEFAULT_SIZE; i++) {
        for (int j = 0; j < DEFAULT_SIZE; j++) {
            if (game_get_square(g, i, j) != squares[DEFAULT_SIZE * i + j])
                return (false);
        }
    }
    game_delete(g);
    return (true);
}

bool test_game_get_square() {
    game g = game_default();
    bool status = true;

    if (!g)
        return (false);
    game_set_square(g, 0, 0, S_ZERO);
    game_set_square(g, 1, 0, S_ONE);
    game_set_square(g, 0, 3, S_IMMUTABLE_ZERO);
    game_set_square(g, 1, 5, S_IMMUTABLE_ONE);
    game_set_square(g, 0, 1, S_EMPTY);
    if (game_get_square(g, 0, 0) != S_ZERO)
        status = false;
    else if (game_get_square(g, 1, 0) != S_ONE)
        status = false;
    else if (game_get_square(g, 0, 3) != S_IMMUTABLE_ZERO)
        status = false;
    else if (game_get_square(g, 1, 5) != S_IMMUTABLE_ONE)
        status = false;
    else if (game_get_square(g, 0, 1) != S_EMPTY)
        status = false;
    game_delete(g);
    return (status);
}

bool test_game_get_number() {
    game g = game_default();
    bool status = true;

    if (!g)
        return (false);
    game_set_square(g, 0, 3, S_ONE);
    game_set_square(g, 0, 4, S_ZERO);
    if (game_get_number(g, 0, 1) != 1)
        status = false;
    else if (game_get_number(g, 0, 0) != -1)
        status = false;
    else if (game_get_number(g, 2, 1) != 0)
        status = false;
    else if (game_get_number(g, 0, 3) != 1)
        status = false;
    else if (game_get_number(g, 0, 4) != 0)
        status = false;
    game_delete(g);
    return (status);
}

bool test_game_get_next_square() {
    game g = game_default();
    game g2 = game_new_empty_ext(7, 14, true, false);
    bool status = true;

    if (!g || !g2)
        return (false);
    game_set_square(g, 0, 3, S_ZERO);
    game_set_square(g, 0, 4, S_ONE);
    game_set_square(g2, 0, 2, S_ONE);
    game_set_square(g2, 1, 2, S_ONE);
    if (game_get_next_square(g, 0, 0, RIGHT, 1) != S_IMMUTABLE_ONE)
        status = false;
    else if (game_get_next_square(g, 0, 0, RIGHT, 2) != S_IMMUTABLE_ZERO)
        status = false;
    else if (game_get_next_square(g, 0, 0, DOWN, 1) != S_EMPTY)
        status = false;
    else if (game_get_next_square(g, 3, 0, LEFT, 2) != -1)
        status = false;
    else if (game_get_next_square(g, 2, 1, UP, 2) != S_IMMUTABLE_ONE)
        status = false;
    else if (game_get_next_square(g, 0, 1, RIGHT, 2) != S_ZERO)
        status = false;
    else if (game_get_next_square(g, 0, 5, LEFT, 1) != S_ONE)
        status = false;
    else if (game_get_next_square(g2, 0, 14, RIGHT, 2) != S_ONE)
        status = false;
    else if (game_get_next_square(g2, 7, 2, DOWN, 1) != S_ONE)
        status = false;
    game_delete(g);
    game_delete(g2);
    return (status);
}

bool test_game_get_next_number() {
    game g = game_default();
    game g2 = game_new_empty_ext(7, 14, true, false);
    bool status = true;

    if (!g || !g2)
        return (false);
    game_set_square(g, 0, 3, S_ZERO);
    game_set_square(g, 0, 4, S_ONE);
    game_set_square(g2, 0, 2, S_ONE);
    game_set_square(g2, 1, 2, S_ONE);
    if (game_get_next_number(g, 0, 0, RIGHT, 1) != 1)
        status = false;
    else if (game_get_next_number(g, 0, 0, RIGHT, 2) != 0)
        status = false;
    else if (game_get_next_number(g, 0, 0, DOWN, 1) != -1)
        status = false;
    else if (game_get_next_number(g, 3, 0, LEFT, 2) != -1)
        status = false;
    else if (game_get_next_number(g, 2, 1, UP, 2) != 1)
        status = false;
    else if (game_get_next_number(g, 0, 1, RIGHT, 2) != 0)
        status = false;
    else if (game_get_next_number(g, 0, 5, LEFT, 1) != 1)
        status = false;
    else if (game_get_next_number(g2, 0, 14, RIGHT, 2) != 1)
        status = false;
    else if (game_get_next_number(g2, 7, 2, DOWN, 1) != 1)
        status = false;
    game_delete(g);
    game_delete(g2);
    return (status);
}

bool test_game_is_immutable() {
    square squares[DEFAULT_SIZE * DEFAULT_SIZE] = {0, 4, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 3, 0,
                                                   0, 3, 4, 0, 0, 0, 0, 0, 4, 0, 0, 3, 0, 0, 0, 0, 0, 3};
    game g = game_new_ext(DEFAULT_SIZE, DEFAULT_SIZE, squares, false, false);

    if (!g)
        return false;
    for (uint i = 0; i < DEFAULT_SIZE; i++) {
        for (uint j = 0; j < DEFAULT_SIZE; j++) {
            if (game_is_immutable(g, i, j) &&
                (game_get_square(g, i, j) != S_IMMUTABLE_ONE && game_get_square(g, i, j) != S_IMMUTABLE_ZERO)) {
                game_delete(g);
                return false;
            } else if (!(game_is_immutable(g, i, j)) &&
                       (game_get_square(g, i, j) == S_IMMUTABLE_ONE || game_get_square(g, i, j) == S_IMMUTABLE_ZERO)) {
                game_delete(g);
                return false;
            }
        }
    }
    game_delete(g);
    return true;
}

bool test_game_has_error() {
    game g1 = game_default_solution();
    square squares_2[DEFAULT_SIZE * DEFAULT_SIZE] = {1, 1, 1, 2, 2, 2, 1, 1, 1, 2, 2, 2, 1, 1, 1, 2, 2, 2,
                                                     4, 4, 4, 3, 3, 3, 4, 4, 4, 3, 3, 3, 4, 4, 4, 3, 3, 3};
    game g2 = game_new_ext(DEFAULT_SIZE, DEFAULT_SIZE, squares_2, false, false);
    if (!g1 || !g2)
        return false;

    for (uint i = 0; i < DEFAULT_SIZE; i++) {
        for (uint j = 0; j < DEFAULT_SIZE; j++) {
            if (game_has_error(g1, i, j) || !game_has_error(g2, i, j)) {
                game_delete(g1);
                game_delete(g2);
                return false;
            }
        }
    }
    game_delete(g1);
    game_delete(g2);

    square squares_4[DEFAULT_SIZE * DEFAULT_SIZE] = {2, 4, 3, 1, 1, 2, 2, 4, 3, 1, 1, 2, 2, 4, 3, 1, 1, 2,
                                                     2, 4, 3, 1, 1, 2, 2, 4, 3, 1, 1, 2, 2, 4, 3, 1, 1, 2};
    game g4 = game_new_ext(DEFAULT_SIZE, DEFAULT_SIZE, squares_4, false, true);
    for (uint i = 0; i < DEFAULT_SIZE; i++) {
        for (uint j = 0; j < DEFAULT_SIZE; j++) {
            if (!game_has_error(g4, i, j)) {
                game_delete(g4);
                return false;
            }
        }
    }
    game_delete(g4);
    return true;
}

bool test_game_check_move() {
    square squares[DEFAULT_SIZE * DEFAULT_SIZE] = {0, 4, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 3, 0,
                                                   0, 3, 4, 0, 0, 0, 0, 0, 4, 0, 0, 3, 0, 0, 0, 0, 0, 3};
    game g = game_new_ext(DEFAULT_SIZE, DEFAULT_SIZE, squares, false, false);

    if (!g)
        return false;
    for (uint i = 0; i < DEFAULT_SIZE; i++) {
        for (uint j = 0; j < DEFAULT_SIZE; j++) {
            if (game_check_move(g, i, j, S_EMPTY) &&
                (game_get_square(g, i, j) == S_IMMUTABLE_ONE || game_get_square(g, i, j) == S_IMMUTABLE_ZERO)) {
                game_delete(g);
                return false;
            } else if (!(game_check_move(g, i, j, S_EMPTY)) &&
                       (game_get_square(g, i, j) != S_IMMUTABLE_ONE && game_get_square(g, i, j) != S_IMMUTABLE_ZERO)) {
                game_delete(g);
                return false;
            }
        }
    }
    game_delete(g);
    return true;
}

bool test_game_play_move() {
    square squares[DEFAULT_SIZE * DEFAULT_SIZE] = {0, 4, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 3, 0,
                                                   0, 3, 4, 0, 0, 0, 0, 0, 4, 0, 0, 3, 0, 0, 0, 0, 0, 3};
    game g = game_new_ext(DEFAULT_SIZE, DEFAULT_SIZE, squares, false, false);

    if (!g)
        return (false);
    square q;
    for (uint i = 0; i < DEFAULT_SIZE; i++) {
        for (uint j = 0; j < DEFAULT_SIZE; j++) {
            q = game_get_square(g, i, j);
            if (q == S_IMMUTABLE_ONE || q == S_IMMUTABLE_ZERO) {
                break;
            } else {
                game_play_move(g, i, j, S_ONE);
            }
            if ((q == S_IMMUTABLE_ONE || q == S_IMMUTABLE_ZERO) && q != game_get_square(g, i, j)) {
                game_delete(g);
                return false;
            }
            if ((q != S_IMMUTABLE_ONE && q != S_IMMUTABLE_ZERO) && q == game_get_square(g, i, j)) {
                game_delete(g);
                return false;
            }
        }
    }
    game_delete(g);
    return true;
}

bool test_game_is_over() {
    game g1 = game_default_solution();
    square squares_2[DEFAULT_SIZE * DEFAULT_SIZE] = {1, 1, 2, 2, 3, 3, 4, 4, 1, 1, 2, 2, 3, 3, 4, 4, 1, 1,
                                                     2, 2, 3, 3, 4, 4, 1, 1, 2, 2, 3, 3, 4, 4, 1, 1, 2, 2};
    game g2 = game_new_ext(DEFAULT_SIZE, DEFAULT_SIZE, squares_2, false, false);
    square squares_3[DEFAULT_SIZE * DEFAULT_SIZE] = {1, 1, 1, 2, 2, 2, 1, 1, 1, 2, 2, 2, 1, 1, 1, 2, 2, 2,
                                                     4, 4, 4, 3, 3, 3, 4, 4, 4, 3, 3, 3, 4, 4, 4, 3, 3, 3};
    game g3 = game_new_ext(DEFAULT_SIZE, DEFAULT_SIZE, squares_3, false, false);
    square squares_4[DEFAULT_SIZE * DEFAULT_SIZE] = {1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4, 2, 3, 4, 1, 2, 3,
                                                     4, 1, 2, 3, 4, 1, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4, 1, 2};
    game g4 = game_new_ext(DEFAULT_SIZE, DEFAULT_SIZE, squares_4, false, false);
    square squares_5[DEFAULT_SIZE * DEFAULT_SIZE] = {0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1,
                                                     1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0};
    game g5 = game_new_ext(DEFAULT_SIZE, DEFAULT_SIZE, squares_5, false, false);

    if (!g1 || !g2 || !g3 || !g4 || !g5)
        return false;

    if (!game_is_over(g1) || game_is_over(g2) || game_is_over(g3) || game_is_over(g4) || game_is_over(g5)) {
        game_delete(g1);
        game_delete(g2);
        game_delete(g3);
        game_delete(g4);
        game_delete(g5);
        return false;
    }
    game_delete(g1);
    game_delete(g2);
    game_delete(g3);
    game_delete(g4);
    game_delete(g5);
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
    if (strcmp("game_new", argv[1]) == 0)
        pass = test_game_new();
    else if (strcmp("game_new_empty", argv[1]) == 0)
        pass = test_game_new_empty();
    else if (strcmp("game_copy", argv[1]) == 0)
        pass = test_game_copy();
    else if (strcmp("game_equal", argv[1]) == 0)
        pass = test_game_equal();
    else if (strcmp("game_delete", argv[1]) == 0)
        pass = test_game_delete();
    else if (strcmp("game_is_empty", argv[1]) == 0)
        pass = test_game_is_empty();
    else if (strcmp("game_restart", argv[1]) == 0)
        pass = test_game_restart();
    else if (strcmp("game_set_square", argv[1]) == 0)
        pass = test_game_set_square();
    else if (strcmp("game_get_square", argv[1]) == 0)
        pass = test_game_get_square();
    else if (strcmp("game_get_number", argv[1]) == 0)
        pass = test_game_get_number();
    else if (strcmp("game_get_next_square", argv[1]) == 0)
        pass = test_game_get_next_square();
    else if (strcmp("game_get_next_number", argv[1]) == 0)
        pass = test_game_get_next_number();
    else if (strcmp("game_is_immutable", argv[1]) == 0)
        pass = test_game_is_immutable();
    else if (strcmp("game_has_error", argv[1]) == 0)
        pass = test_game_has_error();
    else if (strcmp("game_check_move", argv[1]) == 0)
        pass = test_game_check_move();
    else if (strcmp("game_play_move", argv[1]) == 0)
        pass = test_game_play_move();
    else if (strcmp("game_is_over", argv[1]) == 0)
        pass = test_game_is_over();
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