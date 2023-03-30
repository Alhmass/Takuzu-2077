#include "stats.h"

#include "button.h"
#include "env.h"
#include "input.h"

/* **************************************************************** */

void stats_init(Conf conf, Scene stats, Assets assets, SDL_Renderer *ren) {
    scene_init(stats, 0, 0, 0, 0, 0, 0, 5);
    (void)conf;
    (void)assets;
    (void)ren;

    SDL_Rect hitbox = {450, 390, 100, 100};
    stats->text[0]=text_create(assets, "00:00:00", RAJDHANI_MED, LIGHT_BLUE, hitbox, ren);

    hitbox = (SDL_Rect){450, 530, 100, 100};
    stats->text[1]=text_create(assets, "00:00:00", RAJDHANI_MED, LIGHT_BLUE, hitbox, ren);

    hitbox = (SDL_Rect){450, 660, 100, 100};
    stats->text[2]=text_create(assets, "00:00:00", RAJDHANI_MED, LIGHT_BLUE, hitbox, ren);

    hitbox = (SDL_Rect){450, 800, 100, 100};
    stats->text[3]=text_create(assets, "00:00:00", RAJDHANI_MED, LIGHT_BLUE, hitbox, ren);

    hitbox = (SDL_Rect){450, 930, 100, 100};
    stats->text[4]=text_create(assets, "00:00:00", RAJDHANI_MED, LIGHT_BLUE, hitbox, ren);
}

void stats_process(Conf conf, Scene *scenes, Input input, Assets assets, SDL_Renderer *ren, SDL_Rect win_rect) {
    if (scenes[STATS]->is_active == false)
        return;

    (void)assets;
    (void)conf;
    (void)ren;

    SDL_Rect hitbox = {418, 67, 142, 28};
    hitbox = scale_rect(hitbox, win_rect);
    if (left_click(hitbox, input)) {
        Mix_PlayChannel(-1, SOUND(assets, SOUND_SWIPE), 0);
        scenes[SOUNDS]->is_active = true;
        scenes[STATS]->is_active = false;
    }

    hitbox = (SDL_Rect){715, 67, 180, 28};
    hitbox = scale_rect(hitbox, win_rect);
    if (left_click(hitbox, input)) {
        Mix_PlayChannel(-1, SOUND(assets, SOUND_SWIPE), 0);
        scenes[CONTROLS]->is_active = true;
        scenes[STATS]->is_active = false;
    }

    hitbox = (SDL_Rect){1017, 67, 170, 28};
    hitbox = scale_rect(hitbox, win_rect);
    if (left_click(hitbox, input)) {
        Mix_PlayChannel(-1, SOUND(assets, SOUND_SWIPE), 0);
        scenes[GRAPHICS]->is_active = true;
        scenes[STATS]->is_active = false;
    }

    // Keyboard Input
    if (input->key_code == SDLK_ESCAPE) {
        scenes[STATS]->is_active = false;
        scenes[conf->last_scene]->is_active = true;
    }

    // if (key_down(input, SDLK_LEFT)) {
    //     Mix_PlayChannel(-1, SOUND(assets, SOUND_SWIPE), 0);
    //     scenes[GRAPHICS]->is_active = true;
    //     scenes[STATS]->is_active = false;
    // }

    // if (key_down(input, SDLK_RIGHT)) {
    //     Mix_PlayChannel(-1, SOUND(assets, SOUND_SWIPE), 0);
    //     scenes[SOUNDS]->is_active = true;
    //     scenes[STATS]->is_active = false;
    // }
}

/* **************************************************************** */
