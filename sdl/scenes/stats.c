#include "stats.h"

#include "button.h"
#include "env.h"
#include "input.h"

/* **************************************************************** */

void stats_init(Scene stats, Assets assets, SDL_Renderer *ren) {
    scene_init(stats, 0, 0, 0, 0, 0, 0, 0);
    (void)assets;
    (void)ren;
}

void stats_process(Scene *scenes, Input input, Assets assets, SDL_Renderer *ren, SDL_Rect win_rect) {
    if (scenes[STATS]->is_active == false)
        return;

    (void)assets;
    (void)ren;

    SDL_Rect hitbox = {418, 67, 142, 28};
    hitbox = scale_rect(hitbox, win_rect);
    if (is_clicked(hitbox, input)) {
        scenes[SOUNDS]->is_active = true;
        scenes[STATS]->is_active = false;
    }

    hitbox = (SDL_Rect){715, 67, 180, 28};
    hitbox = scale_rect(hitbox, win_rect);
    if (is_clicked(hitbox, input)) {
        scenes[CONTROLS]->is_active = true;
        scenes[STATS]->is_active = false;
    }

    hitbox = (SDL_Rect){1017, 67, 170, 28};
    hitbox = scale_rect(hitbox, win_rect);
    if (is_clicked(hitbox, input)) {
        scenes[GRAPHICS]->is_active = true;
        scenes[STATS]->is_active = false;
    }
}

/* **************************************************************** */
