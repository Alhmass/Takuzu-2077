#include "takuzu.h"

/* ************************************************************************** */
/*                               GAME SOLVER                                  */
/* ************************************************************************** */

solver solver_new(game g, bool unique) {
    solver s = malloc(sizeof(struct solver_s));
    assert(s);

    s->len = game_nb_empty(g);
    s->word = malloc(s->len * sizeof(int));
    assert(s->word);

    s->nb_zero = 0;
    s->nb_one = game_nb_empty(g);
    s->nb_solutions = 0;
    s->unique = unique;

    return s;
}

/* ************************************************************************** */

void solver_delete(solver s) {
    free(s->word);
    free(s);
}

/* ************************************************************************** */

void find_solutions(game g, solver s, uint pos) {
    // stop recursive calls
    if (pos == s->len) {
        if (is_word_solution(g, s))
            s->nb_solutions++;
        return;
    }

    if (s->nb_solutions == 1 && s->unique)
        return;

    // extend current word recursively with value 0 at position pos
    s->word[pos] = 0;
    s->nb_zero++;
    s->nb_one--;
    find_solutions(g, s, pos + 1);

    // extend current word recursively with value 1 at position pos
    s->word[pos] = 1;
    s->nb_zero--;
    s->nb_one++;
    find_solutions(g, s, pos + 1);
}

/* ************************************************************************** */

bool is_word_solution(game g, csolver s) {
    // Optimizations
    if (s->nb_zero + game_nb_zero(g) != s->nb_one + game_nb_one(g))
        return false;

    // replace empty squares of g_copy with the word
    uint word_index = 0;
    game g_copy = game_copy(g);
    for (uint i = 0; i < g->nb_rows; i++) {
        for (uint j = 0; j < g->nb_cols; j++) {
            if (SQUARE(g, i, j) == S_EMPTY) {
                SQUARE(g_copy, i, j) = (s->word[word_index] == 0) ? S_ZERO : S_ONE;
                word_index++;
            }
        }
    }

    if (game_is_over(g_copy)) {
        if (s->nb_solutions == 0 && s->unique)
            copy_squares(g, g_copy);
        game_delete(g_copy);
        return true;
    }

    game_delete(g_copy);
    return false;
}

/* ************************************************************************** */

void copy_squares(game dest, game src) {
    for (uint i = 0; i < dest->nb_rows; i++) {
        for (uint j = 0; j < dest->nb_cols; j++) {
            if (SQUARE(dest, i, j) == S_EMPTY)
                SQUARE(dest, i, j) = SQUARE(src, i, j);
        }
    }
}

/* ************************************************************************** */

void print_word(csolver s) {
    for (uint i = 0; i < s->len; i++) {
        printf("%d", s->word[i]);
    }
    printf("\n");
}