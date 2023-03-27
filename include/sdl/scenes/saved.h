#ifndef SAVED_H
#define SAVED_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "input.h"
#include "scene.h"

/* **************************************************************** */

void saved_init(Scene scene, Assets assets, SDL_Renderer *ren);
void saved_process(Scene *scenes, Input input, Assets assets, SDL_Renderer *ren, SDL_Rect win_rect);

/* **************************************************************** */

#endif /* SAVED_H */