#ifndef CELL_H
#define CELL_H

#include <SDL.h>
#include <stdbool.h>

#include "assets.h"
#include "input.h"
#include "text.h"

/* **************************************************************** */

enum cell_type {
    CELL_TYPE_EMPTY,
    CELL_TYPE_BLUE,
    CELL_TYPE_IMM_BLUE,
    CELL_TYPE_RED,
    CELL_TYPE_IMM_RED,
    CELL_TYPE_COUNT
};

struct Cell_s {
    SDL_Rect hitbox;  // default hitbox (full screen 1920x1080)
    SDL_Rect scaled;  // scaled hitbox (current window size)

    int type;
    bool has_error;

    bool pressed;
    bool hovered;
};

typedef struct Cell_s *Cell;

/* **************************************************************** */

Cell cell_create(SDL_Rect hitbox, int type);
void cell_delete(Cell button);
void cell_render(Cell button, Assets assets, SDL_Renderer *ren, SDL_Rect win_rect);

bool cell_pressed(Cell button, Input input, SDL_Rect win_rect, Assets assets);
bool cell_hovered(Cell button, Input input, SDL_Rect win_rect, Assets assets);

#endif /* CELL_H */