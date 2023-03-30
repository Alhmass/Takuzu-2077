#include "saved.h"

#include "button.h"
#include "env.h"
#include "input.h"

/* **************************************************************** */

void saved_init(Scene saved, Assets assets, SDL_Renderer *ren) {
    scene_init(saved, 0, 0, 0, 0, 0, 0, 0);

    (void)assets;
    (void)ren;
}

void saved_process(Conf conf, Scene * scenes, Input input, Assets assets, SDL_Renderer * ren,                     SDL_Rect win_rect) {
    if (scenes[SAVED]->is_active == false)
        return;

    (void)assets;
    (void)ren;
    (void)win_rect;
    (void)input;
}

/* **************************************************************** */
