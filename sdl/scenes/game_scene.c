#include "game_scene.h"

#include "button.h"
#include "engine.h"
#include "env.h"
#include "input.h"

/* **************************************************************** */

void game_init(Scene game, Assets assets, SDL_Renderer *ren) {
    scene_init(game, 1, 0, 0, 0, 0, 0, 0);

    SDL_Rect hitbox = {1000, 500, 330, 50};
    game->default_b[0] = default_create(hitbox, "MAIN MENU", DEFAULT_BLUE_T, assets, ren);
}

void game_process(Scene *scenes, Input input, Assets assets, SDL_Renderer *ren, SDL_Rect win_rect) {
    if (scenes[GAME]->is_active == false)
        return;

    if (is_clicked(scenes[GAME]->default_b[0]->scaled, input))
        main_menu(scenes);
}

/* **************************************************************** */

bool main_menu(Scene *scenes) {
    scenes[MAIN]->is_active = true;
    scenes[GAME]->is_active = false;

    return true;
}