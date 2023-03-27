#include "main.h"

#include "button.h"
#include "engine.h"
#include "env.h"
#include "input.h"

/* **************************************************************** */

void main_init(Scene main, Assets assets, SDL_Renderer *ren) {
    scene_init(main, 1, 0, 0, 0, 0, 0, 0);

    SDL_Rect hitbox = {300, 500, 330, 50};
    main->default_b[0] = default_create(hitbox, "LOAD GAME", DEFAULT_BLUE_T, assets, ren);

    // hitbox = (SDL_Rect){900, 900, 100, 100};
    // main->default_b[1] = default_create(hitbox, "SQUARE", DEFAULT_BLUE, assets, ren);
}

void main_process(Scene *scenes, Input input, Assets assets, SDL_Renderer *ren, SDL_Rect win_rect) {
    if (scenes[MAIN]->is_active == false)
        return;

    if (is_clicked(scenes[MAIN]->default_b[0]->scaled, input))
        load_game(scenes);
    // if (is_clicked(scenes[MAIN]->default_b[1]->scaled, input))
    //     square_btn();
}

/* ************************************************************************************** */

bool load_game(Scene *scenes) {
    scenes[GAME]->is_active = true;
    scenes[MAIN]->is_active = false;

    return true;
}

// void square_btn() { printf("square\n"); }