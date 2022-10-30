#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "game_aux.h"
#include "game.h"

void usage(int argc, char *argv[]) {
    fprintf(stderr, "Usage: %s <testname> [<...>]\n", argv[0]);
    exit(EXIT_FAILURE);
}

bool test_game_is_immutable() {
    int squares[DEFAULT_SIZE][DEFAULT_SIZE] = {
        {0, 4, 3, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 3, 0, 0, 3, 0},
        {0, 3, 4, 0, 0, 0},
        {0, 0, 4, 0, 0, 3},
        {0, 0, 0, 0, 0, 3}};
    game g = game_new((square *)squares);
    for (uint i = 0; i < DEFAULT_SIZE; i++) {
        for (uint j = 0; j < DEFAULT_SIZE; j++) {
            if (game_is_immutable(g, i, j) && (game_get_square(g, i, j) != S_IMMUTABLE_ONE && game_get_square(g, i, j) != S_IMMUTABLE_ZERO)) {
                return false;
            } else if (!(game_is_immutable(g, i, j)) && (game_get_square(g, i, j) == S_IMMUTABLE_ONE || game_get_square(g, i, j) == S_IMMUTABLE_ZERO)) {
                return false;
            }
        }
    }
    return true;
}

bool test_game_has_error() {
    
    return false;
}

bool test_game_check_move() {
    int squares[DEFAULT_SIZE][DEFAULT_SIZE] = {
        {0, 4, 3, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 3, 0, 0, 3, 0},
        {0, 3, 4, 0, 0, 0},
        {0, 0, 4, 0, 0, 3},
        {0, 0, 0, 0, 0, 3}};
    game g = game_new((square *)squares);
    for (uint i = 0; i < DEFAULT_SIZE; i++) {
        for (uint j = 0; j < DEFAULT_SIZE; j++) {
            if (game_check_move(g, i, j, S_EMPTY) && (game_get_square(g, i, j) == S_IMMUTABLE_ONE || game_get_square(g, i, j) == S_IMMUTABLE_ZERO)) {
                return false;
            } else if (!(game_check_move(g, i, j, S_EMPTY)) && (game_get_square(g, i, j) != S_IMMUTABLE_ONE && game_get_square(g, i, j) != S_IMMUTABLE_ZERO)) {
                return false;
            }
        }
    }
    return true;
}

bool test_game_play_move() {
    return false;
}

bool test_game_is_over() {
    return false;
}

int main(int argc, char *argv[]) {
    if (argc == 1)
        usage(argc, argv);

    bool ok = false;
    if (strcmp(argv[1], "game_is_immutable") == 0) {
        ok = test_game_is_immutable();
    } else if (strcmp(argv[1], "game_has_error") == 0) {
        ok = test_game_has_error();
    } else if(strcmp(argv[1], "game_check_move") == 0) {
        ok = test_game_check_move();
    } else if (strcmp(argv[1], "game_play_move") == 0) {
        ok = test_game_play_move();
    } else if (strcmp(argv[1], "game_is_over") == 0) {
        ok = test_game_is_over();
    } else {
        fprintf(stderr, "Error: test \"%s\" not found\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if (ok) {
        fprintf(stderr, "Test: \"%s\" finished: SUCCESS\n", argv[1]);
        return EXIT_SUCCESS;
    } else {
        fprintf(stderr, "Test: \"%s\" finished: FAILURE\n", argv[1]);
        return EXIT_FAILURE;
    }
}