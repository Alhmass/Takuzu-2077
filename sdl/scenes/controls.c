#include "controls.h"

#include "button.h"
#include "button_create.h"
#include "env.h"
#include "input.h"

/* **************************************************************** */

static void controls_create(Scene controls) {
    controls->texture = malloc(sizeof(SDL_Texture *) * NB_CONTROLS_TEXTURES);
    assert(controls->texture);
    controls->button = malloc(sizeof(struct Button_s) * NB_CONTROLS_BUTTONS);
    assert(controls->button);
    // main->text = malloc(sizeof(SDL_Text) * NB_CONTROLS_TEXTS);
    // assert(main->text);
    // main->font = malloc(sizeof(SDL_Font) * NB_CONTROLS_FONTS);
    // assert(main->font);
    // main->mixer = malloc(sizeof(SDL_Mixer) * NB_CONTROLS_MIXERS);
    // assert(main->mixer);

    controls->nb_textures = NB_CONTROLS_TEXTURES;
    controls->nb_buttons = NB_CONTROLS_BUTTONS;
    controls->nb_texts = NB_CONTROLS_TEXTS;
    controls->nb_fonts = NB_CONTROLS_FONTS;
    controls->nb_mixers = NB_CONTROLS_MIXERS;

    controls->is_active = false;
}

void controls_init(Scene controls, SDL_Renderer *ren) { controls_create(controls); }

void controls_process(Scene *scenes, Input input, SDL_Renderer *ren) {}

/* **************************************************************** */
