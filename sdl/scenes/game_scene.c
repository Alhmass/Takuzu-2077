#include "game_scene.h"

#include "button.h"
#include "engine.h"
#include "env.h"
#include "input.h"

/* **************************************************************** */

void game_init(Conf conf, Scene game, Assets assets, SDL_Renderer *ren) {
    scene_init(game, 12, 4, 0, 0, 0, 0, 0);
    (void)conf;

    // Defaults
    SDL_Rect hitbox = {63, 90, 365, 56};
    game->default_b[0] = default_create(hitbox, " ", DEFAULT_T, assets, ren);

    hitbox = (SDL_Rect){63, 173, 365, 56};
    game->default_b[1] = default_create(hitbox, " ", DEFAULT_T, assets, ren);

    hitbox = (SDL_Rect){63, 255, 365, 56};
    game->default_b[2] = default_create(hitbox, " ", DEFAULT_T, assets, ren);

    hitbox = (SDL_Rect){63, 406, 365, 56};
    game->default_b[3] = default_create(hitbox, " ", DEFAULT_T, assets, ren);

    hitbox = (SDL_Rect){63, 489, 365, 56};
    game->default_b[4] = default_create(hitbox, " ", DEFAULT_T, assets, ren);

    hitbox = (SDL_Rect){63, 620, 365, 56};
    game->default_b[5] = default_create(hitbox, " ", DEFAULT_T, assets, ren);

    hitbox = (SDL_Rect){63, 702, 365, 56};
    game->default_b[6] = default_create(hitbox, " ", DEFAULT_T, assets, ren);

    hitbox = (SDL_Rect){63, 851, 365, 56};
    game->default_b[7] = default_create(hitbox, " ", DEFAULT_T, assets, ren);

    hitbox = (SDL_Rect){63, 934, 365, 56};
    game->default_b[8] = default_create(hitbox, " ", DEFAULT_T, assets, ren);

    hitbox = (SDL_Rect){1493, 769, 365, 56};
    game->default_b[9] = default_create(hitbox, " ", DEFAULT_T, assets, ren);

    hitbox = (SDL_Rect){1493, 851, 365, 56};
    game->default_b[10] = default_create(hitbox, " ", DEFAULT_T, assets, ren);

    hitbox = (SDL_Rect){1493, 934, 365, 56};
    game->default_b[11] = default_create(hitbox, " ", DEFAULT_T, assets, ren);

    // Switches
    hitbox = (SDL_Rect){1619, 90, 239, 43};
    game->switch_b[0] = switch_create(hitbox, SWITCH_OFF);

    hitbox = (SDL_Rect){1619, 158, 239, 43};
    game->switch_b[1] = switch_create(hitbox, SWITCH_OFF);

    hitbox = (SDL_Rect){1619, 226, 239, 43};
    game->switch_b[2] = switch_create(hitbox, SWITCH_OFF);

    hitbox = (SDL_Rect){1619, 295, 239, 43};
    game->switch_b[3] = switch_create(hitbox, SWITCH_OFF);
}

void game_process(Conf conf, Scene *scenes, Input input, Assets assets, SDL_Renderer *ren, SDL_Rect win_rect) {
    if (scenes[GAME]->is_active == false)
        return;

    (void)conf;
    (void)ren;

    // Defaults
    for (int i = 0; i < scenes[GAME]->nb_default; i++) {
        default_pressed(scenes[GAME]->default_b[i], input, win_rect, assets);
    }

    if (default_pressed(scenes[GAME]->default_b[9], input, win_rect, assets)) {
        scenes[GAME]->is_active = false;
        scenes[SOUNDS]->is_active = true;
    }

    if (default_pressed(scenes[GAME]->default_b[10], input, win_rect, assets)) {
        scenes[GAME]->is_active = false;
        scenes[MAIN]->is_active = true;
    }

    if (default_pressed(scenes[GAME]->default_b[11], input, win_rect, assets)) {
        conf->quit = true;
    }

    // Switches
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

    // Keyboard Input
    if (input->key_code == SDLK_ESCAPE) {
        scenes[GAME]->is_active = false;
        scenes[MAIN]->is_active = true;
    }
}

/* **************************************************************** */
