#ifndef SOUNDS_H
#define SOUNDS_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "input.h"
#include "scene.h"

/* **************************************************************** */

void sounds_init(Scene scene, Assets assets, SDL_Renderer *ren);
void sounds_process(Scene *scenes, Input input, Assets assets, SDL_Renderer *ren, SDL_Rect win_rect);

/* **************************************************************** */

#endif /* SOUNDS_H */