#ifndef _MOVE_STACK_H_
#define _MOVE_STACK_H_

#include "game.h"
#include "move.h"

/**
 *  @brief A move stack is a structure that contains a stack of moves.
 **/
struct move_stack_s {
    move *data;
    uint size;
    uint capacity;
};

/**
 * @brief The structure pointer that stores the move stack state.
 **/
typedef struct move_stack_s *ms;

/**
 *  @brief Creates a new move stack.
 *  @param capacity the capacity of the move stack
 *  @return the created move stack
 **/
ms ms_create(uint capacity);

/**
 *  @brief Frees the memory allocated for the move stack.
 *  @param stack the move stack to free
 **/
void ms_delete(ms stack);

/**
 *  @brief double the capacity of the move stack when it is full.
 *  @param stack the move stack
 *  @pre @p stack must be a valid pointer toward a move stack structure.
 **/
void ms_double_capacity(ms stack);


/**
 *  @brief Gets the top move of the move stack.
 *  @param stack the move stack
 *  @pre @p stack must be a valid pointer toward a move stack structure.
 *  @return the top move of the move stack
 **/
move ms_top(ms stack);

/**
 *  @brief Pushes a move to the move stack.
 *  @param stack the move stack
 *  @param m the move to push
 *  @pre @p stack must be a valid pointer toward a move stack structure.
 *  @pre @p m must be a valid pointer toward a move structure.
 **/
void ms_push(ms stack, move m);

/**
 *  @brief Pops a move from the move stack.
 *  @param stack the move stack
 *  @pre @p stack must be a valid pointer toward a move stack structure.
 **/
void ms_pop(ms stack);

/**
 *  @brief Clears the move stack.
 *  @param stack the move stack
 *  @pre @p stack must be a valid pointer toward a move stack structure.
 **/
void ms_clear(ms stack);


/**
 *  @brief Gets the row of the move on the top of the stack.
 *  @param stack the move stack
 *  @pre @p stack must be a valid pointer toward a move stack structure.
 *  @return the row of the move on the top of the stack
 **/
int ms_top_row(ms stack);

/**
 *  @brief Gets the column of the move on the top of the stack.
 *  @param stack the move stack
 *  @pre @p stack must be a valid pointer toward a move stack structure.
 *  @return the column of the move on the top of the stack
 **/
int ms_top_col(ms stack);

/**
 *  @brief Gets the square to place of the move on the top of the stack.
 *  @param stack the move stack
 *  @pre @p stack must be a valid pointer toward a move stack structure.
 *  @return the square to place of the move on the top of the stack
 **/
int ms_top_s(ms stack);

/**
 *  @brief Gets the square to replace of the move on the top of the stack.
 *  @param stack the move stack
 *  @pre @p stack must be a valid pointer toward a move stack structure.
 *  @return the square to replace of the move on the top of the stack
 **/
int ms_top_p(ms stack);

/**
 *  @brief Checks if the move stack is empty.
 *  @param stack the move stack
 *  @pre @p stack must be a valid pointer toward a move stack structure.
 *  @return true if the move stack is empty, false otherwise
 **/
bool ms_is_empty(ms stack);

/**
 *  @brief Checks if the move stack is full.
 *  @param stack the move stack
 *  @pre @p stack must be a valid pointer toward a move stack structure.
 *  @return true if the move stack is full, false otherwise
 **/
bool ms_is_full(ms stack);

/**
 *  @brief Prints the move stack.
 *  @param stack the move stack
 *  @pre @p stack must be a valid pointer toward a move stack structure.
 **/
void ms_print(ms stack);

#endif /* _MOVE_STACK_H_ */