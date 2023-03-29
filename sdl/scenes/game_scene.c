#include "game_scene.h"

#include "button.h"
#include "engine.h"
#include "env.h"
#include "input.h"

/* **************************************************************** */

void game_init(Scene game, Assets assets, SDL_Renderer *ren) {
    scene_init(game, 1, 0, 0, 0, 0, 0, 0);

    SDL_Rect hitbox = {500, 500, 330, 50};
    game->default_b[0] = default_create(hitbox, "MAIN MENU", DEFAULT_BLUE_DARK, assets, ren);
}

void game_process(Scene *scenes, Input input, Assets assets, SDL_Renderer *ren, SDL_Rect win_rect) {
    if (scenes[GAME]->is_active == false)
        return;

    (void)assets;
    (void)ren;
    (void)win_rect;

    if (is_clicked(scenes[GAME]->default_b[0]->scaled, input)) {
        scenes[GAME]->is_active = false;
        scenes[MAIN]->is_active = true;
    }
}

/* **************************************************************** */
