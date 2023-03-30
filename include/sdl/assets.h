#ifndef ASSETS_H
#define ASSETS_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <stdbool.h>

/****************************** Texture Accessors ******************************/

#define BT(assets, button_type, texture) ((assets)->button_texture[button_type][texture])  // Button Texture Accessor
#define ST(assets, texture) ((assets)->sprite_texture[texture])                            // Scene Texture Accessor
#define F(assets, font_type) ((assets)->font[font_type])                                   // Font Accessor
#define S(assets, sound_type) ((assets)->sound[sound_type])                                // Sound Accessor
#define M(assets, music_type) ((assets)->music[music_type])                                // Music Accessor

/******************************** Sprite Textures ********************************/

enum sprite_assets { MAIN_BG, GAME_BG, SETTINGS_BG, SOUNDS_BG, GRAPHICS_BG, CONTROLS_BG, STATS_BG, SPRITE_COUNT };

/******************************** Button Textures ********************************/

enum button_type { DEFAULT, SWITCH, TOGGLE, CHOICE, SLIDER, CELL, BUTTON_COUNT };

enum texture_assets {
    DEFAULT_BLUE,
    DEFAULT_BLUE_T,
    DEFAULT_BLUE_HOVER,
    DEFAULT_BLUE_DARK,
    DEFAULT_RED,
    DEFAULT_RED_T,
    DEFAULT_RED_HOVER,
    DEFAULT_T,
    DEFAULT_COUNT
};

enum switch_assets { SWITCH_ON, SWITCH_OFF, SWITCH_COUNT };

enum toggle_assets { TOGGLE_ON, TOGGLE_OFF, TOGGLE_COUNT };

enum choice_assets { CHOICE_BACKGROUND, CHOICE_COUNT };

enum slider_assets { SLIDER_BACKGROUND, SLIDER_CURSOR, SLIDER_COUNT };

enum cell_assets { CELL_EMPTY, CELL_BLUE, CELL_IMM_BLUE, CELL_RED, CELL_IMM_RED, CELL_ERROR, CELL_HOVER, CELL_COUNT };

/* **************************************************************** */

enum font_assets { CYBERPUNK, OXTA, RAJDHANI, RAJDHANI_MED, FONT_COUNT };

/* **************************************************************** */

enum sound_assets {
    SOUND_CLICK,
    SOUND_HOVER,
    SOUND_AFFIRMATIVE,
    SOUND_NEGATIVE,
    SOUND_ERROR,
    SOUND_ENTER,
    SOUND_EXIT,
    SOUND_INCREMENT,
    SOUND_DECREMENT,
    SOUND_SWIPE,
    SOUND_COUNT
};

#define SOUND(assets, type) ((assets)->sound[type])

enum music_assets { MENU_LOOP, GAME_LOOP, MUSIC_COUNT };

#define MUSIC(assets, type) ((assets)->music[type])

/* **************************************************************** */

struct Assets_s {
    SDL_Texture **sprite_texture;
    SDL_Texture ***button_texture;
    TTF_Font **font;
    Mix_Chunk **sound;
    Mix_Music **music;
};

typedef struct Assets_s *Assets;

/* **************************************************************** */

Assets assets_init(SDL_Renderer *ren);
void assets_delete(Assets assets);

#endif /* ASSETS_H */