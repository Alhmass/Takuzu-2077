#include "graphics.h"

#include "button.h"
#include "env.h"
#include "input.h"

/* **************************************************************** */

void graphics_init(Scene graphics, Assets assets, SDL_Renderer *ren) {
    scene_init(graphics, 0, 0, 6, 1, 0, 0, 0);

    SDL_Rect hitbox = {842, 283, 660, 59};
    char *choices[7] = {"960 x 540",  "1024 x 576", "1152 x 648", "1280 x 720",
                        "1366 x 768", "1600 x 900", "1920 x 1080"};
    graphics->choice_b[0] = choice_create(hitbox, choices, 7, 6, assets, ren);

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

void graphics_process(Scene *scenes, Input input, Assets assets, SDL_Renderer *ren, SDL_Rect win_rect) {
    if (scenes[GRAPHICS]->is_active == false)
        return;

    (void)assets;
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
        printf("[choice 0]: %d\n", scenes[GRAPHICS]->choice_b[0]->current_choice);
    }

    if (toggle_pressed(scenes[GRAPHICS]->toggle_b[0], input, win_rect, assets)) {
        printf("[toggle 0]: %d\n", scenes[GRAPHICS]->toggle_b[0]->state);
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
}

/* **************************************************************** */
