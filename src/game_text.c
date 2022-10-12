#include <stdlib.h>
#include "game.h"
#include "game_aux.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

static void display_help(void)
{
    printf("> action: help\n");
    printf("- press 'w <i> <j>' to put a zero/white at square (i,j)\n");
    printf("- press 'b <i> <j>' to put a one/black at square (i,j)\n");
    printf("- press 'e <i> <j>' to empty square (i,j)\n");
    printf("- press 'r' to restart\n");
    printf("- press 'q' to quit\n");
}

static void command(char c, game *g)
{
    if (c == 'r') {
        printf("> action: restart\n");
        game_restart(*g);
    }
    else if (c == 'h')
        display_help();
    else {
        printf("> action: quit\n");
        printf("What a shame you gave up :-(\n");
        game_delete(*g);
        exit(EXIT_SUCCESS);
    }
}

static void display_errors(const game *g)
{
    int status = 0;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            status = game_has_error(*g, i, j);
            if (status != 0) {
                printf("Game has error at square(%d,%d)\n", i, j);
                status = 0;
            }
        }
    }
}

static square char_to_square(char c)
{
    if (c == 'w')
        return (S_ZERO);
    else if (c == 'b')
        return (S_ONE);
    else
        return (S_EMPTY); 
}

static void try_play_move(game *g, char c, int i, int j)
{
    square s = char_to_square(c);

    if (game_check_move(*g, i, j, s)) {
        printf("> action: play move '%c' into square (%d,%d)\n", c, i, j);
        game_play_move(*g, i, j, s);
    }
}

int main(void)
{
    game g = game_default();
    char c;
    int i = 0;
    int j = 0;
    int r = 0;

    assert(g != NULL);
    while (!game_is_over(g)) {
        game_print(g);
        display_errors(&g);
        printf("> ? [h for help]\n");
        if (r == EOF)
            exit(EXIT_SUCCESS);
        r = scanf(" %c", &c);
        if (strchr("rhq", c))
            command(c, &g);
        else if (strchr("wbe", c)) {
            r = scanf("%d %d", &i, &j);
            if (r == 2)
                try_play_move(&g, c, i, j);
        }
    }
    game_print(g);
    game_delete(g);
    printf("You win congratulation !\n");
    return (EXIT_SUCCESS);
}