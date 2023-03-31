#ifndef BUTTON_H
#define BUTTON_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <stdbool.h>

#include "assets.h"
#include "cell.h"
#include "choice.h"
#include "default.h"
#include "input.h"
#include "slider.h"
#include "switch.h"
#include "text.h"
#include "toggle.h"

/* **************************************************************** */

/**
 * @brief scale a rect based on the current window size, default resolution is 1920x1080
 * @param rect the rectangle to scale
 * @param win_rect the current window size
 * @return SDL_Rect
 */
SDL_Rect scale_rect(SDL_Rect rect, SDL_Rect win_rect);

#endif /* BUTTON_H */