#ifndef CONTROLS_H
#define CONTROLS_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "input.h"
#include "scene.h"

enum controls_textures { NB_CONTROLS_TEXTURES };
enum controls_buttons { NB_CONTROLS_BUTTONS };
enum controls_texts { NB_CONTROLS_TEXTS };
enum controls_fonts { NB_CONTROLS_FONTS };
enum controls_mixers { NB_CONTROLS_MIXERS };

/* **************************************************************** */

void controls_init(Scene scene, SDL_Renderer *ren);
void controls_process(Scene *scenes, Input input, SDL_Renderer *ren);

/* **************************************************************** */

#endif /* CONTROLS_H */