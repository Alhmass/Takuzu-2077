#include "sounds.h"

#include "button.h"
#include "button_create.h"
#include "env.h"
#include "input.h"

/* **************************************************************** */

static void sounds_create(Scene sounds) {
    sounds->texture = malloc(sizeof(SDL_Texture *) * NB_SOUNDS_TEXTURES);
    assert(sounds->texture);
    sounds->button = malloc(sizeof(struct Button_s) * NB_SOUNDS_BUTTONS);
    assert(sounds->button);
    // sounds->text = malloc(sizeof(SDL_Text) * NB_SOUNDS_TEXTS);
    // assert(sounds->text);
    // sounds->font = malloc(sizeof(SDL_Font) * NB_SOUNDS_FONTS);
    // assert(sounds->font);
    // sounds->mixer = malloc(sizeof(SDL_Mixer) * NB_SOUNDS_MIXERS);
    // assert(sounds->mixer);

    sounds->nb_textures = NB_SOUNDS_TEXTURES;
    sounds->nb_buttons = NB_SOUNDS_BUTTONS;
    sounds->nb_texts = NB_SOUNDS_TEXTS;
    sounds->nb_fonts = NB_SOUNDS_FONTS;
    sounds->nb_mixers = NB_SOUNDS_MIXERS;

    sounds->is_active = false;
}

void sounds_init(Scene sounds, SDL_Renderer *ren) { sounds_create(sounds); }

void sounds_process(Scene *scenes, Input input, SDL_Renderer *ren) {}

/* **************************************************************** */
