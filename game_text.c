#include <stdio.h>
#include <stdlib.h>

#include "game.h"
#include "game_aux.h"
#define SUCCESS 0
void game_help() {
  printf("%s\n", "action: help");
  printf("%s\n", "- press 'w <i> <j>' to put a white square at square(i,j)");
  printf("%s\n", "- press 'b <i> <j>' to put a black at square(i,j)");
  printf("%s\n", "- press 'r' to restart");
  printf("%s\n", "- press 'q' to quit");
}

int main(void) {
  game g = game_default();
  game f = game_default_solution();

  while (!game_is_over(g)) {
    int i, j;
    char c;

    scanf(" %c", &c);
    game_print(g);
    for (int i = 0; i < DEFAULT_SIZE; i++) {
      for (int j = 0; j < DEFAULT_SIZE; j++) {
        if (game_has_error(g, i, j)) {
          printf("error at square (%d,%d)\n", i, j);
        }
      }
    }

    printf("> ? [h for help]\n");

    if (c == 'h') {
      game_help();
    } else if (c == 'r') {
      game_restart(g);
    } else if (c == 'q') {
      printf("what a shame on you this solution to try again \n");
      game_print(f);
      exit(0);
    } else if (c == 'w' || c == 'b') {
      scanf(" %d %d", &i, &j);
      if (game_check_move(g, i, j, game_get_square(g, i, j))) {
        switch (c) {
          case 'w':
            printf("> action: play move 'w' into square(%d,%d)\n", i, j);
            game_set_square(g, i, j, S_ZERO);
            game_play_move(g, i, j, game_get_square(g, i, j));

            break;
          case 'b':
            printf("> action: play move 'b' into square(%d,%d)\n", i, j);
            game_set_square(g, i, j, S_ONE);
            game_play_move(g, i, j, game_get_square(g, i, j));
            break;
          case 'e':
            printf("> action: play move 'b' into square(%d,%d)\n", i, j);
            game_set_square(g, i, j, S_EMPTY);
            game_play_move(g, i, j, game_get_square(g, i, j));
            break;
          default:
            game_help();
        }
        game_print(g);
      }
    }
  }

  game_help();

  game_print(g);

  printf("congratulations !!\n");
  return EXIT_SUCCESS;
}
