#ifndef CHOICE_H
#define CHOICE_H

#include <SDL.h>
#include <stdbool.h>

#include "assets.h"
#include "input.h"
#include "text.h"

/* **************************************************************** */

struct Choice_s {
    SDL_Rect hitbox;  // hitbox for rendering
    SDL_Rect scaled;  // scaled hitbox for rendering

    SDL_Rect hitbox_prev;  // previous button hitbox
    SDL_Rect scaled_prev;  // previous button scaled hitbox

    SDL_Rect hitbox_next;  // next button hitbox
    SDL_Rect scaled_next;  // next button scaled hitbox

    Text *choices;
    int current_choice;
    int nb_choice;

    bool pressed;
    bool hovered;
};

typedef struct Choice_s *Choice;

/* **************************************************************** */

Choice choice_create(SDL_Rect hitbox, char **choices, int nb_choice, int default_choice, Assets assets,
                     SDL_Renderer *ren);
void choice_delete(Choice button);
void choice_render(Choice button, Assets assets, SDL_Renderer *ren, SDL_Rect win_rect);

// returns the new choice number
bool choice_pressed(Choice button, Input input, SDL_Rect win_rect, Assets assets);
bool choice_hovered(Choice button, Input input, SDL_Rect win_rect, Assets assets);

#endif /* CHOICE_H */