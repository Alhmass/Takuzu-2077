#include "takuzu.h"

bool test_game_has_error() {
    return false;
}

bool test_is_unique_array() {
    return false;
}

bool test_is_array_same() {
    return false;
}

bool test_is_consecutive_grid() {
    return false;
}

bool test_is_consecutive() {
    return false;
}

bool test_get_number() {
    return false;
}

bool test_rotate_array() {
    return false;
}

bool test_get_col() {
    return false;
}

bool test_get_row() {
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
    if (strcmp("game_has_error", argv[1]) == 0)
        pass = test_game_has_error();
    else if (strcmp("is_unique_array", argv[1]) == 0)
        pass = test_is_unique_array();
    else if (strcmp("is_array_same", argv[1]) == 0)
        pass = test_is_array_same();
    else if (strcmp("is_consecutive_grid", argv[1]) == 0)
        pass = test_is_consecutive_grid();
    else if (strcmp("is_consecutive", argv[1]) == 0)
        pass = test_is_consecutive();
    else if (strcmp("get_number", argv[1]) == 0)
        pass = test_get_number();
    else if (strcmp("rotate_array", argv[1]) == 0)
        pass = test_rotate_array();
    else if (strcmp("get_col", argv[1]) == 0)
        pass = test_get_col();
    else if (strcmp("get_row", argv[1]) == 0)
        pass = test_get_row();
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