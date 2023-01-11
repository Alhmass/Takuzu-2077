#ifndef _ASSERT_H_
#define _ASSERT_H_

#include "game.h"

bool throw_error(char *msg);
bool game_test(game g, char *msg);
bool cgame_test(cgame g, char *msg);
bool pointer_test(void *ptr, char *msg);

#endif /* _ASSERT_H_ */
