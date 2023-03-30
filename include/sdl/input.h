#ifndef INPUT_H
#define INPUT_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdbool.h>

/* **************************************************************** */

enum mouse_action { NO_ACTION, LEFT_CLICK, LEFT_DRAG, RIGHT_CLICK, RIGHT_DRAG };

/* **************************************************************** */

struct Input_s {
    SDL_Point mouse_pos;
    int mouse_action;

    int key_code;
    int key_action;
};

typedef struct Input_s *Input;

/* **************************************************************** */

bool left_press(SDL_Rect rect, Input input);
bool left_click(SDL_Rect rect, Input input);
bool left_drag(SDL_Rect rect, Input input);

bool right_press(SDL_Rect rect, Input input);
bool right_click(SDL_Rect rect, Input input);
bool right_drag(SDL_Rect rect, Input input);

bool is_hovered(SDL_Rect rect, Input input);

/* **************************************************************** */

Input input_init();
void input_update(Input input, SDL_Event *event);

#endif /* INPUT_H */