#include "takuzu.h"

/* ************************************************************************** */
/*                               GAME SOLVER                                  */
/* ************************************************************************** */

solver solver_new(game g, bool unique) {
    solver s = malloc(sizeof(struct solver_s));
    assert(s);

    s->len = game_nb_empty(g);
    s->coords = malloc(sizeof(coordinates) * s->len);
    printf("solver_new: s->len = %d\n", s->len);
    assert(s->coords);

    uint index = 0;
    for (uint i = 0; i < g->nb_cols; i++) {
        for (uint j = 0; j < g->nb_rows; j++) {
            if (game_get_square(g, i, j) != S_IMMUTABLE_ZERO && game_get_square(g, i, j) != S_IMMUTABLE_ONE) {
                s->coords[index] = malloc(sizeof(struct coordinates_s));
                COORDS_I(s, index) = i;
                COORDS_J(s, index) = j;
                index++;
            }
        }
    }

    s->solution = NULL;

    s->nb_zero = 0;
    s->nb_one = s->len;
    s->nb_solutions = 0;
    s->unique = unique;

    return s;
}

/* ************************************************************************** */

void solver_delete(solver s) {
    for (uint i = 0; i < s->len; i++) {
        free(s->coords[i]);
    }
    free(s->coords);
    if (s->solution)
        free(s->solution);
    free(s);
}

/* ************************************************************************** */

void find_solutions(game g, solver s, uint pos) {
    // stop recursive calls
    if (s->nb_solutions == 1 && s->unique)
        return;

    if (pos == s->len) {
        if (is_word_solution(g, s))
            s->nb_solutions++;
        return;
    }

    // extend current word recursively with value 0 at position pos
    game_set_square(g, COORDS_I(s, pos), COORDS_J(s, pos), S_ZERO);
    s->nb_zero++;
    s->nb_one--;
    find_solutions(g, s, pos + 1);

    // extend current word recursively with value 1 at position pos
    game_set_square(g, COORDS_I(s, pos), COORDS_J(s, pos), S_ONE);
    s->nb_zero--;
    s->nb_one++;
    find_solutions(g, s, pos + 1);
}

/* ************************************************************************** */

bool is_word_solution(game g, solver s) {
    // Optimizations
    if (s->nb_zero + game_nb_zero(g) != s->nb_one + game_nb_one(g))
        return false;

    for (uint pos = 0; pos < s->len; pos++) {
        if (game_has_error(g, COORDS_I(s, pos), COORDS_J(s, pos)))
            return false;
    }

    // Save the first solution
    if (s->nb_solutions == 0 && s->unique) {
        s->solution = malloc(sizeof(square) * s->len);
        assert(s->solution);
        for (uint pos = 0; pos < s->len; pos++) {
            s->solution[pos] = game_get_square(g, COORDS_I(s, pos), COORDS_J(s, pos));
        }
    }
    return true;
}

/* ************************************************************************** */

void copy_solution(game g, csolver s) {
    for (uint pos = 0; pos < s->len; pos++) {
        game_set_square(g, COORDS_I(s, pos), COORDS_J(s, pos), s->solution[pos]);
    }
}

/* ************************************************************************** */

void print_word(cgame g, csolver s) {
    for (uint i = 0; i < s->len; i++) {
        printf("%d", game_get_square(g, COORDS_I(s, i), COORDS_J(s, i)));
    }
    printf("\n");
}