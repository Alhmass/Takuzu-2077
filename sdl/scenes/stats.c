#include "stats.h"

#include "button.h"
#include "env.h"
#include "input.h"
#include "file.h"

/* **************************************************************** */

char* pathfile = "../configuration/conf.txt";

void stats_init(Conf conf, Scene stats, Assets assets, SDL_Renderer *ren) {
    scene_init(stats, 0, 0, 0, 0, 0, 0, 8);
    (void)conf;
    (void)assets;
    (void)ren;

    SDL_Rect hitbox = {450, 390, 100, 100};
    stats->text[0]=text_create(assets, get_setting(pathfile, "4x4"), RAJDHANI_MED, LIGHT_BLUE, hitbox, ren);

    hitbox = (SDL_Rect){450, 530, 100, 100};
    stats->text[1]=text_create(assets, get_setting(pathfile, "6x6"), RAJDHANI_MED, LIGHT_BLUE, hitbox, ren);

    hitbox = (SDL_Rect){450, 660, 100, 100};
    stats->text[2]=text_create(assets, get_setting(pathfile, "8x8"), RAJDHANI_MED, LIGHT_BLUE, hitbox, ren);

    hitbox = (SDL_Rect){450, 800, 100, 100};
    stats->text[3]=text_create(assets, get_setting(pathfile, "10x10"), RAJDHANI_MED, LIGHT_BLUE, hitbox, ren);

    hitbox = (SDL_Rect){450, 930, 100, 100};
    stats->text[4]=text_create(assets, get_setting(pathfile, "12x12"), RAJDHANI_MED, LIGHT_BLUE, hitbox, ren);

    hitbox = (SDL_Rect){900, 390, 100, 100};
    stats->text[5]=text_create(assets, get_setting(pathfile, "nb_solved"), RAJDHANI_MED, LIGHT_BLUE, hitbox, ren);

    hitbox = (SDL_Rect){900, 530, 100, 100};
    stats->text[6]=text_create(assets, get_setting(pathfile, "total_time"), RAJDHANI_MED, LIGHT_BLUE, hitbox, ren);

    hitbox = (SDL_Rect){900, 660, 100, 100};
    stats->text[7]=text_create(assets, (get_setting(pathfile, "overall_accuracy")), RAJDHANI_MED, LIGHT_BLUE, hitbox, ren);
}

void stats_process(Conf conf, Scene *scenes, Input input, Assets assets, SDL_Renderer *ren, SDL_Rect win_rect) {
    if (scenes[STATS]->is_active == false)
        return;

    (void)assets;
    (void)conf;
    (void)ren;

    scenes[STATS]->text[0] = text_set_text(scenes[STATS]->text[0], get_setting(pathfile, "4x4"), assets, ren);
    scenes[STATS]->text[1] = text_set_text(scenes[STATS]->text[1], get_setting(pathfile, "6x6"), assets, ren);
    scenes[STATS]->text[2] = text_set_text(scenes[STATS]->text[2], get_setting(pathfile, "8x8"), assets, ren);
    scenes[STATS]->text[3] = text_set_text(scenes[STATS]->text[3], get_setting(pathfile, "10x10"), assets, ren);
    scenes[STATS]->text[4] = text_set_text(scenes[STATS]->text[4], get_setting(pathfile, "12x12"), assets, ren);
    scenes[STATS]->text[5] = text_set_text(scenes[STATS]->text[5], get_setting(pathfile, "nb_solved"), assets, ren);
    scenes[STATS]->text[6] = text_set_text(scenes[STATS]->text[6], get_setting(pathfile, "total_time"), assets, ren);
    scenes[STATS]->text[7] = text_set_text(scenes[STATS]->text[7], get_setting(pathfile, "overall_accuracy"), assets, ren);

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
