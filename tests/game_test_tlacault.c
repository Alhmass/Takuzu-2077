#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "game.h"
#include "game_aux.h"

/*  TEST  */
bool test_game_new(void) {
    int squares[DEFAULT_SIZE][DEFAULT_SIZE] = {
        {0, 2, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 1, 0},
        {0, 1, 2, 0, 0, 0},
        {0, 0, 2, 0, 0, 1},
        {0, 0, 0, 0, 0, 1}};
    game g = game_new((square *)squares);
    if (g == NULL)
        return false;
    return true;
}

bool test_game_new_empty(void) {
    game g = game_new_empty();
    for (uint i = 0; i < DEFAULT_SIZE; i++)
        for (uint j = 0; j < DEFAULT_SIZE; j++)
            if (game_get_square(g, i, j) != 0)
                return false;
    return true;
}

bool test_game_copy(void) {
    // cgame g
    return false;
}

bool test_game_equal(void) {
    // cgame g1, cgame g2
    return false;
}

bool test_game_delete(void) {
    // game g
    return false;
}

bool test_game_is_empty(void) {
    // cgame g, uint i, uint j
    return false;
}

bool test_game_restart(void) {
    // game g
    return false;
}

/*  USAGE  */
void usage(int argc, char *argv[]) {
    fprintf(stderr, "Usage: %s <testname> [<...>]\n", argv[0]);
    exit(EXIT_FAILURE);
}

/*  MAIN ROUTINE  */
int main(int argc, char *argv[]) {
    if (argc == 1)
        usage(argc, argv);

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
