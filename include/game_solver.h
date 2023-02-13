/**
 * @file game_solver.h
 * @brief Game Solver.
 * @details See @ref index for further details.
 * @copyright University of Bordeaux. All rights reserved, 2023.
 *
 **/

#ifndef __GAME_SOLVER_H
#define __GAME_SOLVER_H
#include <stdbool.h>
#include <stdio.h>

#include "game.h"

/**
 * @name Game Solver
 * @{
 */

/**
 * @brief Find all solutions of a game
 * @param g Game
 * @param pos Position in the word
 * @param word Binary word
 * @param nb_solutions Number of solutions found
 * @param mode Mode for the solver : 0 search for the first solution, 1 search for all solutions
 */
void find_solutions(game g, int pos, int *word, uint *nb_solutions, int mode);

/**
 * @brief Check if a word is a solution
 * @param g Game
 * @param word Binary Word
 * @param nb_solutions Number of solutions found
 * @param mode Mode for the solver : 0 search for the first solution, 1 search for all solutions
 * @return True if the word is a solution, false otherwise
 */
bool is_word_solution(game g, int *word, int nb_zero, int nb_one, uint nb_solutions, int mode);

/**
 * @brief Copy the squares from src to dest
 * @param dest Destination game
 * @param src Source game
 */
void copy_squares(game dest, game src);

/**
 * @brief Print a word
 * @param word Binary Word
 * @param len Length of the word
 */
void print_word(int *word, int len);

#endif  // __GAME_SOLVER_H__