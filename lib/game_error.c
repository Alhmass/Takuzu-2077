#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "game.h"
#include "game_ext.h"
#include "game_struct.h"
#include "move.h"
#include "move_stack.h"

static void throw_error(char *msg) {
    fprintf(stderr, "[error] %s\n", msg);
    exit(EXIT_FAILURE);
}
static void test_pointer(void *p, char *msg) {
    if (p == NULL)
        throw_error(msg);
}
static void cgame_test(cgame g, char *msg) {
    if (g == NULL)
        throw_error(msg);
}

static square *get_row(cgame g, uint i) {
    cgame_test(g, "g is NULL");
    square *row = malloc(sizeof(square) * game_nb_cols(g));
    test_pointer(row, "malloc failed");
    for (uint j = 0; j < game_nb_cols(g); j++) row[j] = game_get_square(g, i, j);
    return row;
}

static square *get_col(cgame g, uint j) {
    cgame_test(g, "g is NULL");
    square *col = malloc(sizeof(square) * game_nb_rows(g));
    test_pointer(col, "malloc failed");
    for (uint i = 0; i < game_nb_rows(g); i++) col[i] = game_get_square(g, i, j);
    return col;
}

static square *rotate_array(square *array, uint size) {
    square *rotated = malloc(sizeof(square) * size);
    test_pointer(rotated, "malloc failed");
    square start = array[0];
    for (uint i = 0; i < size - 1; i++) rotated[i] = array[i + 1];
    rotated[size - 1] = start;
    return rotated;
}

static int get_number(int s) {
    if (s == 0) {
        return -1;
    } else if (s == 1 || s == 3) {
        return 0;
    }
    return 1;
}

static bool is_consecutive(square *array, uint size, int current) {
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

static bool is_consecutive_grid(cgame g, uint i, uint j) {
    square *tabRows = get_row(g, i);
    for (uint x = 0; x < game_nb_cols(g); x++) {
        if (is_consecutive(tabRows, game_nb_cols(g), game_get_square(g, i, j))) {
            return true;
        }
        tabRows = rotate_array(tabRows, game_nb_cols(g));
    }
    square *tabCols = get_col(g, i);
    for (uint y = 0; y < game_nb_rows(g); y++) {
        if (is_consecutive(tabCols, game_nb_rows(g), game_get_square(g, i, j))) {
            return true;
        }
        tabCols = rotate_array(tabCols, game_nb_rows(g));
    }
    return false;
}

static bool is_array_same(square *array1, square *array2, uint size) {
    for (uint i = 0; i < size; i++) {
        if (get_number(array1[i]) != get_number(array2[i]) || get_number(array1[i]) == -1 ||
            get_number(array2[i]) == -1) {
            return false;
        }
    }
    return true;
}

static bool is_unique_array(cgame g, uint i, uint j) {
    for (uint x = 0; x < game_nb_rows(g); x++) {
        if (x != i) {
            if (is_array_same(get_row(g, i), get_row(g, x), game_nb_cols(g))) {
                return false;
            }
        }
    }
    for (uint y = 0; y < game_nb_cols(g); y++) {
        if (y != j) {
            if (is_array_same(get_col(g, j), get_col(g, y), game_nb_rows(g))) {
                return false;
            }
        }
    }
    return true;
    // 2 boucle une en parcourant les rows avec i et un autre en parcourant les cols avec j
    //  PAS OUBLIER de skip la colonne et la ligne ou on est !!
    // is_array_same(get_row(g, i), get_row(g, i), game_nb_cols(g));
    // is_array_same(get_col(g, j), get_col(g, j), game_nb_rows(g));
    // return false;
}

static bool is_unique_grid(cgame g) {
    (void)g;
    for (uint i = 0; i < game_nb_rows(g); i++) {
        for (uint j = 0; j < game_nb_cols(g); j++) {
            if (!is_unique_array(g, i, j)) {
                return false;
            }
        }
    }
    return true;
}

int game_has_error(cgame g, uint i, uint j) {
    cgame_test(g, "g is not initialized\n");
    if (i >= game_nb_rows(g) || j >= game_nb_cols(g))
        throw_error("i or j value is out of bounds!\n");

    if (game_is_wrapping(g)) {
        if (is_consecutive_grid(g, i, j)) {
            return 1;
        }
    }
    if (game_is_unique(g)) {
        if (!is_unique_grid(g)) {
            return 1;
        }
    }
    square *row = get_row(g, i);
    square *col = get_col(g, j);
    if (is_consecutive(row, game_nb_cols(g), game_get_number(g, i, j)) ||
        is_consecutive(col, game_nb_rows(g), game_get_number(g, i, j))) {
        free(row);
        free(col);
        return 1;
    }
    free(row);
    free(col);
    return 0;
}