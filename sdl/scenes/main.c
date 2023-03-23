#include "main.h"

#include "button.h"
#include "button_create.h"
#include "engine.h"
#include "env.h"
#include "input.h"

/* **************************************************************** */

static void main_create(Scene main) {
    main->texture = malloc(sizeof(SDL_Texture *) * NB_MAIN_TEXTURES);
    assert(main->texture);
    main->button = malloc(sizeof(struct Button_s) * NB_MAIN_BUTTONS);
    assert(main->button);
    // main->text = malloc(sizeof(SDL_Text) * NB_MAIN_TEXTS);
    // assert(main->text);
    // main->font = malloc(sizeof(SDL_Font) * NB_MAIN_FONTS);
    // assert(main->font);
    // main->mixer = malloc(sizeof(SDL_Mixer) * NB_MAIN_MIXERS);
    // assert(main->mixer);

    main->nb_textures = NB_MAIN_TEXTURES;
    main->nb_buttons = NB_MAIN_BUTTONS;
    main->nb_texts = NB_MAIN_TEXTS;
    main->nb_fonts = NB_MAIN_FONTS;
    main->nb_mixers = NB_MAIN_MIXERS;

    main->is_active = true;
}

void main_init(Scene main, SDL_Renderer *ren) {
    main_create(main);
    TEXTURE(main, MAIN_BACKGROUND) = IMG_LoadTexture(ren, "assets/img/main/background.png");
    if (!TEXTURE(main, MAIN_BACKGROUND))
        ERROR("Error: IMG_LoadTexture (%s)", SDL_GetError());

    SDL_Rect hitbox = {300, 500, 330, 50};
    BUTTON(main, LOAD_GAME) = default_create(ren, hitbox, false);
}

void main_process(Scene *scenes, Input input, SDL_Renderer *ren) {
    if (scenes[MAIN]->is_active == false)
        return;

    if (button_down(BUTTON(scenes[MAIN], LOAD_GAME), input))
        load_game(scenes);
}

/* ************************************************************************************** */

bool load_game(Scene *scenes) {
    scenes[GAME]->is_active = true;
    scenes[MAIN]->is_active = false;

    return true;
}