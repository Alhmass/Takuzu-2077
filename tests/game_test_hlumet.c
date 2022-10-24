#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include "game.h"
#include "game_aux.h"

bool test_game_set_square()
{
    game g = game_default();

    if (!g)
        return (false);
    game_set_square(g, 0, 0, S_ZERO);
    if (game_get_square(g, 0, 0) != S_ZERO) {
        game_delete(g);
        return (false);
    }
    game_delete(g);
    return (true);
}

void usage(int argc, char *argv[])
{
  fprintf(stderr, "Usage: %s <testname> [<...>]\n", argv[0]);
  exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
    if (argc == 1)
        usage(argc, argv);
    // start test
    fprintf(stderr, "=> Start test \"%s\"\n", argv[1]);
    bool ok = false;
    if (strcmp("game_set_square", argv[1]) == 0)
        ok = test_game_set_square();
    else {
        fprintf(stderr, "Test not found!\n");
        exit(EXIT_FAILURE);
    }
    // print test result
    if (ok) {
        fprintf(stderr, "Test \"%s\" finished: SUCCESS\n", argv[1]);
        return (EXIT_SUCCESS);
    }
    else {
        fprintf(stderr, "Test \"%s\" finished: FAILURE\n", argv[1]);
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}