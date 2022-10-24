#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include "game.h"
#include "game_aux.h"

bool test_dummy(int argc, char *argv[])
{
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
    if (strcmp("dummy", argv[1]) == 0)
        ok = test_dummy(argc, argv);
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