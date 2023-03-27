#ifndef STATS_H
#define STATS_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "input.h"
#include "scene.h"

/* **************************************************************** */

void stats_init(Scene scene, Assets assets, SDL_Renderer *ren);
void stats_process(Scene *scenes, Input input, Assets assets, SDL_Renderer *ren, SDL_Rect win_rect);

/* **************************************************************** */

#endif /* STATS_H */