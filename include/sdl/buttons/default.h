#ifndef DEFAULT_H
#define DEFAULT_H

#include <SDL.h>
#include <stdbool.h>

#include "assets.h"
#include "input.h"
#include "text.h"

/* **************************************************************** */

struct Default_s {
    int type;

    Text label;

    SDL_Rect hitbox;  // default hitbox (full screen 1920x1080)
    SDL_Rect scaled;  // scaled hitbox (current window size)

    bool hovered;
};

typedef struct Default_s *Default;

/* **************************************************************** */

Default default_create(SDL_Rect hitbox, char *label, int type, Assets assets, SDL_Renderer *ren);
void default_delete(Default button);
void default_render(Default button, Assets assets, SDL_Renderer *ren, SDL_Rect win_rect, Input input);

bool default_pressed(Default button, Input input, SDL_Rect win_rect, Assets assets);
bool default_hovered(Default button, Input input, SDL_Rect win_rect, Assets assets);

#endif /* DEFAULT_H */