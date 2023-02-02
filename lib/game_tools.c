#include "takuzu.h"

/* ************************************************************************** */
/*                                GAME TOOLS                                  */
/* ************************************************************************** */

game game_load(char *filename) {
    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        fprintf(stderr, "[error] cannot open file %s\n", filename);
        exit(EXIT_FAILURE);
    }
    uint nb_rows, nb_cols, wrapping, unique;
    if (fscanf(f, "%u %u %u %u\n", &nb_rows, &nb_cols, &wrapping, &unique) != 4) {
        fprintf(stderr, "[error] cannot read file %s\n", filename);
        exit(EXIT_FAILURE);
    }
    game g = game_new_empty_ext(nb_rows, nb_cols, wrapping, unique);
    assert(g);
    for (uint i = 0; i < g->nb_rows; i++) {
        for (uint j = 0; j < g->nb_cols; j++) {
            char s;
            if (fscanf(f, "%c", &s) != 1) {
                fprintf(stderr, "[error] cannot read file %s\n", filename);
                exit(EXIT_FAILURE);
            }
            if (s == 'e')
                s = S_EMPTY;
            else if (s == 'w')
                s = S_ZERO;
            else if (s == 'W')
                s = S_IMMUTABLE_ZERO;
            else if (s == 'b')
                s = S_ONE;
            else if (s == 'B')
                s = S_IMMUTABLE_ONE;
            else {
                fprintf(stderr, "[error] cannot read file %s\n", filename);
                exit(EXIT_FAILURE);
            }
            SQUARE(g, i, j) = s;
        }
        fscanf(f, "\n");
    }
    fclose(f);
    return g;
}

/* ************************************************************************** */

void game_save(cgame g, char *filename) {
    (void)g;
    (void)filename;
}
