#include "graphics.h"

#include "button.h"
#include "env.h"
#include "input.h"

/* **************************************************************** */

void graphics_init(Conf conf, Scene graphics, Assets assets, SDL_Renderer *ren) {
    scene_init(graphics, 0, 0, 6, 1, 0, 0, 0);
    (void)conf;

    SDL_Rect hitbox = {842, 283, 660, 59};
    char *choices[7] = {"960 x 540", "1024 x 576", "1152 x 648", "1280 x 720", "1366 x 768", "1600 x 900"};
    graphics->choice_b[0] = choice_create(hitbox, choices, 6, 5, assets, ren);

    hitbox = (SDL_Rect){842, 359, 660, 59};
    graphics->toggle_b[0] = toggle_create(hitbox, false);

    hitbox = (SDL_Rect){842, 435, 660, 59};
    graphics->toggle_b[1] = toggle_create(hitbox, true);

    hitbox = (SDL_Rect){842, 632, 660, 59};
    graphics->toggle_b[2] = toggle_create(hitbox, true);

    hitbox = (SDL_Rect){842, 707, 660, 59};
    graphics->toggle_b[3] = toggle_create(hitbox, true);

    hitbox = (SDL_Rect){842, 783, 660, 59};
    graphics->toggle_b[4] = toggle_create(hitbox, true);

    hitbox = (SDL_Rect){842, 859, 660, 59};
    graphics->toggle_b[5] = toggle_create(hitbox, true);
}

void graphics_process(Conf conf, Scene *scenes, Input input, Assets assets, SDL_Renderer *ren, SDL_Rect win_rect) {
    if (scenes[GRAPHICS]->is_active == false)
        return;

    (void)conf;
    (void)ren;

    SDL_Rect hitbox = {418, 67, 142, 28};
    hitbox = scale_rect(hitbox, win_rect);
    if (left_click(hitbox, input)) {
        Mix_PlayChannel(-1, SOUND(assets, SOUND_SWIPE), 0);
        scenes[SOUNDS]->is_active = true;
        scenes[GRAPHICS]->is_active = false;
    }

    hitbox = (SDL_Rect){715, 67, 180, 28};
    hitbox = scale_rect(hitbox, win_rect);
    if (left_click(hitbox, input)) {
        Mix_PlayChannel(-1, SOUND(assets, SOUND_SWIPE), 0);
        scenes[CONTROLS]->is_active = true;
        scenes[GRAPHICS]->is_active = false;
    }

    hitbox = (SDL_Rect){1394, 67, 107, 28};
    hitbox = scale_rect(hitbox, win_rect);
    if (left_click(hitbox, input)) {
        Mix_PlayChannel(-1, SOUND(assets, SOUND_SWIPE), 0);
        scenes[STATS]->is_active = true;
        scenes[GRAPHICS]->is_active = false;
    }

    if (choice_pressed(scenes[GRAPHICS]->choice_b[0], input, win_rect, assets)) {
        SDL_Rect size[6] = {{0, 0, 960, 540},  {0, 0, 1024, 576}, {0, 0, 1152, 648},
                            {0, 0, 1280, 720}, {0, 0, 1366, 768}, {0, 0, 1600, 900}};
        conf->window_size = size[scenes[GRAPHICS]->choice_b[0]->current_choice];
    }

    if (toggle_pressed(scenes[GRAPHICS]->toggle_b[0], input, win_rect, assets)) {
        conf->fullscreen = scenes[GRAPHICS]->toggle_b[0]->state;
    }

    if (toggle_pressed(scenes[GRAPHICS]->toggle_b[1], input, win_rect, assets)) {
        printf("[toggle 1]: %d\n", scenes[GRAPHICS]->toggle_b[1]->state);
    }

    if (toggle_pressed(scenes[GRAPHICS]->toggle_b[2], input, win_rect, assets)) {
        printf("[toggle 2]: %d\n", scenes[GRAPHICS]->toggle_b[2]->state);
    }

    if (toggle_pressed(scenes[GRAPHICS]->toggle_b[3], input, win_rect, assets)) {
        printf("[toggle 3]: %d\n", scenes[GRAPHICS]->toggle_b[3]->state);
    }

    if (toggle_pressed(scenes[GRAPHICS]->toggle_b[4], input, win_rect, assets)) {
        printf("[toggle 4]: %d\n", scenes[GRAPHICS]->toggle_b[4]->state);
    }

    if (toggle_pressed(scenes[GRAPHICS]->toggle_b[5], input, win_rect, assets)) {
        printf("[toggle 5]: %d\n", scenes[GRAPHICS]->toggle_b[5]->state);
    }

    // Keyboard Input
    if (input->key_code == SDLK_ESCAPE) {
        scenes[GRAPHICS]->is_active = false;
        scenes[conf->last_scene]->is_active = true;
    }
}

/* **************************************************************** */
