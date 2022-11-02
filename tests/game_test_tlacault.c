#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "game.h"
#include "game_aux.h"

/*  TEST  */
bool test_game_new(void) {
    int squares[DEFAULT_SIZE][DEFAULT_SIZE] = {
        {0, 4, 3, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 3, 0, 0, 3, 0},
        {0, 3, 4, 0, 0, 0},
        {0, 0, 4, 0, 0, 3},
        {0, 0, 0, 0, 0, 3}};
    game g = game_new((square *)squares);
    game g2 = game_default();

    if (g == NULL)
        return false;
    for (uint i = 0; i < DEFAULT_SIZE; i++)
        for (uint j = 0; j < DEFAULT_SIZE; j++)
            if (game_get_square(g, i, j) != squares[i][j] || game_get_square(g, i, j) != game_get_square(g2, i, j))
                return false;
    if (!game_equal(g, g2))
        return false;
    return true;
}

bool test_game_new_empty(void) {
    int squares[DEFAULT_SIZE][DEFAULT_SIZE] = {
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0}};
    game g1 = game_new((square *)squares);
    game g2 = game_new_empty();

    if (g1 == NULL || g2 == NULL)
        return false;
    if (!game_equal(g1, g2))
        return false;
    return true;
}

bool test_game_copy(void) {
    int squares[DEFAULT_SIZE][DEFAULT_SIZE] = {
        {0, 4, 3, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 3, 0, 0, 3, 0},
        {0, 3, 4, 0, 0, 0},
        {0, 0, 4, 0, 0, 3},
        {0, 0, 0, 0, 0, 3}};
    game g = game_new((square *)squares);
    game copy = game_copy(g);

    if (copy == NULL)
        return false;
    for (uint i = 0; i < DEFAULT_SIZE; i++)
        for (uint j = 0; j < DEFAULT_SIZE; j++)
            if (game_get_square(copy, i, j) != game_get_square(g, i, j))
                return false;
    return true;
}

bool test_game_equal(void) {
    int squares[DEFAULT_SIZE][DEFAULT_SIZE] = {
        {0, 4, 3, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 3, 0, 0, 3, 0},
        {0, 3, 4, 0, 0, 0},
        {0, 0, 4, 0, 0, 3},
        {0, 0, 0, 0, 0, 3}};
    game g1 = game_new((square *)squares);
    game g2 = game_copy(g1);

    int squares_other[DEFAULT_SIZE][DEFAULT_SIZE] = {
        {0, 4, 3, 0, 0, 0},
        {0, 0, 0, 2, 4, 0},
        {0, 3, 0, 0, 3, 0},
        {0, 3, 4, 3, 0, 0},
        {0, 0, 2, 0, 0, 3},
        {3, 0, 0, 1, 0, 4}};
    game g3 = game_new((square *)squares_other);

    if (!game_equal(g1, g2) && game_equal(g1, g3))
        return false;
    return true;
}

bool test_game_delete(void) {
    return true;
}

bool test_game_is_empty(void) {
    int squares[DEFAULT_SIZE][DEFAULT_SIZE] = {
        {0, 4, 3, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 3, 0, 0, 3, 0},
        {0, 3, 4, 0, 0, 0},
        {0, 0, 4, 0, 0, 3},
        {0, 0, 0, 0, 0, 3}};
    game g = game_new((square *)squares);

    for (uint i = 0; i < DEFAULT_SIZE; i++)
        for (uint j = 0; j < DEFAULT_SIZE; j++)
            if (squares[i][j] == 0 && game_is_empty(g, i, j) == false)
                return false;
    return true;
}

bool test_game_restart(void) {
    int squares[DEFAULT_SIZE][DEFAULT_SIZE] = {
        {0, 4, 3, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 3, 0, 0, 3, 0},
        {0, 3, 4, 0, 0, 0},
        {0, 0, 4, 0, 0, 3},
        {0, 0, 0, 0, 0, 3}};
    game g = game_new((square *)squares);

    game_set_square(g, 0, 0, S_ZERO);
    game_set_square(g, 3, 5, S_ONE);
    game_restart(g);

    for (uint i = 0; i < DEFAULT_SIZE; i++)
        for (uint j = 0; j < DEFAULT_SIZE; j++)
            if (game_get_square(g, i, j) != squares[i][j])
                return false;
    return true;
}

/*  USAGE  */
void usage(int argc, char *argv[]) {
    fprintf(stderr, "Usage: %s <testname> [<...>]\n", argv[0]);
    exit(EXIT_FAILURE);
}

/*  MAIN ROUTINE  */
int main(int argc, char *argv[]) {
    if (argc == 1)
        usage(argc, argv);

    fprintf(stderr, "=> Start test \"%s\"\n", argv[1]);
    bool ok = false;
    if (strcmp("game_new", argv[1]) == 0)
        ok = test_game_new();
    else if (strcmp("game_new_empty", argv[1]) == 0)
        ok = test_game_new_empty();
    else if (strcmp("game_copy", argv[1]) == 0)
        ok = test_game_copy();
    else if (strcmp("game_equal", argv[1]) == 0)
        ok = test_game_equal();
    else if (strcmp("game_delete", argv[1]) == 0)
        ok = test_game_delete();
    else if (strcmp("game_is_empty", argv[1]) == 0)
        ok = test_game_is_empty();
    else if (strcmp("game_restart", argv[1]) == 0)
        ok = test_game_restart();
    else {
        fprintf(stderr, "Error: test \"%s\" not found!\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    if (ok) {
        fprintf(stderr, "Test \"%s\" finished: SUCCESS\n", argv[1]);
        return EXIT_SUCCESS;
    } else {
        fprintf(stderr, "Test \"%s\" finished: FAILURE\n", argv[1]);
        return EXIT_FAILURE;
    }
}
