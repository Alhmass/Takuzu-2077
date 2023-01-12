#include "takuzu.h"

void game_print(cgame g) {
    cgame_test(g, "g is not initialized\n");
    uint rows_g = (g->version == 1) ? DEFAULT_SIZE : game_nb_rows(g);
    uint cols_g = (g->version == 1) ? DEFAULT_SIZE : game_nb_cols(g);
    printf("cold: %d, row: %d\n", cols_g, rows_g);
    printf("   ");
    for (uint i = 0; i < rows_g; i++) printf("%d", i);
    printf("\n   ");
    for (uint i = 0; i < rows_g; i++) printf("-");
    printf("\n");
    for (uint i = 0; i < rows_g; i++) {
        printf("%d |", i);
        for (uint j = 0; j < cols_g; j++) {
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
    printf("   ");
    for (uint i = 0; i < rows_g; i++) printf("-");
    printf("\n");
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
