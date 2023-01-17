#ifndef _MOVE_H_
#define _MOVE_H_

#include "game.h"

/**
 *  @brief A move is a structure that contains the row and column of the move,
 *  the square to place and the square to replace.
 **/
struct move_s {
    uint row;
    uint col;
    square s;
    square p;
};

/**
 * @brief The structure pointer that stores the move state.
 **/
typedef struct move_s *move;

/**
 *  @brief Creates a new move.
 *  @param row the row of the move
 *  @param col the column of the move
 *  @param s the square to place
 *  @param p the square to replace
 *  @return the created move
 **/
move move_create(uint row, uint col, square s, square p);

/**
 *  @brief Frees the memory allocated for the move.
 *  @param m the move to free
 **/
void move_delete(move m);

/**
 *  @brief Gets the row of the move.
 *  @param m the move
 *  @pre @p m must be a valid pointer toward a move structure.
 *  @return the row of the move
 **/
uint move_row(move m);

/**
 *  @brief Gets the column of the move.
 *  @param m the move
 *  @pre @p m must be a valid pointer toward a move structure.
 *  @return the column of the move
 **/
uint move_col(move m);

/**
 *  @brief Gets the square to place.
 *  @param m the move
 *  @pre @p m must be a valid pointer toward a move structure.
 *  @return the square to place
 **/
square move_s(move m);

/**
 *  @brief Gets the square to replace.
 *  @param m the move
 *  @pre @p m must be a valid pointer toward a move structure.
 *  @return the square to replace
 **/
square move_p(move m);

/**
 *  @brief Prints the move on the standard output stream.
 *  @param m the move
 *  @pre @p m must be a valid pointer toward a move structure.
 **/
void move_print(move m);

#endif /* _MOVE_H_ */