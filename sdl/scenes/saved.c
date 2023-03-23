#include "saved.h"

#include "button.h"
#include "button_create.h"
#include "env.h"
#include "input.h"

/* **************************************************************** */

static void saved_create(Scene saved) {
    saved->texture = malloc(sizeof(SDL_Texture *) * NB_SAVED_TEXTURES);
    assert(saved->texture);
    saved->button = malloc(sizeof(struct Button_s) * NB_SAVED_BUTTONS);
    assert(saved->button);
    // main->text = malloc(sizeof(SDL_Text) * NB_SAVED_TEXTS);
    // assert(main->text);
    // main->font = malloc(sizeof(SDL_Font) * NB_SAVED_FONTS);
    // assert(main->font);
    // main->mixer = malloc(sizeof(SDL_Mixer) * NB_SAVED_MIXERS);
    // assert(main->mixer);

    saved->nb_textures = NB_SAVED_TEXTURES;
    saved->nb_buttons = NB_SAVED_BUTTONS;
    saved->nb_texts = NB_SAVED_TEXTS;
    saved->nb_fonts = NB_SAVED_FONTS;
    saved->nb_mixers = NB_SAVED_MIXERS;

    saved->is_active = false;
}

void saved_init(Scene saved, SDL_Renderer *ren) { saved_create(saved); }

void saved_process(Scene *scenes, Input input, SDL_Renderer *ren) {}

/* **************************************************************** */
