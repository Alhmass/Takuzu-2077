#ifndef CUSTOM_H
#define CUSTOM_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "input.h"
#include "scene.h"

/* **************************************************************** */

void custom_init(Scene scene, Assets assets, SDL_Renderer *ren);
void custom_process(Scene *scenes, Input input, Assets assets, SDL_Renderer *ren, SDL_Rect win_rect);

/* **************************************************************** */

#endif /* CUSTOM_H */