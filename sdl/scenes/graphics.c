#include "graphics.h"

#include "button.h"
#include "env.h"
#include "input.h"

/* **************************************************************** */

void graphics_init(Scene graphics, Assets assets, SDL_Renderer *ren) { scene_init(graphics, 0, 0, 0, 0, 0, 0, 0); }

void graphics_process(Scene *scenes, Input input, Assets assets, SDL_Renderer *ren, SDL_Rect win_rect) {}

/* **************************************************************** */
