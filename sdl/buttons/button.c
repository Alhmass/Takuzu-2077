#include "button.h"

SDL_Rect scale_rect(SDL_Rect rect, SDL_Rect win_rect) {
    SDL_Rect scaled_rect = rect;
    scaled_rect.x = rect.x * win_rect.w / 1920;
    scaled_rect.y = rect.y * win_rect.h / 1080;
    scaled_rect.w = rect.w * win_rect.w / 1920;
    scaled_rect.h = rect.h * win_rect.h / 1080;
    return scaled_rect;
}
