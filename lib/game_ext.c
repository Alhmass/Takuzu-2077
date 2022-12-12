#include "game_ext.h"
#include "game_struct.h"

game game_new_ext(uint nb_rows, uint nb_cols, square* squares, bool wrapping, bool unique)
{
    return (NULL);
}

game game_new_empty_ext(uint nb_rows, uint nb_cols, bool wrapping, bool unique)
{
    return (NULL);
}

uint game_nb_rows(cgame g)
{
    return (0);
}

uint game_nb_cols(cgame g)
{
    return (0);
}

bool game_is_wrapping(cgame g)
{
    return (false);
}

bool game_is_unique(cgame g)
{
    return (false);
}

void game_undo(game g)
{
   return;
}

void game_redo(game g)
{
    return;
}