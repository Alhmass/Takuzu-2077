#ifndef SCENE_H
#define SCENE_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <assert.h>
#include <stdbool.h>

#include "assets.h"
#include "button.h"
#include "cell.h"
#include "choice.h"
#include "default.h"
#include "input.h"
#include "slider.h"
#include "switch.h"
#include "text.h"
#include "toggle.h"

/* **************************************************************** */

enum scenes { MAIN, GAME, CREATE, EDITOR, SAVED, CUSTOM, SOUNDS, CONTROLS, GRAPHICS, STATS, CREDITS, NB_SCENES };

struct Scene_s {
    /****** Objects ******/
    Default *default_b;
    Switch *switch_b;
    Toggle *toggle_b;
    Choice *choice_b;
    Slider *slider_b;
    Cell *cell_b;

    int nb_default;
    int nb_switch;
    int nb_toggle;
    int nb_choice;
    int nb_slider;
    int nb_cell;

    Text *text;
    int nb_texts;

    /****** Properties ******/
    bool is_active;
};

typedef struct Scene_s *Scene;

/* **************************************************************** */

void scene_init(Scene scene, int nb_default, int nb_switch, int nb_toggle, int nb_choice, int nb_slider, int nb_cell,
                int nb_texts);
void scene_render(Scene scene, int type, Assets assets, SDL_Renderer *ren, SDL_Rect win_rect);
void scene_delete(Scene scene);

#endif /* SCENE_H */