#include "graphics.h"

#include "button.h"
#include "button_create.h"
#include "env.h"
#include "input.h"

/* **************************************************************** */

static void graphics_create(Scene graphics) {
    graphics->texture = malloc(sizeof(SDL_Texture *) * NB_GRAPHICS_TEXTURES);
    assert(graphics->texture);
    graphics->button = malloc(sizeof(struct Button_s) * NB_GRAPHICS_BUTTONS);
    assert(graphics->button);
    // main->text = malloc(sizeof(SDL_Text) * NB_GRAPHICS_TEXTS);
    // assert(main->text);
    // main->font = malloc(sizeof(SDL_Font) * NB_GRAPHICS_FONTS);
    // assert(main->font);
    // main->mixer = malloc(sizeof(SDL_Mixer) * NB_GRAPHICS_MIXERS);
    // assert(main->mixer);

    graphics->nb_textures = NB_GRAPHICS_TEXTURES;
    graphics->nb_buttons = NB_GRAPHICS_BUTTONS;
    graphics->nb_texts = NB_GRAPHICS_TEXTS;
    graphics->nb_fonts = NB_GRAPHICS_FONTS;
    graphics->nb_mixers = NB_GRAPHICS_MIXERS;

    graphics->is_active = false;
}

void graphics_init(Scene graphics, SDL_Renderer *ren) { graphics_create(graphics); }

void graphics_process(Scene *scenes, Input input, SDL_Renderer *ren) {}

/* **************************************************************** */
