#include "game_aux.h"

#include <stdio.h>

#include "game.h"
void game_print(cgame g) {
  int squareValue;
  square squareindice;
  for (int i = 0; i < DEFAULT_SIZE + 3; i++) {
    for (int j = 0; j < DEFAULT_SIZE + 3; j++) {
      if ((i == 0 && j == 0) || (i == 1 && j == 0) || (i == 0 && j == 1) ||
          (i == 1 && j == 1) || (i == 0 && j == 8) || (i == 1 && j == 8) ||
          (i == 8 && j == 0) || (i == 8 && j == 1) || (i == 8 && j == 8)) {
        printf("%c", ' ');
      }
      if (i == 0 && (j >= 2 && j <= DEFAULT_SIZE + 1)) {
        printf("%d", j - 2);
      }
      if (j == 0 && (i >= 2 && i <= DEFAULT_SIZE + 1)) {
        printf("%d", i - 2);
      }
      if ((i == 1 || i == 7) && (j >= 2 && j <= DEFAULT_SIZE + 1)) {
        printf("%c", '-');
      }
      if ((j == 1 || j == 7) && (i >= 2 && i <= DEFAULT_SIZE + 1, i + 2)) {
        printf("%c", '|');
      }

      if (i >= 2 && j >= 2 && i <= 7 && j <= 7) {
        squareValue = game_get_square(g, i - 2, j - 2);
        switch (squareValue) {
          case S_EMPTY:

            printf("%c", ' \t');
            break;
          case S_ZERO:
            printf("%c", 'b\t');
            break;
          case S_ONE:
            printf("%c", 'w\t');
            break;
          case S_IMMUTABLE_ZERO:
            printf("%c", 'W\t');
            break;
          case S_IMMUTABLE_ONE:
            printf("%c", 'B\t');
            break;
        }
      }
    }
    printf("\n");
  }
}
game game_default(void) {
  square s[36];
  for (int i = 0; i < 36; i++) {
    if ((i == 3) && (i == 14) && (i == 17) && (i == 20) && (i == 30) &&
        (i == 36)) {
      s[i] = S_IMMUTABLE_ZERO;
    }
    if ((i == 21) && (i == 27)) {
      s[i] = S_IMMUTABLE_ONE;
    } else
      s[i] = S_EMPTY;
  }
  return game_new(s);
}
game game_default_solution(void) {
  game g = game_default();
  game_play_move(g, 0, 0, S_ONE);
  game_play_move(g, 0, 1, S_ONE);
  game_play_move(g, 0, 4, S_ONE);
  game_play_move(g, 1, 5, S_ONE);
  game_play_move(g, 2, 5, S_ONE);
  game_play_move(g, 2, 2, S_ONE);
  game_play_move(g, 3, 1, S_ONE);
  game_play_move(g, 3, 3, S_ONE);
  game_play_move(g, 3, 4, S_ONE);
  game_play_move(g, 4, 0, S_ONE);
  game_play_move(g, 4, 3, S_ONE);
  game_play_move(g, 5, 1, S_ONE);
  game_play_move(g, 3, 0, S_ZERO);
  game_play_move(g, 5, 0, S_ZERO);
  game_play_move(g, 1, 1, S_ZERO);
  game_play_move(g, 2, 1, S_ZERO);
  game_play_move(g, 5, 0, S_ZERO);
  game_play_move(g, 1, 1, S_ZERO);
  game_play_move(g, 2, 1, S_ZERO);
  game_play_move(g, 4, 1, S_ZERO);

  game_play_move(g, 0, 3, S_ZERO);
  game_play_move(g, 5, 3, S_ZERO);
  game_play_move(g, 0, 5, S_ZERO);
  game_play_move(g, 4, 5, S_ZERO);
}
