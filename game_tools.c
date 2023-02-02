#include "takuzu.h"

/* ************************************************************************** */
/*                                GAME TOOLS                                  */
/* ************************************************************************** */

game game_load(char *filename) {
    (void)filename;
    game g = game_new_empty_ext(DEFAULT_SIZE, DEFAULT_SIZE, false, false);
    assert(g);
    return g;
}

/* ************************************************************************** */

void game_save(cgame g, char *filename) {
    (void)g;
    (void)filename;
}