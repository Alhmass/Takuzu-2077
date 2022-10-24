#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "game.h"
#include "game_aux.h"

/*  TEST  */
bool test_game_new(void) {
    square *squares = {S_ZERO};
    game g = game_new(squares);
    if (g == NULL)
        return false;
    return true;
}

bool test_game_new_empty(void) {
    return false;
}

bool test_game_copy(cgame g) {
    return false;
}

bool test_game_equal(cgame g1, cgame g2) {
    return false;
}

bool test_game_delete(game g) {
    return false;
}

bool test_game_is_empty(cgame g, uint i, uint j) {
    return false;
}

bool test_game_restart(game g) {
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
        ok = test_game_new_empty();
    else if (strcmp("game_new_empty", argv[1]) == 0)
        ok = test_game_new_empty();
    else if (strcmp("game_copy", argv[1]) == 0)
        ok = test_game_new_empty();
    else if (strcmp("game_equal", argv[1]) == 0)
        ok = test_game_new_empty();
    else if (strcmp("game_delete", argv[1]) == 0)
        ok = test_game_new_empty();
    else if (strcmp("game_is_empty", argv[1]) == 0)
        ok = test_game_new_empty();
    else if (strcmp("game_restart", argv[1]) == 0)
        ok = test_game_new_empty();
    else {
        fprintf(stderr, "Error: test \"%s\" not found!\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    if (!ok) {
        fprintf(stderr, "Test \"%s\" finished: SUCCESS\n", argv[1]);
        return EXIT_SUCCESS;
    } else {
        fprintf(stderr, "Test \"%s\" finished: FAILURE\n", argv[1]);
        return EXIT_FAILURE;
    }
}
