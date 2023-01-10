#ifndef _ASSERT_H_
#define _ASSERT_H_

#include "game.h"

void throw_error(char *msg);
void game_test(game g, char *msg);
void cgame_test(cgame g, char *msg);
void pointer_test(void *ptr, char *msg);

#endif /* _ASSERT_H_ */