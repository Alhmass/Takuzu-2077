#include "custom.h"

#include "button.h"
#include "env.h"
#include "input.h"

/* **************************************************************** */

void custom_init(Scene custom, Assets assets, SDL_Renderer *ren) {
    scene_init(custom, 0, 0, 0, 0, 0, 0, 0);
    (void)assets;
    (void)ren;
}

void custom_process(Conf conf, Scene * scenes, Input input, Assets assets, SDL_Renderer * ren,                     SDL_Rect win_rect) {
    if (scenes[CUSTOM]->is_active == false)
        return;

    (void)assets;
    (void)ren;
    (void)win_rect;
    (void)input;
}

/* **************************************************************** */
