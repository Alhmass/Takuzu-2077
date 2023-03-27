#ifndef DEFAULT_H
#define DEFAULT_H

#include <SDL.h>
#include <stdbool.h>

#include "assets.h"
#include "input.h"
#include "text.h"

/* **************************************************************** */

enum default_type {
    DEF_TYPE_BLUE,
    DEF_TYPE_BLUE_T,
    DEF_TYPE_BLUE_HOVER,
    DEF_TYPE_RED,
    DEF_TYPE_RED_T,
    DEF_TYPE_RED_HOVER,
    DEF_TYPE_COUNT
};

struct Default_s {
    int type;

    Text label;

    SDL_Rect hitbox;  // default hitbox (full screen 1920x1080)
    SDL_Rect scaled;  // scaled hitbox (current window size)

    // label hitbox, used for rendering
    SDL_Rect label_hitbox;
    SDL_Rect label_scaled;

    bool pressed;
    bool hovered;
};

typedef struct Default_s *Default;

/* **************************************************************** */

Default default_create(SDL_Rect hitbox, char *label, int type, Assets assets, SDL_Renderer *ren);
void default_delete(Default button);
void default_render(Default button, Assets assets, SDL_Renderer *ren, SDL_Rect win_rect);

bool default_pressed(Default button, Input input, SDL_Rect win_rect, Assets assets);
bool default_hovered(Default button, Input input, SDL_Rect win_rect, Assets assets);

#endif /* DEFAULT_H */