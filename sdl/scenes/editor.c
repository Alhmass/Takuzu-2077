#include "editor.h"

#include "button.h"
#include "button_create.h"
#include "env.h"
#include "input.h"

/* **************************************************************** */

static void editor_create(Scene editor) {
    editor->texture = malloc(sizeof(SDL_Texture *) * NB_EDITOR_TEXTURES);
    assert(editor->texture);
    editor->button = malloc(sizeof(struct Button_s) * NB_EDITOR_BUTTONS);
    assert(editor->button);
    // main->text = malloc(sizeof(SDL_Text) * NB_EDITOR_TEXTS);
    // assert(main->text);
    // main->font = malloc(sizeof(SDL_Font) * NB_EDITOR_FONTS);
    // assert(main->font);
    // main->mixer = malloc(sizeof(SDL_Mixer) * NB_EDITOR_MIXERS);
    // assert(main->mixer);

    editor->nb_textures = NB_EDITOR_TEXTURES;
    editor->nb_buttons = NB_EDITOR_BUTTONS;
    editor->nb_texts = NB_EDITOR_TEXTS;
    editor->nb_fonts = NB_EDITOR_FONTS;
    editor->nb_mixers = NB_EDITOR_MIXERS;

    editor->is_active = false;
}

void editor_init(Scene editor, SDL_Renderer *ren) { editor_create(editor); }

void editor_process(Scene *scenes, Input input, SDL_Renderer *ren) {}

/* **************************************************************** */
