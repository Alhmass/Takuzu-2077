#include "takuzu.h"

/* ************************************************************************** */
/*                               GAME SOLVER                                  */
/* ************************************************************************** */

void find_solutions(game g, int pos, int *word, uint *nb_solutions, int mode) {
    int len = game_nb_empty(g);

    // stop recursive calls
    if (pos == len) {
        // count number of zeros and ones in the word
        int nb_zero = 0, nb_one = 0;
        for (int i = 0; i < len; i++) (word[i] == 0) ? nb_zero++ : nb_one++;
        if (is_word_solution(g, word, nb_zero, nb_one, *nb_solutions, mode))
            (*nb_solutions)++;
        return;
    }

    if (*nb_solutions == 1 && mode == 0)
        return;

    // extend current word recursively with value 0 at position pos
    word[pos] = 0;
    find_solutions(g, pos + 1, word, nb_solutions, mode);

    // extend current word recursively with value 1 at position pos
    word[pos] = 1;
    find_solutions(g, pos + 1, word, nb_solutions, mode);
}

/* ************************************************************************** */

bool is_word_solution(game g, int *word, int nb_zero, int nb_one, uint nb_solutions, int mode) {
    if (nb_zero + game_nb_zero(g) != nb_one + game_nb_one(g))
        return false;

    game g_copy = game_copy(g);

    // replace empty squares with the word
    for (uint i = 0; i < g->nb_rows; i++) {
        for (uint j = 0; j < g->nb_cols; j++) {
            if (SQUARE(g, i, j) == S_EMPTY) {
                SQUARE(g_copy, i, j) = (word[0] == 0) ? S_ZERO : S_ONE;
                word++;
            }
        }
    }

    if (game_is_over(g_copy)) {
        if (nb_solutions == 0 && mode == 0)
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

void print_word(int *word, int len) {
    for (int i = 0; i <= len; i++) {
        printf("%d", word[i]);
    }
    printf("\n");
}