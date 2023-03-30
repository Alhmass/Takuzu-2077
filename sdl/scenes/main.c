#include "main.h"

#include "button.h"
#include "engine.h"
#include "env.h"
#include "input.h"

/* **************************************************************** */

void main_init(Scene main, Assets assets, SDL_Renderer *ren) {
    scene_init(main, 5, 0, 0, 0, 0, 0, 0);

    SDL_Rect hitbox = {300, 550, 365, 56};
    main->default_b[0] = default_create(hitbox, "NEW GAME", DEFAULT_BLUE_DARK, assets, ren);

    hitbox = (SDL_Rect){300, 625, 365, 56};
    main->default_b[1] = default_create(hitbox, "LOAD GAME", DEFAULT_BLUE_DARK, assets, ren);

    hitbox = (SDL_Rect){300, 700, 365, 56};
    main->default_b[2] = default_create(hitbox, "SETTINGS", DEFAULT_BLUE_DARK, assets, ren);

    hitbox = (SDL_Rect){300, 775, 365, 56};
    main->default_b[3] = default_create(hitbox, "CREDITS", DEFAULT_BLUE_DARK, assets, ren);

    hitbox = (SDL_Rect){300, 850, 365, 56};
    main->default_b[4] = default_create(hitbox, "QUIT GAME", DEFAULT_BLUE_DARK, assets, ren);
}

void main_process(Conf conf, Scene * scenes, Input input, Assets assets, SDL_Renderer * ren,                     SDL_Rect win_rect) {
    (void)ren;

    if (scenes[MAIN]->is_active == false)
        return;

    if (default_pressed(scenes[MAIN]->default_b[0], input, win_rect, assets)) {
        scenes[CREATE]->is_active = true;
        scenes[MAIN]->is_active = false;
    }

    if (default_pressed(scenes[MAIN]->default_b[1], input, win_rect, assets)) {
        scenes[GAME]->is_active = true;
        scenes[MAIN]->is_active = false;
    }

    if (default_pressed(scenes[MAIN]->default_b[2], input, win_rect, assets)) {
        scenes[SOUNDS]->is_active = true;
        scenes[MAIN]->is_active = false;
    }

    if (default_pressed(scenes[MAIN]->default_b[3], input, win_rect, assets)) {
        scenes[CREDITS]->is_active = true;
        scenes[MAIN]->is_active = false;
    }

    if (default_pressed(scenes[MAIN]->default_b[4], input, win_rect, assets)) {
        printf("Quit Game\n");
    }
}

/* ************************************************************************************** */
