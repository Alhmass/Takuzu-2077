#include "takuzu.h"

bool test_new_ext() {
    return true;
}

bool test_new_empty_ext() {
    return true;
}

bool test_equal_ext() {
    return true;
}

bool test_copy_ext() {
    return true;
}

bool test_get_next_square_wrapping() {
    return true;
}

bool test_get_next_number_wrapping() {
    return true;
}

bool test_has_error_wrapping() {
    return true;
}

bool test_is_over_wrapping() {
    return true;
}

bool test_has_error_unique() {
    return true;
}

bool test_is_over_unique() {
    return true;
}

bool test_undo_one() {
    return true;
}

bool test_undo_redo_some() {
    return true;
}

bool test_undo_redo_all() {
    return true;
}

bool test_restart_undo() {
    return true;
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
    if (strcmp("new_ext", argv[1]) == 0)
        pass = test_new_ext();
    else if (strcmp("new_empty_ext", argv[1]) == 0)
        pass = test_new_empty_ext();
    else if (strcmp("equal_ext", argv[1]) == 0)
        pass = test_equal_ext();
    else if (strcmp("copy_ext", argv[1]) == 0)
        pass = test_copy_ext();
    else if (strcmp("get_next_square_wrapping", argv[1]) == 0)
        pass = test_get_next_square_wrapping();
    else if (strcmp("get_next_number_wrapping", argv[1]) == 0)
        pass = test_get_next_number_wrapping();
    else if (strcmp("has_error_wrapping", argv[1]) == 0)
        pass = test_has_error_wrapping();
    else if (strcmp("is_over_wrapping", argv[1]) == 0)
        pass = test_is_over_wrapping();
    else if (strcmp("has_error_unique", argv[1]) == 0)
        pass = test_has_error_unique();
    else if (strcmp("is_over_unique", argv[1]) == 0)
        pass = test_is_over_unique();
    else if (strcmp("undo_one", argv[1]) == 0)
        pass = test_undo_one();
    else if (strcmp("undo_redo_some", argv[1]) == 0)
        pass = test_undo_redo_some();
    else if (strcmp("undo_redo_all", argv[1]) == 0)
        pass = test_undo_redo_all();
    else if (strcmp("restart_undo", argv[1]) == 0)
        pass = test_restart_undo();
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
