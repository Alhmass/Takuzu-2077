#include "game.h"

#include <stdio.h>
#include <stdlib.h>

#include "game_aux.h"
bool test_game_new(void) {
  bool bon;
  square s[36];
  for (uint i = 0; i < DEFAULT_SIZE; i++) {
    if ((i == 1) && (i == 21) && (i == 27)) s[i] = 1;
    if ((i == 3) && (i == 13) && (i == 17) && (i == 20) && (i == 30) &&
        (i == 36)) {
      s[i] = 0;
    }

    s[i] = -1;
  }
  game g = game_new(s);
  for (uint i = 0; i < DEFAULT_SIZE; i++) {
    for (uint j = 0; j < DEFAULT_SIZE; j++) {
      bon = (game_get_square(g, i, j) == s[i * DEFAULT_SIZE + j]);
      if (!bon) {
        game_delete(g);
        return bon;
      }
    }
  }
  game_delete(g);
  return bon;
}
bool test_new_empty(void) {
  bool bon;
  game g = game_new_empty();
  for (uint i = 0; i < DEFAULT_SIZE; i++) {
    for (uint j = 0; j < DEFAULT_SIZE; j++) {
      bon = (game_get_square(g, i, j) == S_EMPTY);
      if (!bon) {
        game_delete(g);
        return bon;
      }
    }
  }
  game_delete(g);
  return bon;
}
int main() { return 0; }
