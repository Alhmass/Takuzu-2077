#ifndef SAVED_H
#define SAVED_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "input.h"
#include "scene.h"

enum saved_textures { NB_SAVED_TEXTURES };
enum saved_buttons { NB_SAVED_BUTTONS };
enum saved_texts { NB_SAVED_TEXTS };
enum saved_fonts { NB_SAVED_FONTS };
enum saved_mixers { NB_SAVED_MIXERS };

/* **************************************************************** */

void saved_init(Scene scene, SDL_Renderer *ren);
void saved_process(Scene *scenes, Input input, SDL_Renderer *ren);

/* **************************************************************** */

#endif /* SAVED_H */