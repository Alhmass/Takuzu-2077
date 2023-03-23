#ifndef BUTTON_H
#define BUTTON_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <stdbool.h>

#include "input.h"

/* **************************************************************** */

#define FONT_RAJDHANI "assets/font/Rajdhani/Rajdhani-Regular.ttf"

#define SOUND_HOVER "assets/sound/button_click.mp3"
#define SOUND_CLICK "assets/sound/button_click.mp3"

/* **************************************************************** */

enum Button_type { DEFAULT, TRANSPARENT, SWITCH, SLIDER, CHOICE, CELL };

struct Button_s {
    /****** Type ******/
    enum Button_type type;

    /****** Assets ******/
    SDL_Texture **texture;
    int nb_textures;
    bool *active_texture;

    // SDL_Mixer **mixer;
    int nb_mixers;

    // Text **label;
    int nb_labels;
    int active_label;

    /****** Properties ******/
    SDL_Rect hitbox;
    SDL_Rect scaled_hitbox;
    bool hovered;
    bool error;

    int value;
    int min;
    int max;
};

typedef struct Button_s *Button;

/* **************************************************************** */

#define LABEL(button) (button->label[button->label_index])

/* **************************************************************** */

void button_render(Button button, SDL_Renderer *ren, SDL_Rect win_rect);
void button_delete(Button button);

bool button_down(Button button, Input input);
bool button_hovered(Button button, Input input);
bool button_up(Button button, Input input);

#endif /* BUTTON_H */