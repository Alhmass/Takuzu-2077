#ifndef SCENE_H
#define SCENE_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <assert.h>
#include <stdbool.h>

#include "button.h"
// #include "text.h"

/* **************************************************************** */

enum scenes {
    MAIN,
    GAME,
    NEW_CREATE,
    NEW_EDITOR,
    LOAD_SAVED,
    LOAD_CUSTOM,
    SETTINGS_SOUNDS,
    SETTINGS_CONTROLS,
    SETTINGS_GRAPHICS,
    SETTINGS_STATS,
    CREDITS,
    NB_SCENES
};

struct Scene_s {
    /****** Assets ******/
    SDL_Texture **texture;
    // SDL_Font **font;
    // SDL_Mixer *mixer;
    Button *button;
    // SDL_Text *text;

    int nb_textures;
    int nb_fonts;
    int nb_mixers;
    int nb_buttons;
    int nb_texts;

    /****** Properties ******/
    bool is_active;
};

typedef struct Scene_s *Scene;

/* **************************************************************** */

#define TEXTURE(scene, i) (scene->texture[i])
#define FONT(scene, i) (scene->font[i])
#define MIXER(scene, i) (scene->mixer[i])
#define BUTTON(scene, i) (scene->button[i])
// #define TEXT(scene, i) (scene->text[i])

/* **************************************************************** */

void scene_render(Scene scene, SDL_Renderer *ren, SDL_Rect win_rect);
void scene_delete(Scene scene, SDL_Renderer *ren);

#endif /* SCENE_H */