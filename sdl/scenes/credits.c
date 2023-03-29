#include "credits.h"

#include "button.h"
#include "env.h"
#include "input.h"

/* **************************************************************** */

void credits_init(Scene credits, Assets assets, SDL_Renderer *ren) {
    scene_init(credits, 0, 0, 0, 0, 0, 0, 0);

    (void)assets;
    (void)ren;
}

void credits_process(Scene *scenes, Input input, Assets assets, SDL_Renderer *ren, SDL_Rect win_rect) {
    if (scenes[CREDITS]->is_active == false)
        return;

    (void)assets;
    (void)ren;
    (void)win_rect;
    (void)input;
}

/* **************************************************************** */
