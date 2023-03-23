#include "game_scene.h"

#include "button.h"
#include "button_create.h"
#include "engine.h"
#include "env.h"
#include "input.h"

/* **************************************************************** */

static void game_create(Scene game) {
    game->texture = malloc(sizeof(SDL_Texture *) * NB_GAME_TEXTURES);
    assert(game->texture);
    game->button = malloc(sizeof(struct Button_s) * NB_GAME_BUTTONS);
    assert(game->button);
    // main->text = malloc(sizeof(SDL_Text) * NB_GAME_TEXTS);
    // assert(main->text);
    // main->font = malloc(sizeof(SDL_Font) * NB_GAME_FONTS);
    // assert(main->font);
    // main->mixer = malloc(sizeof(SDL_Mixer) * NB_GAME_MIXERS);
    // assert(main->mixer);

    game->nb_textures = NB_GAME_TEXTURES;
    game->nb_buttons = NB_GAME_BUTTONS;
    game->nb_texts = NB_GAME_TEXTS;
    game->nb_fonts = NB_GAME_FONTS;
    game->nb_mixers = NB_GAME_MIXERS;

    game->is_active = false;
}

void game_init(Scene game, SDL_Renderer *ren) {
    game_create(game);
    TEXTURE(game, GAME_BACKGROUND) = IMG_LoadTexture(ren, "assets/img/settings/background.png");
    if (!TEXTURE(game, GAME_BACKGROUND))
        ERROR("Error: IMG_LoadTexture (%s)", SDL_GetError());

    SDL_Rect hitbox = {1000, 500, 330, 50};
    BUTTON(game, MAIN_MENU) = default_create(ren, hitbox, false);
}

void game_process(Scene *scenes, Input input, SDL_Renderer *ren) {
    if (scenes[GAME]->is_active == false)
        return;

    if (button_down(BUTTON(scenes[GAME], MAIN_MENU), input))
        main_menu(scenes);
}

/* **************************************************************** */

bool main_menu(Scene *scenes) {
    scenes[MAIN]->is_active = true;
    scenes[GAME]->is_active = false;

    return true;
}