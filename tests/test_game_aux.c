#include "takuzu.h"

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

bool test_game_print(void) {
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
    if (strcmp("game_default", argv[1]) == 0)
        pass = test_game_default();
    else if (strcmp("game_default_solution", argv[1]) == 0)
        pass = test_game_default_solution();
    else if (strcmp("game_print", argv[1]) == 0)
        pass = test_game_print();
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