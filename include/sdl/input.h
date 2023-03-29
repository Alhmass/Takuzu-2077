#ifndef INPUT_H
#define INPUT_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

/* **************************************************************** */

enum mouse_action { NO_ACTION, LEFT_CLICK, LEFT_DRAG, RIGHT_CLICK, RIGHT_DRAG };

/* **************************************************************** */

struct Input_s {
    SDL_Point mouse_pos;
    int mouse_action;
    // Props Keyboard
};

typedef struct Input_s *Input;

/* **************************************************************** */

#endif /* INPUT_H */