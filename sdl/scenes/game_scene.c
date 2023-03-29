#include "game_scene.h"

#include "button.h"
#include "engine.h"
#include "env.h"
#include "input.h"

/* **************************************************************** */

void game_init(Scene game, Assets assets, SDL_Renderer *ren) {
    scene_init(game, 1, 4, 0, 0, 0, 0, 0);

    SDL_Rect hitbox = {500, 500, 330, 50};
    game->default_b[0] = default_create(hitbox, "MAIN MENU", DEFAULT_BLUE_DARK, assets, ren);

    hitbox = (SDL_Rect){1619, 90, 239, 43};
    game->switch_b[0] = switch_create(hitbox, SWITCH_OFF);

    hitbox = (SDL_Rect){1619, 158, 239, 43};
    game->switch_b[1] = switch_create(hitbox, SWITCH_OFF);

    hitbox = (SDL_Rect){1619, 226, 239, 43};
    game->switch_b[2] = switch_create(hitbox, SWITCH_OFF);

    hitbox = (SDL_Rect){1619, 295, 239, 43};
    game->switch_b[3] = switch_create(hitbox, SWITCH_OFF);
}

void game_process(Scene *scenes, Input input, Assets assets, SDL_Renderer *ren, SDL_Rect win_rect) {
    if (scenes[GAME]->is_active == false)
        return;

    (void)assets;
    (void)ren;
    (void)win_rect;

    if (left_click(scenes[GAME]->default_b[0]->scaled, input)) {
        scenes[GAME]->is_active = false;
        scenes[MAIN]->is_active = true;
    }

    if (switch_pressed(scenes[GAME]->switch_b[0], input, win_rect, assets)) {
        printf("[switch 0] %d\n", scenes[GAME]->switch_b[0]->state);
    }

    if (switch_pressed(scenes[GAME]->switch_b[1], input, win_rect, assets)) {
        printf("[switch 1] %d\n", scenes[GAME]->switch_b[1]->state);
    }

    if (switch_pressed(scenes[GAME]->switch_b[2], input, win_rect, assets)) {
        printf("[switch 2] %d\n", scenes[GAME]->switch_b[2]->state);
    }

    if (switch_pressed(scenes[GAME]->switch_b[3], input, win_rect, assets)) {
        printf("[switch 3] %d\n", scenes[GAME]->switch_b[3]->state);
    }
}

/* **************************************************************** */
