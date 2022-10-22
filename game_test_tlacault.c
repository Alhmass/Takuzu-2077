/*
  ╭────────────────────────────────────────────────────────╮
    > File:           game_test_tlacault.c
    > Created Date:   22-10-2022 15:10
    > Author:         Tim Lacault
    ──────────────────────────────────────────────────────
    > Last Modified:  22-10-2022 15:10
    > Modified By:    Tim Lacault
    ──────────────────────────────────────────────────────
    > Description:
  ╰────────────────────────────────────────────────────────╯
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*  TEST  */
bool test_dummy(void) {
    return (EXIT_SUCCESS);
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
    if (strcmp("dummy", argv[1]) == 0)
        ok = test_dummy();
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
