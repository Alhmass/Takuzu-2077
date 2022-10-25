/*
  ╭────────────────────────────────────────────────────────╮
    > File:           game_test_aloupoueyou.c
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
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void usage(int argc, char *argv[]) {
    fprintf(stderr, "Usage: %s <testname> [<...>]\n", argv[0]);
    exit(EXIT_FAILURE);
}

bool test_game_is_immutable() {
    return false;
}

bool test_game_has_error() {
    return false;
}

bool test_game_check_move() {
    return false;
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