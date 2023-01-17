#ifndef _ASSERT_H_
#define _ASSERT_H_

#include "game.h"

/**
 *  @brief Throws an error and outputs the msg on stderr.
 *  @param msg the error message to throw
 *  @pre @p msg must be a valid pointer toward a string.
 **/
bool throw_error(char *msg);

/**
 *  @brief Tests if the game is valid.
 *  @param g the game to test
 *  @param msg the error message to throw
 *  @pre @p g must be a valid pointer toward a game structure.
 *  @pre @p msg must be a valid pointer toward a string.
 *  @return true if the game is valid, false otherwise
 **/
bool game_test(game g, char *msg);

/**
 *  @brief Tests if the cgame is valid.
 *  @param g the cgame to test
 *  @param msg the error message to throw
 *  @pre @p g must be a valid pointer toward a cgame structure.
 *  @pre @p msg must be a valid pointer toward a string.
 *  @return true if the cgame is valid, false otherwise
 **/
bool cgame_test(cgame g, char *msg);

/**
 *  @brief Tests if the pointer is not NULL.
 *  @param ptr the pointer to test
 *  @param msg the error message to throw
 *  @pre @p ptr must be a valid pointer toward a move structure.
 *  @pre @p msg must be a valid pointer toward a string.
 *  @return true if the pointer is valid, false otherwise
 **/
bool pointer_test(void *ptr, char *msg);

#endif /* _ASSERT_H_ */
