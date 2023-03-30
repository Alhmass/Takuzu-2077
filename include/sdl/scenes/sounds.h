#ifndef SOUNDS_H
#define SOUNDS_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "conf.h"
#include "input.h"
#include "scene.h"

/* **************************************************************** */

void sounds_init(Conf conf, Scene scene, Assets assets, SDL_Renderer *ren);
void sounds_process(Conf conf, Scene *scenes, Input input, Assets assets, SDL_Renderer *ren, SDL_Rect win_rect);

/* **************************************************************** */

#endif /* SOUNDS_H */