#include "graphics.h"

#include "button.h"
#include "env.h"
#include "input.h"

/* **************************************************************** */

void graphics_init(Scene graphics, Assets assets, SDL_Renderer *ren) {
    scene_init(graphics, 0, 0, 0, 0, 0, 0, 0);
    (void)assets;
    (void)ren;
}

void graphics_process(Scene *scenes, Input input, Assets assets, SDL_Renderer *ren, SDL_Rect win_rect) {
    if (scenes[GRAPHICS]->is_active == false)
        return;

    (void)assets;
    (void)ren;

    SDL_Rect hitbox = {418, 67, 142, 28};
    hitbox = scale_rect(hitbox, win_rect);
    if (left_click(hitbox, input)) {
        scenes[SOUNDS]->is_active = true;
        scenes[GRAPHICS]->is_active = false;
    }

    hitbox = (SDL_Rect){715, 67, 180, 28};
    hitbox = scale_rect(hitbox, win_rect);
    if (left_click(hitbox, input)) {
        scenes[CONTROLS]->is_active = true;
        scenes[GRAPHICS]->is_active = false;
    }

    hitbox = (SDL_Rect){1394, 67, 107, 28};
    hitbox = scale_rect(hitbox, win_rect);
    if (left_click(hitbox, input)) {
        scenes[STATS]->is_active = true;
        scenes[GRAPHICS]->is_active = false;
    }
}

/* **************************************************************** */
