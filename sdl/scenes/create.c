#include "create.h"

#include "button.h"
#include "env.h"
#include "input.h"

/* **************************************************************** */

void create_init(Conf conf, Scene create, Assets assets, SDL_Renderer *ren) {
    scene_init(create, 0, 0, 0, 0, 0, 0, 0);

    (void)conf;
    (void)assets;
    (void)ren;
}

void create_process(Conf conf, Scene *scenes, Input input, Assets assets, SDL_Renderer *ren, SDL_Rect win_rect) {
    if (scenes[CREATE]->is_active == false)
        return;

    (void)conf;
    (void)assets;
    (void)ren;
    (void)win_rect;
    (void)input;
}

/* **************************************************************** */
