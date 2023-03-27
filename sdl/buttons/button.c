#include "button.h"

SDL_Rect scale_rect(SDL_Rect rect, SDL_Rect win_rect) {
    SDL_Rect scaled_rect;
    scaled_rect.x = rect.x * win_rect.w / 1920;
    scaled_rect.y = rect.y * win_rect.h / 1080;
    scaled_rect.w = rect.w * win_rect.w / 1920;
    scaled_rect.h = rect.h * win_rect.h / 1080;
    return scaled_rect;
}

bool is_pressed(SDL_Rect rect, Input input) { return (is_clicked(rect, input) || is_dragged(rect, input)); }

bool is_clicked(SDL_Rect rect, Input input) {
    return (input->mouse_action == LEFT_CLICK && SDL_PointInRect(&input->mouse_pos, &rect));
}

bool is_hovered(SDL_Rect rect, Input input) {
    return (input->mouse_action == NO_ACTION && SDL_PointInRect(&input->mouse_pos, &rect));
}

bool is_dragged(SDL_Rect rect, Input input) {
    return (input->mouse_action == LEFT_DRAG && SDL_PointInRect(&input->mouse_pos, &rect));
}
