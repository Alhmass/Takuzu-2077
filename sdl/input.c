#include "input.h"

#include <assert.h>

Input input_init() {
    Input input = malloc(sizeof(struct Input_s));
    assert(input);

    input->mouse_pos.x = 0;
    input->mouse_pos.y = 0;
    input->mouse_action = NO_ACTION;

    input->key_code = 0;
    input->key_action = 0;

    return input;
}

void input_update(Input input, SDL_Event *event) {
    // Mouse Input
    SDL_GetMouseState(&input->mouse_pos.x, &input->mouse_pos.y);
    if (event->type == SDL_MOUSEBUTTONDOWN) {
        if (event->button.button == SDL_BUTTON_LEFT) {
            input->mouse_action = LEFT_CLICK;
        } else if (event->button.button == SDL_BUTTON_RIGHT) {
            input->mouse_action = RIGHT_CLICK;
        }
    } else if (event->type == SDL_MOUSEBUTTONUP) {
        input->mouse_action = NO_ACTION;
    } else if (input->mouse_action == LEFT_CLICK) {
        input->mouse_action = LEFT_DRAG;
    } else if (input->mouse_action == RIGHT_CLICK) {
        input->mouse_action = RIGHT_DRAG;
    }
    // char *action[5] = {"NO_ACTION", "LEFT_CLICK", "LEFT_DRAG", "RIGHT_CLICK", "RIGHT_DRAG"};
    // printf("[%d, %d]  %s\n", input->mouse_pos.x, input->mouse_pos.y, action[input->mouse_action]);

    // Keyboard Input
    if (event->type == SDL_KEYDOWN) {
        input->key_code = event->key.keysym.sym;
        input->key_action = event->key.state;
    } else if (event->type == SDL_KEYUP) {
        input->key_code = 0;
        input->key_action = event->key.state;
    }
    // printf("[%c, %d]  KEY\n\n", input->key_code, input->key_action);
}

/* **************************************************************** */

bool left_press(SDL_Rect rect, Input input) { return (left_click(rect, input) || left_drag(rect, input)); }

bool left_click(SDL_Rect rect, Input input) {
    return (input->mouse_action == LEFT_CLICK && SDL_PointInRect(&input->mouse_pos, &rect));
}

bool left_drag(SDL_Rect rect, Input input) {
    return (input->mouse_action == LEFT_DRAG && SDL_PointInRect(&input->mouse_pos, &rect));
}

/* **************************************************************** */

bool right_press(SDL_Rect rect, Input input) { return (right_click(rect, input) || right_drag(rect, input)); }

bool right_click(SDL_Rect rect, Input input) {
    return (input->mouse_action == RIGHT_CLICK && SDL_PointInRect(&input->mouse_pos, &rect));
}

bool right_drag(SDL_Rect rect, Input input) {
    return (input->mouse_action == RIGHT_DRAG && SDL_PointInRect(&input->mouse_pos, &rect));
}

/* **************************************************************** */

bool is_hovered(SDL_Rect rect, Input input) { return (SDL_PointInRect(&input->mouse_pos, &rect)); }
