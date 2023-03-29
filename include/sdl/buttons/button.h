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

SDL_Rect scale_rect(SDL_Rect rect, SDL_Rect win_rect);

bool left_press(SDL_Rect rect, Input input);
bool left_click(SDL_Rect rect, Input input);
bool left_drag(SDL_Rect rect, Input input);

bool right_press(SDL_Rect rect, Input input);
bool right_click(SDL_Rect rect, Input input);
bool right_drag(SDL_Rect rect, Input input);

bool is_hovered(SDL_Rect rect, Input input);

#endif /* BUTTON_H */