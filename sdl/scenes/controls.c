#include "controls.h"

#include "button.h"
#include "env.h"
#include "input.h"

/* **************************************************************** */

void controls_init(Conf conf, Scene controls, Assets assets, SDL_Renderer *ren) {
    scene_init(controls, 0, 0, 0, 0, 0, 0, 0);

    (void)conf;
    (void)assets;
    (void)ren;
}

void controls_process(Conf conf, Scene *scenes, Input input, Assets assets, SDL_Renderer *ren, SDL_Rect win_rect) {
    if (scenes[CONTROLS]->is_active == false)
        return;

    (void)conf;
    (void)ren;

    SDL_Rect hitbox = {418, 67, 142, 28};
    hitbox = scale_rect(hitbox, win_rect);
    if (left_click(hitbox, input)) {
        Mix_PlayChannel(-1, SOUND(assets, SOUND_SWIPE), 0);
        scenes[SOUNDS]->is_active = true;
        scenes[CONTROLS]->is_active = false;
    }

    hitbox = (SDL_Rect){1055, 67, 174, 28};
    hitbox = scale_rect(hitbox, win_rect);
    if (left_click(hitbox, input)) {
        Mix_PlayChannel(-1, SOUND(assets, SOUND_SWIPE), 0);
        scenes[GRAPHICS]->is_active = true;
        scenes[CONTROLS]->is_active = false;
    }

    hitbox = (SDL_Rect){1394, 67, 107, 28};
    hitbox = scale_rect(hitbox, win_rect);
    if (left_click(hitbox, input)) {
        Mix_PlayChannel(-1, SOUND(assets, SOUND_SWIPE), 0);
        scenes[STATS]->is_active = true;
        scenes[CONTROLS]->is_active = false;
    }

    // Keyboard Input
    if (input->key_code == SDLK_ESCAPE) {
        scenes[CONTROLS]->is_active = false;
        scenes[conf->last_scene]->is_active = true;
    }
}

/* **************************************************************** */
