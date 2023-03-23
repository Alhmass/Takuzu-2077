#include "create.h"

#include "button.h"
#include "button_create.h"
#include "env.h"
#include "input.h"

/* **************************************************************** */

static void create_create(Scene create) {
    create->texture = malloc(sizeof(SDL_Texture *) * NB_CREATE_TEXTURES);
    assert(create->texture);
    create->button = malloc(sizeof(struct Button_s) * NB_CREATE_BUTTONS);
    assert(create->button);
    // main->text = malloc(sizeof(SDL_Text) * NB_CREATE_TEXTS);
    // assert(main->text);
    // main->font = malloc(sizeof(SDL_Font) * NB_CREATE_FONTS);
    // assert(main->font);
    // main->mixer = malloc(sizeof(SDL_Mixer) * NB_CREATE_MIXERS);
    // assert(main->mixer);

    create->nb_textures = NB_CREATE_TEXTURES;
    create->nb_buttons = NB_CREATE_BUTTONS;
    create->nb_texts = NB_CREATE_TEXTS;
    create->nb_fonts = NB_CREATE_FONTS;
    create->nb_mixers = NB_CREATE_MIXERS;

    create->is_active = false;
}

void create_init(Scene create, SDL_Renderer *ren) { create_create(create); }

void create_process(Scene *scenes, Input input, SDL_Renderer *ren) {}

/* **************************************************************** */
