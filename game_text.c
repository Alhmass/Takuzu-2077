#include "takuzu.h"

static void display_help(void) {
    printf("> action: help\n");
    printf("- press 'w <i> <j>' to put a zero/white at square (i,j)\n");
    printf("- press 'b <i> <j>' to put a one/black at square (i,j)\n");
    printf("- press 'e <i> <j>' to empty square (i,j)\n");
    printf("- press 'z' to undo previous move\n");
    printf("- press 'y' to redo undone moves\n");
    printf("- press 'r' to restart\n");
    printf("- press 'q' to quit\n");
}

static void command(game *g, char c) {
    if (c == 'r') {
        printf("> action: restart\n");
        game_restart(*g);
    } else if (c == 'h') {
        display_help();
    } else if (c == 'q') {
        printf("> action: quit\n");
        printf("What a shame you gave up :-(\n");
        game_delete(*g);
        exit(EXIT_SUCCESS);
    } else if (c == 'z') {
        printf("> action: undo\n");
        game_undo(*g);
    } else if (c == 'y') {
        printf("> action: redo\n");
        game_redo(*g);
    }
}

static void display_errors(cgame g) {
    for (uint i = 0; i < game_nb_cols(g); i++) {
        for (uint j = 0; j < game_nb_rows(g); j++) {
            if (game_has_error(g, i, j))
                printf("Game has error at square(%d,%d)\n", i, j);
        }
    }
}

static square char_to_square(char c) {
    if (c == 'w')
        return (S_ZERO);
    else if (c == 'b')
        return (S_ONE);
    else
        return (S_EMPTY);
}

static void try_play_move(game *g, char c, int i, int j) {
    square s = char_to_square(c);

    if (game_check_move(*g, i, j, s)) {
        printf("> action: play move '%c' into square (%d,%d)\n", c, i, j);
        game_play_move(*g, i, j, s);
    }
}

int main(void) {
    game g = game_load("default.txt");

    char user_input;
    int scanf_return = 0;
    uint i = 0;
    uint j = 0;

    assert(g != NULL);
    while (!game_is_over(g)) {
        game_print(g);
        display_errors(g);
        printf("> ? [h for help]\n");
        if (scanf_return == EOF)
            exit(EXIT_SUCCESS);
        scanf_return = scanf(" %c", &user_input);
        if (strchr("rhqzy", user_input)) {
            command(&g, user_input);
        } else if (strchr("wbe", user_input)) {
            scanf_return = scanf("%d %d", &i, &j);
            if (scanf_return == 2)
                try_play_move(&g, user_input, i, j);
        }
    }
    game_print(g);
    game_delete(g);
    printf("You win congratulation !\n");
    return (EXIT_SUCCESS);
}