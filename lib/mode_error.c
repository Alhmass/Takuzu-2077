#include "takuzu.h"

void print_array(square *array, uint size) {
    for (uint i = 0; i < size; i++) {
        printf("[%d] ", array[i]);
    }
    printf("\n");
}

square *get_row(cgame g, uint i) {
    cgame_test(g, "g is NULL");
    uint cols_g = (g->version == 1) ? DEFAULT_SIZE : game_nb_cols(g);
    // row: array of squares that will contain the row
    square *row = malloc(sizeof(square) * cols_g);
    pointer_test(row, "malloc failed");
    for (uint j = 0; j < cols_g; j++) row[j] = game_get_square(g, i, j);
    return row;
}

square *get_col(cgame g, uint j) {
    cgame_test(g, "g is NULL");
    uint rows_g = (g->version == 1) ? DEFAULT_SIZE : game_nb_rows(g);
    // col: array of squares that will contain the column
    square *col = malloc(sizeof(square) * rows_g);
    pointer_test(col, "malloc failed");
    for (uint i = 0; i < rows_g; i++) {
        col[i] = game_get_square(g, i, j);
    }
    return col;
}

void rotate_array(square *array, uint size) {
    pointer_test(array, "array is NULL");
    // start: first element of the array
    square start = array[0];
    for (uint i = 0; i < size - 1; i++) array[i] = array[i + 1];
    array[size - 1] = start;
}

int get_number(square s) {
    if (s == S_EMPTY)
        return -1;
    if (s == S_ZERO || s == S_IMMUTABLE_ZERO)
        return 0;
    if (s == S_ONE || s == S_IMMUTABLE_ONE)
        return 1;
    // invalid square: should never happen
    return -1;
}

bool is_consecutive(square *array, uint size, int current) {
    // current: the square that is currently verified by has_error
    if (current == -1)
        return false;

    // consecutive: number of consecutive squares of the same value as current
    uint consecutive = 0;
    // current_counter: number of squares of the same value as current on the array
    uint current_counter = 0;
    for (uint i = 0; i < size; i++) {
        if (get_number(array[i]) == current) {
            current_counter++;
            if (current_counter > size / 2)
                return true;
            consecutive++;
            if (consecutive >= 3)
                return true;
        } else {
            consecutive = 0;
        }
    }
    return false;
}

bool is_consecutive_grid(cgame g, uint i, uint j) {
    // tabRows: array of squares that contains the row i
    square *tabRows = get_row(g, i);
    // rows_g: number of rows of the grid
    uint rows_g = (g->version == 1) ? DEFAULT_SIZE : game_nb_rows(g);
    // cols_g: number of columns of the grid
    uint cols_g = (g->version == 1) ? DEFAULT_SIZE : game_nb_cols(g);

    for (uint x = 0; x < cols_g; x++) {
        rotate_array(tabRows, cols_g);
        if (is_consecutive(tabRows, cols_g, game_get_number(g, i, j))) {
            free(tabRows);
            return true;
        }
    }
    free(tabRows);

    // tabCols: array of squares that contains the column j
    square *tabCols = get_col(g, j);

    for (uint y = 0; y < rows_g; y++) {
        rotate_array(tabCols, rows_g);
        if (is_consecutive(tabCols, rows_g, game_get_number(g, i, j))) {
            free(tabCols);
            return true;
        }
    }
    free(tabCols);
    return false;
}

bool is_array_same(square *array1, square *array2, uint size) {
    for (uint i = 0; i < size; i++) {
        if (get_number(array1[i]) != get_number(array2[i]))
            return false;
    }
    return true;
}

bool is_array_full(square *array, uint size) {
    for (uint i = 0; i < size; i++) {
        if (get_number(array[i]) == -1)
            return false;
    }
    return true;
}

bool is_unique_array(cgame g, uint i, uint j) {
    uint rows_g = (g->version == 1) ? DEFAULT_SIZE : game_nb_rows(g);
    uint cols_g = (g->version == 1) ? DEFAULT_SIZE : game_nb_cols(g);
    // row_i: array of squares that contains the row i
    square *row_i = get_row(g, i);
    if (is_array_full(row_i, cols_g)) {
        // if the row is full, we check if there is another row that is the same
        for (uint x = 0; x < rows_g; x++) {
            // we don't check the row x = i (it's the same, is_array_same would return true)
            if (x != i) {
                // row_x: array of squares that contains the row x
                square *row_x = get_row(g, x);
                if (is_array_full(row_x, cols_g)) {
                    if (is_array_same(row_i, row_x, cols_g)) {
                        free(row_x);
                        free(row_i);
                        return false;
                    }
                }
                free(row_x);
            }
        }
    }
    free(row_i);

    // col_j: array of squares that contains the column j
    square *col_j = get_col(g, j);
    if (is_array_full(col_j, rows_g)) {
        for (uint y = 0; y < cols_g; y++) {
            // we don't check the column y = j (it's the same, is_array_same would return true)
            if (y != j) {
                // col_y: array of squares that contains the column y
                square *col_y = get_col(g, y);
                if (is_array_full(col_y, rows_g)) {
                    if (is_array_same(col_j, col_y, rows_g)) {
                        free(col_y);
                        free(col_j);
                        return false;
                    }
                }
                free(col_y);
            }
        }
    }
    free(col_j);
    return true;
}