#include "game_aux.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void throw_error(char *msg) {
    fprintf(stderr, "[error] %s\n", msg);
    exit(EXIT_FAILURE);
}
static void game_test(game g, char *msg) {
    if (g == NULL)
        throw_error(msg);
}
static void cgame_test(cgame g, char *msg) {
    if (g == NULL)
        throw_error(msg);
}

void game_print(cgame g) {
    cgame_test(g, "g is not initialized\n");
    printf("   012345\n   ------\n");
    for (int i = 0; i < DEFAULT_SIZE; i++) {
        printf("%d |", i);
        for (int j = 0; j < DEFAULT_SIZE; j++) {
            square s = game_get_square(g, i, j);
            if (s == S_EMPTY)
                printf(" ");
            else if (s == S_ZERO)
                printf("w");
            else if (s == S_ONE)
                printf("b");
            else if (s == S_IMMUTABLE_ZERO)
                printf("W");
            else if (s == S_IMMUTABLE_ONE)
                printf("B");
        }
        printf("|\n");
    }
    printf("   ------\n");
}

game game_default(void) {
    square squares[DEFAULT_SIZE * DEFAULT_SIZE] = {0, 4, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 3, 0,
                                                   0, 3, 4, 0, 0, 0, 0, 0, 4, 0, 0, 3, 0, 0, 0, 0, 0, 3};
    game g = game_new(squares);
    game_test(g, "g is not initialized\n");
    return g;
}

game game_default_solution(void) {
    square squares[DEFAULT_SIZE * DEFAULT_SIZE] = {1, 4, 3, 2, 1, 2, 1, 2, 2, 1, 2, 1, 2, 3, 1, 2, 3, 2,
                                                   2, 3, 4, 1, 1, 2, 1, 2, 4, 1, 2, 3, 2, 1, 1, 2, 2, 3};
    game g = game_new(squares);
    game_test(g, "g is not initialized\n");
    return g;
}
