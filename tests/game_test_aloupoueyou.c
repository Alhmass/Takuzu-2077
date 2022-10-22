#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void usage(int argc, char* argv[]) {
    fprintf(stderr, "Usage: %s <testname> [<...>]\n", argv[0]);
    exit(EXIT_FAILURE);
}

int main(int argc, char* argv[]) {
    if (argc == 1)
        usage(argc, argv);
    bool ok = false;
    if (strcmp(argv[1], "dummy") == 0)
        ok = true;

    //Print test result
    if (ok) {
        fprintf(stderr, "Test: \"%s\" finished: SUCCESS\n", argv[1]);
        return EXIT_SUCCESS;
    } else {
        fprintf(stderr, "Test: \"%s\" finished: FAILURE\n", argv[1]);
        return EXIT_FAILURE;
    }
}