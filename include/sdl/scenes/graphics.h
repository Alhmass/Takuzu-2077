#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "input.h"
#include "scene.h"

enum graphics_textures { NB_GRAPHICS_TEXTURES };
enum graphics_buttons { NB_GRAPHICS_BUTTONS };
enum graphics_texts { NB_GRAPHICS_TEXTS };
enum graphics_fonts { NB_GRAPHICS_FONTS };
enum graphics_mixers { NB_GRAPHICS_MIXERS };

/* **************************************************************** */

void graphics_init(Scene scene, SDL_Renderer *ren);
void graphics_process(Scene *scenes, Input input, SDL_Renderer *ren);

/* **************************************************************** */

#endif /* GRAPHICS_H */