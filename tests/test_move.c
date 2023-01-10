#include "takuzu.h"

bool test_move_create() {
    return false;
}

bool test_move_delete() {
    return false;
}

bool test_move_row() {
    return false;
}

bool test_move_col() {
    return false;
}

bool test_move_s() {
    return false;
}

bool test_move_p() {
    return false;
}

bool test_move_print() {
    return false;
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
    if (strcmp("move_create", argv[1]) == 0)
        pass = test_move_create();
    else if (strcmp("move_delete", argv[1]) == 0)
        pass = test_move_delete();
    else if (strcmp("move_row", argv[1]) == 0)
        pass = test_move_row();
    else if (strcmp("move_col", argv[1]) == 0)
        pass = test_move_col();
    else if (strcmp("move_s", argv[1]) == 0)
        pass = test_move_s();
    else if (strcmp("move_p", argv[1]) == 0)
        pass = test_move_p();
    else if (strcmp("", argv[1]) == 0)
        pass = test_move_print();
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