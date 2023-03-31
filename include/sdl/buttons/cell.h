#ifndef CELL_H
#define CELL_H

#include <SDL.h>
#include <stdbool.h>

#include "assets.h"
#include "input.h"
#include "text.h"

/* **************************************************************** */

/**
 * @brief Cell structure definition
 * @param hitbox the default hitbox
 * @param scaled the scaled hitbox
 * @param type the type of the cell (based on the enum square in game.h)
 * @param has_error true if the cell has an error
 * @param hovered true if the cell is hovered
 */
struct Cell_s {
    SDL_Rect hitbox;  // used for the 1920x1080 resolution
    SDL_Rect scaled;  // used for the current window size

    int type;
    bool has_error;
    bool hovered;
};

/**
 * @brief Cell type definition
 */
typedef struct Cell_s *Cell;

/* **************************************************************** */

/**
 * @brief create a new cell
 * @param hitbox the default hitbox
 * @param type the type of the cell
 * @return Cell
 */
Cell cell_create(SDL_Rect hitbox, int type);

/**
 * @brief delete a cell
 * @param button the cell to delete
 */
void cell_delete(Cell button);

/**
 * @brief render a cell
 * @param button the cell to render
 * @param assets the assets to use
 * @param ren the renderer
 * @param win_rect the current window size
 * @param input the inputs
 */
void cell_render(Cell button, Assets assets, SDL_Renderer *ren, SDL_Rect win_rect, Input input);

/**
 * @brief check if a cell is pressed
 * @param button the cell to check
 * @param input the inputs
 * @param win_rect the current window size
 * @param assets the assets to use
 * @return true if the cell is pressed, false otherwise
 */
bool cell_pressed(Cell button, Input input, SDL_Rect win_rect, Assets assets);

/**
 * @brief check if a cell is hovered
 * @param button the cell to check
 * @param input the inputs
 * @param win_rect the current window size
 * @param assets the assets to use
 * @return true if the cell is hovered, false otherwise
 */
bool cell_hovered(Cell button, Input input, SDL_Rect win_rect, Assets assets);

#endif /* CELL_H */