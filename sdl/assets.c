#include "assets.h"

#include <assert.h>

#include "engine.h"

static void default_init(Assets a, SDL_Renderer *ren) {
    a->button_texture[DEFAULT] = malloc(sizeof(SDL_Texture *) * DEFAULT_COUNT);
    assert(a->button_texture[DEFAULT]);

    BT(a, DEFAULT, DEFAULT_BLUE) = IMG_LoadTexture(ren, "assets/img/buttons/default/blue.png");
    if (!BT(a, DEFAULT, DEFAULT_BLUE))
        ERROR("Error: IMG_LoadTexture (%s)", SDL_GetError());
    BT(a, DEFAULT, DEFAULT_BLUE_T) = IMG_LoadTexture(ren, "assets/img/buttons/default/blue_transparent.png");
    if (!BT(a, DEFAULT, DEFAULT_BLUE_T))
        ERROR("Error: IMG_LoadTexture (%s)", SDL_GetError());
    BT(a, DEFAULT, DEFAULT_BLUE_HOVER) = IMG_LoadTexture(ren, "assets/img/buttons/default/blue_hover.png");
    if (!BT(a, DEFAULT, DEFAULT_BLUE_HOVER))
        ERROR("Error: IMG_LoadTexture (%s)", SDL_GetError());
    BT(a, DEFAULT, DEFAULT_RED) = IMG_LoadTexture(ren, "assets/img/buttons/default/red.png");
    if (!BT(a, DEFAULT, DEFAULT_RED))
        ERROR("Error: IMG_LoadTexture (%s)", SDL_GetError());
    BT(a, DEFAULT, DEFAULT_RED_T) = IMG_LoadTexture(ren, "assets/img/buttons/default/red_transparent.png");
    if (!BT(a, DEFAULT, DEFAULT_RED_T))
        ERROR("Error: IMG_LoadTexture (%s)", SDL_GetError());
    BT(a, DEFAULT, DEFAULT_RED_HOVER) = IMG_LoadTexture(ren, "assets/img/buttons/default/red_hover.png");
    if (!BT(a, DEFAULT, DEFAULT_RED_HOVER))
        ERROR("Error: IMG_LoadTexture (%s)", SDL_GetError());
}

static void switch_init(Assets a, SDL_Renderer *ren) {
    a->button_texture[SWITCH] = malloc(sizeof(SDL_Texture *) * SWITCH_COUNT);
    assert(a->button_texture[SWITCH]);

    BT(a, SWITCH, SWITCH_ON) = IMG_LoadTexture(ren, "assets/img/buttons/switch/on.png");
    if (!BT(a, SWITCH, SWITCH_ON))
        ERROR("Error: IMG_LoadTexture (%s)", SDL_GetError());
    BT(a, SWITCH, SWITCH_OFF) = IMG_LoadTexture(ren, "assets/img/buttons/switch/off.png");
    if (!BT(a, SWITCH, SWITCH_OFF))
        ERROR("Error: IMG_LoadTexture (%s)", SDL_GetError());
}

static void toggle_init(Assets a, SDL_Renderer *ren) {
    a->button_texture[TOGGLE] = malloc(sizeof(SDL_Texture *) * TOGGLE_COUNT);
    assert(a->button_texture[TOGGLE]);

    BT(a, TOGGLE, TOGGLE_ON) = IMG_LoadTexture(ren, "assets/img/buttons/toggle/on.png");
    if (!BT(a, TOGGLE, TOGGLE_ON))
        ERROR("Error: IMG_LoadTexture (%s)", SDL_GetError());
    BT(a, TOGGLE, TOGGLE_OFF) = IMG_LoadTexture(ren, "assets/img/buttons/toggle/off.png");
    if (!BT(a, TOGGLE, TOGGLE_OFF))
        ERROR("Error: IMG_LoadTexture (%s)", SDL_GetError());
}

static void choice_init(Assets a, SDL_Renderer *ren) {
    a->button_texture[CHOICE] = malloc(sizeof(SDL_Texture *) * CHOICE_COUNT);
    assert(a->button_texture[CHOICE]);

    BT(a, CHOICE, CHOICE_BACKGROUND) = IMG_LoadTexture(ren, "assets/img/buttons/choice/background.png");
    if (!BT(a, CHOICE, CHOICE_BACKGROUND))
        ERROR("Error: IMG_LoadTexture (%s)", SDL_GetError());
}

static void slider_init(Assets a, SDL_Renderer *ren) {
    a->button_texture[SLIDER] = malloc(sizeof(SDL_Texture *) * SLIDER_COUNT);
    assert(a->button_texture[SLIDER]);

    BT(a, SLIDER, SLIDER_BACKGROUND) = IMG_LoadTexture(ren, "assets/img/buttons/slider/background.png");
    if (!BT(a, SLIDER, SLIDER_BACKGROUND))
        ERROR("Error: IMG_LoadTexture (%s)", SDL_GetError());
    BT(a, SLIDER, SLIDER_CURSOR) = IMG_LoadTexture(ren, "assets/img/buttons/slider/cursor.png");
    if (!BT(a, SLIDER, SLIDER_CURSOR))
        ERROR("Error: IMG_LoadTexture (%s)", SDL_GetError());
}

static void cell_init(Assets a, SDL_Renderer *ren) {
    a->button_texture[CELL] = malloc(sizeof(SDL_Texture *) * CELL_COUNT);
    assert(a->button_texture[CELL]);

    BT(a, CELL, CELL_EMPTY) = IMG_LoadTexture(ren, "assets/img/buttons/cell/empty.png");
    if (!BT(a, CELL, CELL_EMPTY))
        ERROR("Error: IMG_LoadTexture (%s)", SDL_GetError());
    BT(a, CELL, CELL_BLUE) = IMG_LoadTexture(ren, "assets/img/buttons/cell/blue.png");
    if (!BT(a, CELL, CELL_BLUE))
        ERROR("Error: IMG_LoadTexture (%s)", SDL_GetError());
    BT(a, CELL, CELL_IMM_BLUE) = IMG_LoadTexture(ren, "assets/img/buttons/cell/imm_blue.png");
    if (!BT(a, CELL, CELL_IMM_BLUE))
        ERROR("Error: IMG_LoadTexture (%s)", SDL_GetError());
    BT(a, CELL, CELL_RED) = IMG_LoadTexture(ren, "assets/img/buttons/cell/red.png");
    if (!BT(a, CELL, CELL_RED))
        ERROR("Error: IMG_LoadTexture (%s)", SDL_GetError());
    BT(a, CELL, CELL_IMM_RED) = IMG_LoadTexture(ren, "assets/img/buttons/cell/imm_red.png");
    if (!BT(a, CELL, CELL_IMM_RED))
        ERROR("Error: IMG_LoadTexture (%s)", SDL_GetError());
    BT(a, CELL, CELL_ERROR) = IMG_LoadTexture(ren, "assets/img/buttons/cell/error.png");
    if (!BT(a, CELL, CELL_ERROR))
        ERROR("Error: IMG_LoadTexture (%s)", SDL_GetError());
    BT(a, CELL, CELL_HOVER) = IMG_LoadTexture(ren, "assets/img/buttons/cell/hover.png");
    if (!BT(a, CELL, CELL_HOVER))
        ERROR("Error: IMG_LoadTexture (%s)", SDL_GetError());
}

/* ************************************************************************* */

static void sprite_init(Assets a, SDL_Renderer *ren) {
    a->sprite_texture = malloc(sizeof(SDL_Texture *) * SPRITE_COUNT);
    assert(a->sprite_texture);

    ST(a, MAIN_BG) = IMG_LoadTexture(ren, "assets/img/sprites/main_bg.png");
    if (!ST(a, MAIN_BG))
        ERROR("Error: IMG_LoadTexture (%s)", SDL_GetError());
    ST(a, GAME_BG) = IMG_LoadTexture(ren, "assets/img/sprites/game_bg.png");
    if (!ST(a, GAME_BG))
        ERROR("Error: IMG_LoadTexture (%s)", SDL_GetError());
    ST(a, SETTINGS_BG) = IMG_LoadTexture(ren, "assets/img/sprites/settings_bg.png");
    if (!ST(a, SETTINGS_BG))
        ERROR("Error: IMG_LoadTexture (%s)", SDL_GetError());
}

/* ************************************************************************* */

static void fonts_init(Assets a) {
    a->font = malloc(sizeof(TTF_Font *) * FONT_COUNT);
    assert(a->font);

    F(a, FONT_CYBERPUNK) = TTF_OpenFont("assets/fonts/Cyberpunk.ttf", 100);
    if (!F(a, FONT_CYBERPUNK))
        ERROR("Error: TTF_OpenFont (%s)", TTF_GetError());
    F(a, FONT_OXTA) = TTF_OpenFont("assets/fonts/Oxta.ttf", 100);
    if (!F(a, FONT_OXTA))
        ERROR("Error: TTF_OpenFont (%s)", TTF_GetError());
    F(a, FONT_RAJDHANI) = TTF_OpenFont("assets/fonts/Rajdhani-SemiBold.ttf", 100);
    if (!F(a, FONT_RAJDHANI))
        ERROR("Error: TTF_OpenFont (%s)", TTF_GetError());
}

/* ************************************************************************* */

static void sounds_init(Assets a) {
    a->sound = malloc(sizeof(Mix_Chunk *) * SOUND_COUNT);
    assert(a->sound);

    S(a, SOUND_CLICK) = Mix_LoadWAV("assets/sounds/click.wav");
    if (!S(a, SOUND_CLICK))
        ERROR("Error: Mix_LoadWAV (%s)", Mix_GetError());
    S(a, SOUND_HOVER) = Mix_LoadWAV("assets/sounds/hover.wav");
    if (!S(a, SOUND_HOVER))
        ERROR("Error: Mix_LoadWAV (%s)", Mix_GetError());
    S(a, SOUND_AFFIRMATIVE) = Mix_LoadWAV("assets/sounds/affirmative.wav");
    if (!S(a, SOUND_AFFIRMATIVE))
        ERROR("Error: Mix_LoadWAV (%s)", Mix_GetError());
    S(a, SOUND_NEGATIVE) = Mix_LoadWAV("assets/sounds/negative.wav");
    if (!S(a, SOUND_NEGATIVE))
        ERROR("Error: Mix_LoadWAV (%s)", Mix_GetError());
    S(a, SOUND_ERROR) = Mix_LoadWAV("assets/sounds/error.wav");
    if (!S(a, SOUND_ERROR))
        ERROR("Error: Mix_LoadWAV (%s)", Mix_GetError());
    S(a, SOUND_ENTER) = Mix_LoadWAV("assets/sounds/enter.wav");
    if (!S(a, SOUND_ENTER))
        ERROR("Error: Mix_LoadWAV (%s)", Mix_GetError());
    S(a, SOUND_EXIT) = Mix_LoadWAV("assets/sounds/exit.wav");
    if (!S(a, SOUND_EXIT))
        ERROR("Error: Mix_LoadWAV (%s)", Mix_GetError());
    S(a, SOUND_INCREMENT) = Mix_LoadWAV("assets/sounds/increment.wav");
    if (!S(a, SOUND_INCREMENT))
        ERROR("Error: Mix_LoadWAV (%s)", Mix_GetError());
    S(a, SOUND_DECREMENT) = Mix_LoadWAV("assets/sounds/decrement.wav");
    if (!S(a, SOUND_DECREMENT))
        ERROR("Error: Mix_LoadWAV (%s)", Mix_GetError());
    S(a, SOUND_SWIPE) = Mix_LoadWAV("assets/sounds/swipe.wav");
    if (!S(a, SOUND_SWIPE))
        ERROR("Error: Mix_LoadWAV (%s)", Mix_GetError());
}

/* ************************************************************************* */

static void music_init(Assets a) {
    a->music = malloc(sizeof(Mix_Music *) * MUSIC_COUNT);
    assert(a->music);

    M(a, MENU_LOOP) = Mix_LoadMUS("assets/music/menu.mp3");
    if (!M(a, MENU_LOOP))
        ERROR("Error: Mix_LoadMUS (%s)", Mix_GetError());
    M(a, GAME_LOOP) = Mix_LoadMUS("assets/music/game.mp3");
    if (!M(a, GAME_LOOP))
        ERROR("Error: Mix_LoadMUS (%s)", Mix_GetError());
}

/* ************************************************************************* */

Assets assets_init(SDL_Renderer *ren) {
    Assets assets = malloc(sizeof(struct Assets_s));
    assert(assets);

    // Allocate memory for 6 button types
    assets->button_texture = malloc(sizeof(SDL_Texture **) * BUTTON_COUNT);
    assert(assets->button_texture);

    // Load the button textures
    default_init(assets, ren);
    switch_init(assets, ren);
    toggle_init(assets, ren);
    choice_init(assets, ren);
    slider_init(assets, ren);
    cell_init(assets, ren);

    // Load the other sprite textures
    sprite_init(assets, ren);

    // Load the font
    fonts_init(assets);

    // Load the sounds
    sounds_init(assets);

    // Load the music
    music_init(assets);

    return assets;
}

void assets_destroy(Assets a) {
    // Destroy the button textures
    int *button_counts = (int[]){DEFAULT_COUNT, SWITCH_COUNT, TOGGLE_COUNT, CHOICE_COUNT, SLIDER_COUNT, CELL_COUNT};
    for (int i = 0; i < BUTTON_COUNT; i++) {
        for (int j = 0; j < button_counts[i]; j++) {
            SDL_DestroyTexture(BT(a, i, j));
        }
        free(a->button_texture[i]);
    }
    free(a->button_texture);

    // Destroy the sprite textures
    for (int i = 0; i < SPRITE_COUNT; i++) {
        SDL_DestroyTexture(ST(a, i));
    }
    free(a->sprite_texture);

    // Destroy the fonts
    for (int i = 0; i < FONT_COUNT; i++) {
        TTF_CloseFont(F(a, i));
    }
    free(a->font);

    // Destroy the sounds
    for (int i = 0; i < SOUND_COUNT; i++) {
        Mix_FreeChunk(S(a, i));
    }
    free(a->sound);

    // Destroy the music
    for (int i = 0; i < MUSIC_COUNT; i++) {
        Mix_FreeMusic(M(a, i));
    }
    free(a->music);

    free(a);
}

/* ************************************************************************* */
