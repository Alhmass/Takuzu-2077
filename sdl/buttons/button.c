#include "button.h"

SDL_Rect scale_rect(SDL_Rect rect, SDL_Rect win_rect) {
    SDL_Rect scaled_rect = rect;
    scaled_rect.x = rect.x * win_rect.w / 1920;
    scaled_rect.y = rect.y * win_rect.h / 1080;
    scaled_rect.w = rect.w * win_rect.w / 1920;
    scaled_rect.h = rect.h * win_rect.h / 1080;
    return scaled_rect;
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
