#include "takuzu.h"

bool test_solver_new() { return false; }

bool test_solver_delete() { return false; }

bool test_find_solutions() { return false; }

bool test_is_word_solution() { return false; }

bool test_copy_word() { return false; }

bool test_print_word() { return false; }

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
    if (strcmp("solver_new", argv[1]) == 0)
        pass = test_solver_new();
    else if (strcmp("solver_delete", argv[1]) == 0)
        pass = test_solver_delete();
    else if (strcmp("find_solutions", argv[1]) == 0)
        pass = test_find_solutions();
    else if (strcmp("is_word_solution", argv[1]) == 0)
        pass = test_is_word_solution();
    else if (strcmp("copy_word", argv[1]) == 0)
        pass = test_copy_word();
    else if (strcmp("print_word", argv[1]) == 0)
        pass = test_print_word();
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