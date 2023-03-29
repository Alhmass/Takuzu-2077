#ifndef TOGGLE_H
#define TOGGLE_H

#include <SDL.h>
#include <stdbool.h>

#include "assets.h"
#include "input.h"

/* **************************************************************** */

struct Toggle_s {
    SDL_Rect render_hitbox;  // hitbox for rendering
    SDL_Rect scaled_hitbox;  // scaled hitbox for rendering

    SDL_Rect hitbox_off;  // toggle_off hitbox
    SDL_Rect scaled_off;  // scaled toggle_off hitbox

    SDL_Rect hitbox_on;  // toggle_on hitbox
    SDL_Rect scaled_on;  // scaled toggle_on hitbox

    bool state;  // switch state

    bool hovered;
};

typedef struct Toggle_s *Toggle;

/* **************************************************************** */

Toggle toggle_create(SDL_Rect hitbox, bool default_state);
void toggle_delete(Toggle button);
void toggle_render(Toggle button, Assets assets, SDL_Renderer *ren, SDL_Rect win_rect);

bool toggle_pressed(Toggle button, Input input, SDL_Rect win_rect, Assets assets);
bool toggle_hovered(Toggle button, Input input, SDL_Rect win_rect, Assets assets);

#endif /* TOGGLE_H */