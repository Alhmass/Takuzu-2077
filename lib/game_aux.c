#include "game_aux.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void throw_error(char *msg);

void game_print(cgame g) {
    if (g == NULL)
        throw_error("game is NULL");
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
    return game_new(squares);
}

game game_default_solution(void) {
    square squares[DEFAULT_SIZE * DEFAULT_SIZE] = {1, 4, 3, 2, 1, 2, 1, 2, 2, 1, 2, 1, 2, 3, 1, 2, 3, 2,
                                                   2, 3, 4, 1, 1, 2, 1, 2, 4, 1, 2, 3, 2, 1, 1, 2, 2, 3};
    return game_new(squares);
}
