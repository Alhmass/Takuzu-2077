#include "takuzu.h"

game game_new(square *squares) {
    game g = malloc(sizeof(struct game_s));
    pointer_test(g, "malloc failed");
    g->game = malloc(sizeof(square) * (DEFAULT_SIZE * DEFAULT_SIZE));
    pointer_test(g->game, "malloc failed");
    memcpy(g->game, squares, sizeof(square) * (DEFAULT_SIZE * DEFAULT_SIZE));
    g->version = 1;
    return g;
}

game game_new_empty(void) {
    square *squares = (square *)calloc(DEFAULT_SIZE * DEFAULT_SIZE, sizeof(square));
    pointer_test(squares, "malloc failed");
    game g = game_new(squares);
    cgame_test(g, "malloc failed");
    free(squares);
    g->version = 1;
    return g;
}

game game_copy(cgame g) {
    cgame_test(g, "g is NULL");
    if (g->version == 2) {
        game copy = game_new_ext(game_nb_rows(g), game_nb_cols(g), g->game, g->wrapping, g->unique);
        game_test(copy, "malloc failed");
        return copy;
    }
    game copy = game_new(g->game);
    game_test(copy, "malloc failed");
    return copy;
}

bool game_equal(cgame g1, cgame g2) {
    if (g1 == NULL || g2 == NULL || g1->game == NULL || g2->game == NULL)
        return false;
    uint rows_g1 = (g1->version == 1) ? DEFAULT_SIZE : game_nb_rows(g1);
    uint cols_g1 = (g1->version == 1) ? DEFAULT_SIZE : game_nb_cols(g1);
    uint rows_g2 = (g2->version == 1) ? DEFAULT_SIZE : game_nb_rows(g2);
    uint cols_g2 = (g2->version == 1) ? DEFAULT_SIZE : game_nb_cols(g2);
    if (rows_g1 != rows_g2 || cols_g1 != cols_g2)
        return false;
    for (uint i = 0; i < rows_g1; i++) {
        for (uint j = 0; j < cols_g1; j++) {
            if (game_get_square(g1, i, j) != game_get_square(g2, i, j))
                return false;
        }
    }
    return true;
}

void game_delete(game g) {
    if (g == NULL)
        return;
    if (g->game != NULL)
        free(g->game);
    if (g->version == 2) {
        ms_delete(g->history);
        ms_delete(g->backup);
    }
    free(g);
}

void game_set_square(game g, uint i, uint j, square s) {
    uint rows_g = (g->version == 1) ? DEFAULT_SIZE : game_nb_rows(g);
    uint cols_g = (g->version == 1) ? DEFAULT_SIZE : game_nb_cols(g);
    if (i >= rows_g || j >= cols_g)
        return;
    g->game[rows_g * i + j] = s;
}

square game_get_square(cgame g, uint i, uint j) {
    cgame_test(g, "g is not initialized\n");
    uint rows_g = (g->version == 1) ? DEFAULT_SIZE : game_nb_rows(g);
    uint cols_g = (g->version == 1) ? DEFAULT_SIZE : game_nb_cols(g);
    if (i >= rows_g || j >= cols_g)
        throw_error("invalid index");
    return g->game[cols_g * i + j];
}

int game_get_number(cgame g, uint i, uint j) {
    cgame_test(g, "g is not initialized\n");
    uint rows_g = (g->version == 1) ? DEFAULT_SIZE : game_nb_rows(g);
    uint cols_g = (g->version == 1) ? DEFAULT_SIZE : game_nb_cols(g);
    if (i >= rows_g || j >= cols_g)
        throw_error("i or j value is out of bounds!\n");
    uint index = rows_g * i + j;
    if (g->game[index] == S_EMPTY)
        return (-1);
    else if (g->game[index] == S_ZERO || g->game[index] == S_IMMUTABLE_ZERO)
        return (0);
    else
        return (1);
}

int game_get_next_square(cgame g, uint i, uint j, direction dir, uint dist) {
    cgame_test(g, "g is not initialized\n");
    if (dist > 2)
        throw_error("the distance value must be <=2!\n");
    uint rows_g = (g->version == 1) ? DEFAULT_SIZE : game_nb_rows(g);
    uint cols_g = (g->version == 1) ? DEFAULT_SIZE : game_nb_cols(g);
    // if (i >= rows_g || j >= cols_g)
    //     return (-1);
    int findex = 0;
    if (g->version == 2 && game_is_wrapping(g)) {
        if (dir == LEFT) {
            findex = (j - dist);
            j = findex <= 0 ? (cols_g + findex) % cols_g : (j - dist) % cols_g;
        } else if (dir == RIGHT)
            j = (j + dist) % cols_g;
        else if (dir == UP) {
            findex = (i - dist);
            i = findex <= 0 ? (rows_g + findex) % rows_g : (i - dist) % rows_g;
        } else
            i = (i + dist) % rows_g;
    } else {
        if (dir == LEFT && dist <= j)
            j -= dist;
        else if (dir == RIGHT && (j + dist) < cols_g)
            j += dist;
        else if (dir == UP && dist <= i)
            i -= dist;
        else if (dir == DOWN && (i + dist) < rows_g)
            i += dist;
        else
            return (-1);
    }
    return (game_get_square(g, i, j));
}

int game_get_next_number(cgame g, uint i, uint j, direction dir, uint dist) {
    cgame_test(g, "g is not initialized\n");
    if (dist > 2)
        throw_error("the distance value must be <=2!\n");
    uint rows_g = (g->version == 1) ? DEFAULT_SIZE : game_nb_rows(g);
    uint cols_g = (g->version == 1) ? DEFAULT_SIZE : game_nb_cols(g);
    int findex = 0;
    if (g->version == 2 && game_is_wrapping(g)) {
        if (i >= rows_g || j >= cols_g)
            return (-1);
        if (dir == LEFT) {
            findex = (j - dist);
            j = findex <= 0 ? (cols_g + findex) : (j - dist) % cols_g;
        } else if (dir == RIGHT)
            j = (j + dist) % cols_g;
        else if (dir == UP) {
            findex = (i - dist);
            i = findex <= 0 ? (rows_g + findex) : (i - dist) % rows_g;
        } else
            i = (i + dist) % rows_g;
    } else {
        if (dir == LEFT && dist <= j)
            j -= dist;
        else if (dir == RIGHT && (j + dist) < cols_g)
            j += dist;
        else if (dir == UP && dist <= i)
            i -= dist;
        else if (dir == DOWN && (i + dist) < rows_g)
            i += dist;
        else
            return (-1);
    }
    return (game_get_number(g, i, j));
}

bool game_is_empty(cgame g, uint i, uint j) {
    cgame_test(g, "g is not initialized\n");
    uint rows_g = (g->version == 1) ? DEFAULT_SIZE : game_nb_rows(g);
    uint cols_g = (g->version == 1) ? DEFAULT_SIZE : game_nb_cols(g);
    assert(((i < rows_g) && (j < cols_g)));
    return (game_get_square(g, i, j) == S_EMPTY);
}

bool game_is_immutable(cgame g, uint i, uint j) {
    cgame_test(g, "g is not initialized\n");
    uint rows_g = (g->version == 1) ? DEFAULT_SIZE : game_nb_rows(g);
    uint cols_g = (g->version == 1) ? DEFAULT_SIZE : game_nb_cols(g);
    assert(((i < rows_g) && (j < cols_g)));
    square s = game_get_square(g, i, j);
    if (s == 3 || s == 4) {
        return true;
    }
    return false;
}

int game_has_error(cgame g, uint i, uint j) {
    cgame_test(g, "g is not initialized\n");

    uint rows_g = (g->version == 1) ? DEFAULT_SIZE : game_nb_rows(g);
    uint cols_g = (g->version == 1) ? DEFAULT_SIZE : game_nb_cols(g);
    if (i >= rows_g || j >= cols_g)
        throw_error("i or j value is out of bounds!\n");

    if (g->version == 2 && game_is_wrapping(g)) {
        if (is_consecutive_grid(g, i, j)) {
            return 1;
        }
    }
    if (g->version == 2 && game_is_unique(g)) {
        if (!is_unique_array(g, i, j)) {
            return 1;
        }
    }
    square *row = get_row(g, i);
    square *col = get_col(g, j);
    if (is_consecutive(row, cols_g, game_get_number(g, i, j)) ||
        is_consecutive(col, rows_g, game_get_number(g, i, j))) {
        free(row);
        free(col);
        return 1;
    }
    free(row);
    free(col);
    return 0;
}

bool game_check_move(cgame g, uint i, uint j, square s) {
    cgame_test(g, "g is not initialized\n");
    uint rows_g = (g->version == 1) ? DEFAULT_SIZE : game_nb_rows(g);
    uint cols_g = (g->version == 1) ? DEFAULT_SIZE : game_nb_cols(g);
    if ((i > rows_g) || (j > cols_g))
        return false;
    if (s == S_IMMUTABLE_ONE || s == S_IMMUTABLE_ZERO)
        return false;
    square c = game_get_square(g, i, j);
    if (c == S_IMMUTABLE_ONE || c == S_IMMUTABLE_ZERO)
        return false;

    return true;
}

void game_play_move(game g, uint i, uint j, square s) {
    cgame_test(g, "g is not initialized\n");
    uint rows_g = (g->version == 1) ? DEFAULT_SIZE : game_nb_rows(g);
    uint cols_g = (g->version == 1) ? DEFAULT_SIZE : game_nb_cols(g);
    assert(((i < rows_g) && (j < cols_g)));
    if (game_check_move(g, i, j, s)) {
        if (g->version == 2) {
            if (g->backup != NULL && g->history != NULL) {
                move m = move_create(i, j, s, game_get_square(g, i, j));
                ms_push(g->history, m);
                ms_clear(g->backup);
                free(m);
            }
        }
        game_set_square(g, i, j, s);
    }
}

bool game_is_over(cgame g) {
    cgame_test(g, "g is not initialized\n");
    uint rows_g = (g->version == 1) ? DEFAULT_SIZE : game_nb_rows(g);
    uint cols_g = (g->version == 1) ? DEFAULT_SIZE : game_nb_cols(g);
    for (uint i = 0; i < rows_g; i++)
        for (uint j = 0; j < cols_g; j++)
            if (game_is_empty(g, i, j) || game_has_error(g, i, j))
                return false;
    return true;
}

void game_restart(game g) {
    pointer_test(g, "g is not initialized\n");
    uint rows_g = (g->version == 1) ? DEFAULT_SIZE : game_nb_rows(g);
    uint cols_g = (g->version == 1) ? DEFAULT_SIZE : game_nb_cols(g);
    for (uint i = 0; i < rows_g; i++)
        for (uint j = 0; j < cols_g; j++)
            if (!game_is_immutable(g, i, j))
                game_set_square(g, i, j, S_EMPTY);
    if (g->version == 2) {
        if (g->history != NULL)
            ms_clear(g->history);
        if (g->backup != NULL)
            ms_clear(g->backup);
    }
}