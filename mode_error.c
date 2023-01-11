#include "takuzu.h"

square *get_row(cgame g, uint i) {
    cgame_test(g, "g is NULL");
    uint cols_g = (g->version == 1) ? DEFAULT_SIZE : game_nb_cols(g);
    square *row = malloc(sizeof(square) * cols_g);
    pointer_test(row, "malloc failed");
    for (uint j = 0; j < cols_g; j++) row[j] = game_get_square(g, i, j);
    return row;
}

square *get_col(cgame g, uint j) {
    cgame_test(g, "g is NULL");
    uint rows_g = (g->version == 1) ? DEFAULT_SIZE : game_nb_rows(g);
    square *col = malloc(sizeof(square) * rows_g);
    pointer_test(col, "malloc failed");
    for (uint i = 0; i < rows_g; i++) col[i] = game_get_square(g, i, j);
    return col;
}

void rotate_array(square *array, uint size) {
    pointer_test(array, "array is NULL");
    square start = array[0];
    for (uint i = 0; i < size - 1; i++) array[i] = array[i + 1];
    array[size - 1] = start;
}

int get_number(int s) {
    if (s == 0) {
        return -1;
    } else if (s == 1 || s == 3) {
        return 0;
    }
    return 1;
}

bool is_consecutive(square *array, uint size, int current) {
    if (current == -1)
        return false;

    uint consecutive = 0;
    uint current_counter = 0;
    for (uint i = 0; i < size; i++) {
        if (get_number(array[i]) == current) {
            if (++current_counter > (size / 2) + (size % 2)) {
                return true;
            }
            if (++consecutive >= size / 2) {
                return true;
            }
        } else
            consecutive = 0;
    }
    return false;
}

bool is_consecutive_grid(cgame g, uint i, uint j) {
    square *tabRows = get_row(g, i);
    uint rows_g = (g->version == 1) ? DEFAULT_SIZE : game_nb_rows(g);
    uint cols_g = (g->version == 1) ? DEFAULT_SIZE : game_nb_cols(g);
    for (uint x = 0; x < cols_g; x++) {
        rotate_array(tabRows, cols_g);
        if (is_consecutive(tabRows, cols_g, game_get_number(g, i, j))) {
            return true;
        }
    }
    free(tabRows);
    square *tabCols = get_col(g, j);
    for (uint y = 0; y < rows_g; y++) {
        rotate_array(tabCols, rows_g);
        if (is_consecutive(tabCols, rows_g, game_get_number(g, i, j))) {
            return true;
        }
    }
    free(tabCols);
    return false;
}

bool is_array_same(square *array1, square *array2, uint size) {
    for (uint i = 0; i < size; i++) {
        if (get_number(array1[i]) != get_number(array2[i]) || get_number(array1[i]) == -1 ||
            get_number(array2[i]) == -1) {
            return false;
        }
    }
    return true;
}

bool is_unique_array(cgame g, uint i, uint j) {
    uint rows_g = (g->version == 1) ? DEFAULT_SIZE : game_nb_rows(g);
    uint cols_g = (g->version == 1) ? DEFAULT_SIZE : game_nb_cols(g);
    for (uint x = 0; x < rows_g; x++) {
        if (x != i) {
            if (is_array_same(get_row(g, i), get_row(g, x), cols_g)) {
                return false;
            }
        }
    }
    for (uint y = 0; y < cols_g; y++) {
        if (y != j) {
            if (is_array_same(get_col(g, j), get_col(g, y), rows_g)) {
                return false;
            }
        }
    }
    return true;
}