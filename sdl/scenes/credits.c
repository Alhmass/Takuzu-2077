#include "credits.h"

#include "button.h"
#include "env.h"
#include "input.h"

/* **************************************************************** */

void credits_init(Conf conf, Scene credits, Assets assets, SDL_Renderer *ren) {
    scene_init(credits, 0, 0, 0, 0, 0, 0, 0);

    (void)conf;
    (void)assets;
    (void)ren;
}

void credits_process(Conf conf, Scene *scenes, Input input, Assets assets, SDL_Renderer *ren, SDL_Rect win_rect) {
    if (scenes[CREDITS]->is_active == false)
        return;

    (void)conf;
    (void)assets;
    (void)ren;
    (void)win_rect;

    // Keyboard Input
    if (input->key_code == SDLK_ESCAPE) {
        scenes[CREDITS]->is_active = false;
        scenes[MAIN]->is_active = true;
    }
}

/* **************************************************************** */
