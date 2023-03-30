#include "input.h"

#include <assert.h>

Input input_init() {
    Input input = malloc(sizeof(struct Input_s));
    assert(input);

    input->mouse_pos = (SDL_Point){0, 0};
    input->mouse_action = NO_ACTION;

    input->key_code = 0;
    input->key_action = NO_KEY;

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
        if (event->key.keysym.sym != input->key_code) {
            input->key_code = event->key.keysym.sym;
            input->key_action = KEY_DOWN;
        } else
            input->key_action = KEY_REPEAT;
    } else if (event->type == SDL_KEYUP) {
        input->key_code = 0;
        input->key_action = NO_KEY;
    } else if (input->key_action == KEY_DOWN) {
        input->key_action = KEY_REPEAT;
    }

    // if (input->key_action == NO_KEY)
    //     printf("[]   NO_KEY\n\n");
    // else if (input->key_action == KEY_DOWN)
    //     printf("[%d]   KEY_DOWN\n\n", input->key_code);
    // else if (input->key_action == KEY_REPEAT)
    //     printf("[%d]   KEY_REPEAT\n\n", input->key_code);
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

/* **************************************************************** */

bool key_down(Input input, int key_code) { return (input->key_code == key_code && input->key_action == KEY_DOWN); }

bool key_repeat(Input input, int key_code) { return (input->key_code == key_code && input->key_action == KEY_REPEAT); }