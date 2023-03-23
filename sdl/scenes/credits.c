#include "credits.h"

#include "button.h"
#include "button_create.h"
#include "env.h"
#include "input.h"

/* **************************************************************** */

static void credits_create(Scene credits) {
    credits->texture = malloc(sizeof(SDL_Texture *) * NB_CREDITS_TEXTURES);
    assert(credits->texture);
    credits->button = malloc(sizeof(struct Button_s) * NB_CREDITS_BUTTONS);
    assert(credits->button);
    // main->text = malloc(sizeof(SDL_Text) * NB_CREDITS_TEXTS);
    // assert(main->text);
    // main->font = malloc(sizeof(SDL_Font) * NB_CREDITS_FONTS);
    // assert(main->font);
    // main->mixer = malloc(sizeof(SDL_Mixer) * NB_CREDITS_MIXERS);
    // assert(main->mixer);

    credits->nb_textures = NB_CREDITS_TEXTURES;
    credits->nb_buttons = NB_CREDITS_BUTTONS;
    credits->nb_texts = NB_CREDITS_TEXTS;
    credits->nb_fonts = NB_CREDITS_FONTS;
    credits->nb_mixers = NB_CREDITS_MIXERS;

    credits->is_active = false;
}

void credits_init(Scene credits, SDL_Renderer *ren) { credits_create(credits); }

void credits_process(Scene *scenes, Input input, SDL_Renderer *ren) {}

/* **************************************************************** */
