#include "takuzu.h"

bool test_is_unique_array() {
    bool pass = true;
    square array1[4 * 4] = {1, 3, 2, 2, 1, 1, 2, 4, 1, 4, 1, 3, 3, 2, 1, 4};
    square array2[4 * 4] = {1, 0, 0, 3, 4, 0, 0, 2, 2, 0, 0, 4, 1, 0, 0, 3};
    square array3[4 * 4] = {1, 4, 2, 3, 2, 1, 1, 2, 4, 4, 1, 3, 1, 3, 4, 2};
    game g1 = game_new_ext(4, 4, array1, true, false);
    game g2 = game_new_ext(4, 4, array2, true, false);
    game g3 = game_new_ext(4, 4, array3, true, false);
    if (is_unique_array(g1, 0, 0))
        pass = false;
    if (is_unique_array(g2, 0, 0))
        pass = false;
    if (!is_unique_array(g3, 0, 0))
        pass = false;
    game_delete(g1);
    game_delete(g2);
    game_delete(g3);
    return pass;
}

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

bool test_is_consecutive_grid() {
    bool pass = true;
    square square_1[4 * 4] = {3, 1, 1, 2, 4, 3, 2, 1, 4, 2, 3, 1, 1, 2, 2, 2};
    game g1 = game_new_ext(DEFAULT_SIZE, DEFAULT_SIZE, square_1, false, false);
    square square_2[4 * 4] = {1, 1, 2, 3, 2, 1, 2, 1, 2, 2, 1, 1, 1, 2, 2, 2};
    game g2 = game_new_ext(DEFAULT_SIZE, DEFAULT_SIZE, square_2, false, false);
    square square_3[DEFAULT_SIZE * DEFAULT_SIZE] = {1, 4, 3, 2, 2, 1, 2, 1, 2, 1, 3, 4, 2, 1, 1, 2, 2, 1,
                                                    2, 1, 3, 4, 4, 1, 1, 2, 3, 1, 3, 2, 3, 3, 2, 1, 4, 2};
    game g3 = game_new_ext(DEFAULT_SIZE, DEFAULT_SIZE, square_3, false, false);
    square square_4[DEFAULT_SIZE * DEFAULT_SIZE] = {1, 4, 3, 2, 1, 2, 1, 2, 2, 1, 2, 1, 2, 3, 1, 2, 3, 2,
                                                    2, 3, 4, 1, 1, 2, 1, 2, 4, 1, 2, 3, 2, 1, 1, 2, 2, 3};
    game g4 = game_new_ext(DEFAULT_SIZE, DEFAULT_SIZE, square_4, false, false);
    if (!is_consecutive_grid(g1, 0, 0))
        pass = false;
    if (!is_consecutive_grid(g2, 0, 0))
        pass = false;
    if (!is_consecutive_grid(g3, 0, 0))
        pass = false;
    if (is_consecutive_grid(g4, 0, 0))
        pass = false;
    game_delete(g1);
    game_delete(g2);
    game_delete(g3);
    game_delete(g4);
    return pass;
}

bool test_is_consecutive() {
    bool pass = true;
    square square_1[DEFAULT_SIZE] = {1, 1, 3, 2, 4, 3};
    game g1 = game_new_ext(1, DEFAULT_SIZE, square_1, false, false);
    square square_2[DEFAULT_SIZE] = {4, 2, 4, 1, 2, 3};
    game g2 = game_new_ext(1, DEFAULT_SIZE, square_2, false, false);
    square square_3[DEFAULT_SIZE] = {1, 1, 2, 2, 1, 1};
    game g3 = game_new_ext(1, DEFAULT_SIZE, square_3, false, false);
    square square_4[DEFAULT_SIZE] = {1, 3, 2, 4, 1, 2};
    game g4 = game_new_ext(1, DEFAULT_SIZE, square_4, false, false);
    if (!is_consecutive(square_1, DEFAULT_SIZE, game_get_number(g1, 0, 0)))
        pass = false;
    if (!is_consecutive(square_2, DEFAULT_SIZE, game_get_number(g2, 0, 0)))
        pass = false;
    if (!is_consecutive(square_3, DEFAULT_SIZE, game_get_number(g3, 0, 0)))
        pass = false;
    if (is_consecutive(square_4, DEFAULT_SIZE, game_get_number(g4, 0, 0)))
        pass = false;
    game_delete(g1);
    game_delete(g2);
    game_delete(g3);
    game_delete(g4);
    return pass;
}

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
    if (!is_array_same(col_0, square_2, 2))
        pass = false;
    if (!is_array_same(col_1, square_3, 2))
        pass = false;
    if (is_array_same(col_0, square_4, 2))
        pass = false;
    if (is_array_same(col_1, square_4, 2))
        pass = false;
    free(col_0);
    free(col_1);
    game_delete(g);
    return pass;
}

bool test_get_row() {
    bool pass = true;
    square square_1[DEFAULT_SIZE * 2] = {1, 2, 1, 1, 2, 1, 3, 4, 3, 4, 3, 4};
    game g = game_new_ext(2, DEFAULT_SIZE, square_1, true, false);
    square square_2[DEFAULT_SIZE] = {1, 2, 1, 1, 2, 1};
    square square_3[DEFAULT_SIZE] = {3, 4, 3, 4, 3, 4};
    square square_4[DEFAULT_SIZE] = {1, 2, 3, 1, 2, 0};
    square *row_0 = get_row(g, 0);
    square *row_1 = get_row(g, 1);
    if (!is_array_same(row_0, square_2, 6))
        pass = false;
    if (!is_array_same(row_1, square_3, 6))
        pass = false;
    if (is_array_same(row_0, square_4, 6))
        pass = false;
    if (is_array_same(row_1, square_4, 6))
        pass = false;
    free(row_0);
    free(row_1);
    game_delete(g);
    return pass;
}

bool test_is_array_full() {
    bool pass = true;
    square array1[DEFAULT_SIZE] = {1, 2, 3, 1, 2, 3};
    square array2[DEFAULT_SIZE] = {1, 0, 3, 1, 2, 3};
    if (!is_array_full(array1, DEFAULT_SIZE))
        pass = false;
    if (is_array_full(array2, DEFAULT_SIZE))
        pass = false;
    return pass;
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
    if (strcmp("is_unique_array", argv[1]) == 0)
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
    else if (strcmp("is_array_full", argv[1]) == 0)
        pass = test_is_array_full();
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