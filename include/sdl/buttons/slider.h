#ifndef SLIDER_H
#define SLIDER_H

#include <SDL.h>
#include <stdbool.h>

#include "assets.h"
#include "input.h"
#include "text.h"

/* **************************************************************** */

struct Slider_s {
    Text label;

    SDL_Rect hitbox;  // default hitbox (full screen 1920x1080)
    SDL_Rect scaled;  // scaled hitbox (current window size)

    SDL_Rect cursor_hitbox;
    SDL_Rect cursor_scaled;

    int value;
    int min;
    int max;

    bool dragged;
    bool hovered;
};

typedef struct Slider_s *Slider;

/* **************************************************************** */

Slider slider_create(SDL_Rect hitbox, int value, int min, int max, Assets assets, SDL_Renderer *ren);
void slider_delete(Slider button);
void slider_render(Slider button, Assets assets, SDL_Renderer *ren, SDL_Rect win_rect, Input input);

bool slider_dragged(Slider button, Input input, Assets assets, SDL_Renderer *ren, SDL_Rect win_rect);
bool slider_hovered(Slider button, Input input, SDL_Rect win_rect, Assets assets);

#endif /* SLIDER_H */