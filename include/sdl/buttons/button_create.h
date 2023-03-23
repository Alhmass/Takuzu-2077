#ifndef BUTTON_CREATE_H
#define BUTTON_CREATE_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <assert.h>
#include <stdbool.h>

#include "button.h"

/* **************************************************************** */

#define DEFAULT_TEXTURE "assets/img/buttons/default.png"
#define DEFAULT_HOVER "assets/img/buttons/default_hover.png"

#define TRANSPARENT_TEXTURE "assets/imgs/button/transparent.png"
#define TRANSPARENT_HOVER "assets/imgs/button/transparent_hover.png"

// Button default_create(SDL_Renderer *ren, SDL_Rect hitbox, Text label, bool transparent);
Button default_create(SDL_Renderer *ren, SDL_Rect hitbox, bool transparent);

/* **************************************************************** */

#define SWITCH_ON "assets/img/buttons/switch_on.png"
#define SWITCH_OFF "assets/img/buttons/switch_off.png"

Button switch_create(SDL_Renderer *ren, SDL_Rect hitbox, bool default_state);

/* **************************************************************** */

#define LEFT_TEXTURE "assets/img/buttons/left.png"
#define RIGHT_TEXTURE "assets/img/buttons/right.png"
#define BACKGROUND_TEXTURE "assets/img/buttons/slider_background.png"
#define SLIDER_CURSOR "assets/img/buttons/slider_cursor.png"

Button slider_create(SDL_Renderer *ren, SDL_Rect hitbox, int min, int max, int default_value);
Button choice_create(SDL_Renderer *ren, SDL_Rect hitbox, int nb_choice, char **choices);

/* **************************************************************** */

#define BLACK "assets/img/buttons/black.png"
#define WHITE "assets/img/buttons/white.png"
#define EMPTY "assets/img/buttons/empty.png"
#define ERROR_HOVER "assets/img/buttons/error.png"
#define HOVER "assets/img/buttons/hover.png"

Button cell_create(SDL_Renderer *ren, SDL_Rect hitbox, int value);

/* **************************************************************** */

#endif /* BUTTON_CREATE_H */