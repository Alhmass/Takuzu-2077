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

static bool is_consecutive(square *array, uint size, square current) {
    if (current == S_EMPTY)
        return false;

    uint consecutive = 0;
    for (uint i = 0; i < size; i++) {
        if (array[i] == current) {
            if (++consecutive >= size / 2)
                return true;
        } else
            consecutive = 0;
    }
    return false;
}

static bool is_consecutive_grid(cgame g, uint i, uint j) {
    (void)g;
    (void)i;
    (void)j;
    // premiere boucle pour les lignes
    // tu get_row(i) et tu l'envoies dans is_consecutive
    is_consecutive(get_row(g, i), game_nb_cols(g), game_get_square(g, i, j));
    // si WRAPPING tu fais les rotations (game_nb_row(i) fois) et à chaque fois t'envoie l'array dans is_consecutive
    rotate_array(get_row(g, i), game_nb_cols(g));  // tu fais ca game_nb_row(i) fois mais sur la meme array

    // deuxieme boucle pour les colonnes
    // tu get_col(j) et tu l'envoies dans is_consecutive
    is_consecutive(get_col(g, j), game_nb_rows(g), game_get_square(g, i, j));
    // si WRAPPING tu fais les rotations (game_nb_col(j) fois) et à chaque fois t'envoie l'array dans is_consecutive
    rotate_array(get_col(g, j), game_nb_rows(g));  // tu fais ca game_nb_col(j) fois mais sur la meme array

    return false;
}

static bool is_array_same(square *array1, square *array2, uint size) {
    for (uint i = 0; i < size; i++) {
        if (array1[i] != array2[i])
            return false;
    }
    return true;
}

static bool is_unique_grid(cgame g, uint i, uint j) {
    (void)g;
    (void)i;
    (void)j;
    // 2 boucle une en parcourant les rows avec i et un autre en parcourant les cols avec j
    //  PAS OUBLIER de skip la colonne et la ligne ou on est !!
    is_array_same(get_row(g, i), get_row(g, i), game_nb_cols(g));
    is_array_same(get_col(g, j), get_col(g, j), game_nb_rows(g));
    return false;
}

int game_has_error(cgame g, uint i, uint j) {
    cgame_test(g, "g is not initialized\n");
    if (i >= game_nb_rows(g) || j >= game_nb_cols(g))
        throw_error("i or j value is out of bounds!\n");

    if (game_is_wrapping(g)) {
        if (is_consecutive_grid(g, i, j))
            return 1;
    }
    if (game_is_unique(g)) {
        if (!is_unique_grid(g, i, j))
            return 1;
    }

    return 0;
}