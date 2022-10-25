/*
  ╭────────────────────────────────────────────────────────╮
    > File:           game_test_hlumet.c
    > Created Date:   25-10-2022 17:10
    > Author:         Tim Lacault
    ──────────────────────────────────────────────────────
    > Last Modified:  25-10-2022 17:10
    > Modified By:    Tim Lacault
    ──────────────────────────────────────────────────────
    > Description:
  ╰────────────────────────────────────────────────────────╯
*/

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include "game.h"
#include "game_aux.h"

bool test_game_set_square()
{
    game g = game_default();
    bool status = true;

    if (!g)
        return (false);
    game_set_square(g, 0, 0, S_ZERO);
    game_set_square(g, 1, 0, S_ONE);
    game_set_square(g, 0, 3, S_IMMUTABLE_ZERO);
    game_set_square(g, 1, 5, S_IMMUTABLE_ONE);
    game_set_square(g, 0, 1, S_EMPTY);
    if (game_get_square(g, 0, 0) != S_ZERO)
        status = false;
    else if (game_get_square(g, 1, 0) != S_ONE)
        status = false;
    else if (game_get_square(g, 0, 3) != S_IMMUTABLE_ZERO)
        status = false;
    else if (game_get_square(g, 1, 5) != S_IMMUTABLE_ONE)
        status = false;
    else if (game_get_square(g, 0, 1) != S_EMPTY)
        status = false;
    game_delete(g);
    return (status);
}

bool test_game_get_square()
{
    game g = game_default();
    bool status = true;

    if (!g)
        return (false);
    game_set_square(g, 0, 0, S_ZERO);
    game_set_square(g, 1, 0, S_ONE);
    game_set_square(g, 0, 3, S_IMMUTABLE_ZERO);
    game_set_square(g, 1, 5, S_IMMUTABLE_ONE);
    game_set_square(g, 0, 1, S_EMPTY);
    if (game_get_square(g, 0, 0) != S_ZERO)
        status = false;
    else if (game_get_square(g, 1, 0) != S_ONE)
        status = false;
    else if (game_get_square(g, 0, 3) != S_IMMUTABLE_ZERO)
        status = false;
    else if (game_get_square(g, 1, 5) != S_IMMUTABLE_ONE)
        status = false;
    else if (game_get_square(g, 0, 1) != S_EMPTY)
        status = false;
    game_delete(g);
    return (status);
}

bool test_game_get_number()
{
    game g = game_default();
    bool status = true;

    if (!g)
        return (false);
    game_set_square(g, 0, 3, S_ONE);
    game_set_square(g, 0, 4, S_ZERO);
    if (game_get_number(g, 0, 1) != 1)
        status = false;
    else if (game_get_number(g, 0, 0) != -1)
        status = false;
    else if (game_get_number(g, 2, 1) != 0)
        status = false;
    else if (game_get_number(g, 0, 3) != 1)
        status = false;
    else if (game_get_number(g, 0, 4) != 0)
        status = false;
    game_delete(g);
    return (status);
}

bool test_game_get_next_square()
{
    game g = game_default();
    bool status = true;

    if (!g)
        return (false);
    game_set_square(g, 0, 3, S_ZERO);
    game_set_square(g, 0, 4, S_ONE);
    if (game_get_next_square(g, 0, 0, RIGHT, 1) != S_IMMUTABLE_ONE)
        status = false;
    else if (game_get_next_square(g, 0, 0, RIGHT, 2) != S_IMMUTABLE_ZERO)
        status = false;
    else if (game_get_next_square(g, 0, 0, DOWN, 1) != S_EMPTY)
        status = false;
    else if (game_get_next_square(g, 3, 0, LEFT, 2) != -1)
        status = false;
    else if (game_get_next_square(g, 2, 1, UP, 2) != S_IMMUTABLE_ONE)
        status = false;
    else if (game_get_next_square(g, 0, 1, RIGHT, 2) != S_ZERO)
        status = false;
    else if (game_get_next_square(g, 0, 5, LEFT, 1) != S_ONE)
        status = false;
    game_delete(g);
    return (status);
}

bool test_game_get_next_number()
{
    game g = game_default();
    bool status = true;

    if (!g)
        return (false);
    game_set_square(g, 0, 3, S_ZERO);
    game_set_square(g, 0, 4, S_ONE);
    if (game_get_next_number(g, 0, 0, RIGHT, 1) != 1)
        status = false;
    else if (game_get_next_number(g, 0, 0, RIGHT, 2) != 0)
        status = false;
    else if (game_get_next_number(g, 0, 0, DOWN, 1) != -1)
        status = false;
    else if (game_get_next_number(g, 3, 0, LEFT, 2) != -1)
        status = false;
    else if (game_get_next_number(g, 2, 1, UP, 2) != 1)
        status = false;
    else if (game_get_next_number(g, 0, 1, RIGHT, 2) != 0)
        status = false;
    else if (game_get_next_number(g, 0, 5, LEFT, 1) != 1)
        status = false;
    game_delete(g);
    return (status);
}

void usage(int argc, char *argv[])
{
  fprintf(stderr, "Usage: %s <testname> [<...>]\n", argv[0]);
  exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
    if (argc == 1)
        usage(argc, argv);
    // start test
    fprintf(stderr, "=> Start test \"%s\"\n", argv[1]);
    bool ok = false;
    if (strcmp("game_set_square", argv[1]) == 0)
        ok = test_game_set_square();
    else if (strcmp("game_get_square", argv[1]) == 0)
        ok = test_game_get_square();
    else if (strcmp("game_get_number", argv[1]) == 0)
        ok = test_game_get_number();
    else if (strcmp("game_get_next_square", argv[1]) == 0)
        ok = test_game_get_next_square();
    else if (strcmp("game_get_next_number", argv[1]) == 0)
        ok = test_game_get_next_number();
    else {
        fprintf(stderr, "Test not found!\n");
        exit(EXIT_FAILURE);
    }
    // print test result
    if (ok) {
        fprintf(stderr, "Test \"%s\" finished: SUCCESS\n", argv[1]);
        return (EXIT_SUCCESS);
    }
    else {
        fprintf(stderr, "Test \"%s\" finished: FAILURE\n", argv[1]);
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}