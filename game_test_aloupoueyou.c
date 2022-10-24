#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "game_aux.h"
#include "game.h"

void usage(int argc, char *argv[]) {
    fprintf(stderr, "Usage: %s <testname> [<...>]\n", argv[0]);
    exit(EXIT_FAILURE);
}

bool test_dummy() {
    return true;
}

int main(int argc, char *argv[]) {
    if (argc == 1)
        usage(argc, argv);
    if (strcmp(argv[1], "dummy") == 0) {
        if (test_dummy()) {
            fprintf(stderr, "Test: \"%s\" finished: SUCCESS\n", argv[1]);
            return EXIT_SUCCESS;
        }
    }
    fprintf(stderr, "Test: \"%s\" finished: FAILURE\n", argv[1]);
    return EXIT_FAILURE;
}