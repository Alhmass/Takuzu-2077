#include "custom.h"

#include "button.h"
#include "button_create.h"
#include "env.h"
#include "input.h"

/* **************************************************************** */

static void custom_create(Scene custom) {
    custom->texture = malloc(sizeof(SDL_Texture *) * NB_CUSTOM_TEXTURES);
    assert(custom->texture);
    custom->button = malloc(sizeof(struct Button_s) * NB_CUSTOM_BUTTONS);
    assert(custom->button);
    // main->text = malloc(sizeof(SDL_Text) * NB_CUSTOM_TEXTS);
    // assert(main->text);
    // main->font = malloc(sizeof(SDL_Font) * NB_CUSTOM_FONTS);
    // assert(main->font);
    // main->mixer = malloc(sizeof(SDL_Mixer) * NB_CUSTOM_MIXERS);
    // assert(main->mixer);

    custom->nb_textures = NB_CUSTOM_TEXTURES;
    custom->nb_buttons = NB_CUSTOM_BUTTONS;
    custom->nb_texts = NB_CUSTOM_TEXTS;
    custom->nb_fonts = NB_CUSTOM_FONTS;
    custom->nb_mixers = NB_CUSTOM_MIXERS;

    custom->is_active = false;
}

void custom_init(Scene custom, SDL_Renderer *ren) { custom_create(custom); }

void custom_process(Scene *scenes, Input input, SDL_Renderer *ren) {}

/* **************************************************************** */
