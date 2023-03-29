#ifndef SWITCH_H
#define SWITCH_H

#include <SDL.h>
#include <stdbool.h>

#include "assets.h"
#include "input.h"

/* **************************************************************** */

struct Switch_s {
    SDL_Rect render_hitbox;  // hitbox for rendering
    SDL_Rect scaled_hitbox;  // scaled hitbox for rendering

    SDL_Rect hitbox;  // hitbox for input
    SDL_Rect scaled;  // scaled hitbox for input

    bool state;  // switch button state

    bool hovered;
};

typedef struct Switch_s *Switch;

/* **************************************************************** */

Switch switch_create(SDL_Rect hitbox, bool default_state);
void switch_delete(Switch button);
void switch_render(Switch button, Assets assets, SDL_Renderer *ren, SDL_Rect win_rect);

bool switch_pressed(Switch button, Input input, SDL_Rect win_rect, Assets assets);
bool switch_hovered(Switch button, Input input, SDL_Rect win_rect, Assets assets);

#endif /* SWITCH_H */