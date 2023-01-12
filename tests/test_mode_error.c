#include "takuzu.h"

bool test_game_has_error() { return false; }

bool test_is_unique_array() { return false; }

bool test_is_array_same() {
    bool pass = true;
    square array1[6] = {1, 1, 1, 1, 1, 1};
    square array2[6] = {1, 3, 1, 3, 1, 3};
    square array3[6] = {2, 2, 2, 2, 2, 2};
    square array4[6] = {2, 4, 4, 4, 2, 2};
    if (!is_array_same(array1, array2, 6))
        pass = false;
    if (is_array_same(array1, array3, 6))
        pass = false;
    if (is_array_same(array2, array3, 6))
        pass = false;
    if (is_array_same(array1, array4, 6))
        pass = false;
    if (!is_array_same(array3, array4, 6))
        pass = false;
    return pass;
}

bool test_is_consecutive_grid() { return false; }

bool test_is_consecutive() { return false; }

bool test_get_number() {
    bool pass = true;
    square a = S_ONE;
    square b = S_ZERO;
    square c = S_IMMUTABLE_ONE;
    square d = S_IMMUTABLE_ZERO;
    square e = S_EMPTY;
    if (get_number(e) != -1 || (get_number(a) != 1 || get_number(c) != 1) ||
        (get_number(b) != 0 || get_number(d) != 0)) {
        pass = false;
    }
    return pass;
}

bool test_rotate_array() {
    bool pass = true;
    square array[6] = {1, 3, 1, 3, 1, 3};
    square array2[6] = {1, 3, 1, 3, 1, 3};
    rotate_array(array2, 6);
    square array3[6] = {3, 1, 3, 1, 3, 1};
    square array4[6] = {1, 3, 1, 3, 1, 3};
    print_array(array, 6);
    print_array(array2, 6);
    print_array(array3, 6);
    if (!is_array_same(array, array2, 6))
        pass = false;
    if (!is_array_same(array2, array3, 6))
        pass = false;
    for (uint i = 0; i < DEFAULT_SIZE; i++) {
        rotate_array(array4, 6);
    }
    if (!is_array_same(array, array4, 6))
        pass = false;
    return pass;
}

bool test_get_col() {
    bool pass = true;
    square square_1[DEFAULT_SIZE * 2] = {1, 2, 1, 1, 2, 1, 3, 4, 3, 4, 3, 4};
    game g = game_new_ext(DEFAULT_SIZE, 2, square_1, false, false);
    square square_2[DEFAULT_SIZE] = {1, 1, 2, 3, 3, 3};
    square square_3[DEFAULT_SIZE] = {2, 1, 1, 4, 4, 4};
    square square_4[DEFAULT_SIZE] = {3, 2, 1, 3, 2, 1};
    square *col_0 = get_col(g, 0);
    square *col_1 = get_col(g, 1);
    print_array(col_0, 6);
    print_array(col_1, 6);


    if (!is_array_same(col_0, square_2, 2))
        pass = false;
    printf("pass: %d\n", pass);
    if (!is_array_same(col_1, square_3, 2))
        pass = false;
    printf("pass: %d\n", pass);
    if (is_array_same(col_0, square_4, 2))
        pass = false;
    printf("pass: %d\n", pass);
    if (is_array_same(col_1, square_4, 2))
        pass = false;
    printf("pass: %d\n", pass);

    free(col_0);
    free(col_1);
    game_delete(g);
    return pass;
}

bool test_get_row() {
    bool pass = false; 
    square square_1[DEFAULT_SIZE * 2] = {1, 2, 1, 1, 2, 1, 3, 4, 3, 4, 3, 4};
    game g = game_new_ext(2, DEFAULT_SIZE, square_1, true, false);
    square square_2[DEFAULT_SIZE] = {1, 2, 1, 1, 2, 1};
    square square_3[DEFAULT_SIZE] = {3, 4, 3, 4, 3, 4};
    square square_4[DEFAULT_SIZE] = {1, 2, 3, 1, 2, 0};
    square *col_0 = get_row(g, 0);
    square *col_1 = get_row(g, 1);
    if (!is_array_same(col_0, ))
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