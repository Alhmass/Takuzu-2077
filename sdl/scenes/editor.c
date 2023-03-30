#include "editor.h"

#include "button.h"
#include "env.h"
#include "input.h"

/* **************************************************************** */

void editor_init(Scene editor, Assets assets, SDL_Renderer *ren) {
    scene_init(editor, 0, 0, 0, 0, 0, 0, 0);

    (void)assets;
    (void)ren;
}

void editor_process(Conf conf, Scene * scenes, Input input, Assets assets, SDL_Renderer * ren,                     SDL_Rect win_rect) {
    if (scenes[EDITOR]->is_active == false)
        return;

    (void)assets;
    (void)ren;
    (void)win_rect;
    (void)input;
}

/* **************************************************************** */
