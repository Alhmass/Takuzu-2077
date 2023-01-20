#ifndef _MODE_ERROR_H_
#define _MODE_ERROR_H_

#include "game.h"

/**
 * @brief creates an array containing the squares of the row i
 * @param g pointer to the game
 * @param i row index
 * @return the square array
 **/
square *get_row(cgame g, uint i);

/**
 * @brief creates an array containing the squares of the column j
 * @param g pointer to the game
 * @param j column index
 * @return the square array
 **/
square *get_col(cgame g, uint j);

/**
 * @brief modifies the array by applying a left rotation
 * @param array the array to rotate
 * @param size the size of the array
 **/
void rotate_array(square *array, uint size);

/**
 * @brief same as game_get_number but takes a square as parameter
 * @param s the square
 * @return the number (-1 if empty, 0 if S_ZERO or S_IMMUTABLE_ZERO, 1 if S_ONE or S_IMMUTABLE_ONE)
 **/
int get_number(square s);

/**
 * @brief checks if the array contains 3 consecutive numbers
 * @param array the array to check
 * @param size the size of the array
 * @param current the current number
 * @return true if the array contains 3 consecutive numbers, false otherwise
 **/
bool is_consecutive(square *array, uint size, int current);

/**
 * @brief checks if one of the arrays contains 3 consecutive numbers
 * @param g pointer to the game
 * @param i row index
 * @param j column index
 * @return true if the array contains 3 consecutive numbers, false otherwise
 **/
bool is_consecutive_grid(cgame g, uint i, uint j);

/**
 * @brief checks if the array is full (contains no S_EMPTY)
 * @param array the array to check
 * @param size the size of the array
 * @return true if the array is full, false otherwise
 **/
bool is_array_full(square *array, uint size);

/**
 * @brief checks if array1 and array2 are the same (using get_number)
 * @param array1 the first array to compare
 * @param array2 the second array to compare
 * @param size the size of the array
 * @pre array1 and array2 must have the same size
 * @return true if array1 and array2 are the same, false otherwise
 **/
bool is_array_same(square *array1, square *array2, uint size);

/**
 * @brief checks if the row i and column j are unique in the game
 * @param g pointer to the game
 * @param i row index
 * @param j column index
 * @return true if the row i and column j are unique, false otherwise
 **/
bool is_unique_array(cgame g, uint i, uint j);

/**
 * @brief prints and array (used to debug)
 * @param array the array to print
 * @param size the size of the array
 **/
void print_array(square *array, uint size);

#endif /* _MODE_ERROR_H_ */