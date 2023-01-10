#include "takuzu.h"

bool test_ms_create() {
    return false;
}

bool test_ms_delete() {
    return false;
}

bool test_ms_double_capacity() {
    return false;
}

bool test_ms_top() {
    return false;
}

bool test_ms_push() {
    return false;
}

bool test_ms_pop() {
    return false;
}

bool test_ms_clear() {
    return false;
}

bool test_ms_top_row() {
    return false;
}

bool test_ms_top_col() {
    return false;
}

bool test_ms_top_s() {
    return false;
}

bool test_ms_top_p() {
    return false;
}

bool test_ms_is_empty() {
    return false;
}

bool test_ms_is_full() {
    return false;
}

bool test_ms_print() {
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
    if (strcmp("ms_create", argv[1]) == 0)
        pass = test_ms_create();
    else if (strcmp("ms_delete", argv[1]) == 0)
        pass = test_ms_delete();
    else if (strcmp("ms_double_capacity", argv[1]) == 0)
        pass = test_ms_double_capacity();
    else if (strcmp("ms_top", argv[1]) == 0)
        pass = test_ms_top();
    else if (strcmp("ms_push", argv[1]) == 0)
        pass = test_ms_push();
    else if (strcmp("ms_pop", argv[1]) == 0)
        pass = test_ms_pop();
    else if (strcmp("ms_clear", argv[1]) == 0)
        pass = test_ms_clear();
    else if (strcmp("ms_top_row", argv[1]) == 0)
        pass = test_ms_top_row();
    else if (strcmp("ms_top_col", argv[1]) == 0)
        pass = test_ms_top_col();
    else if (strcmp("ms_top_s", argv[1]) == 0)
        pass = test_ms_top_s();
    else if (strcmp("ms_top_p", argv[1]) == 0)
        pass = test_ms_top_p();
    else if (strcmp("ms_is_empty", argv[1]) == 0)
        pass = test_ms_is_empty();
    else if (strcmp("ms_is_full", argv[1]) == 0)
        pass = test_ms_is_full();
    else if (strcmp("ms_print", argv[1]) == 0)
        pass = test_ms_print();
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