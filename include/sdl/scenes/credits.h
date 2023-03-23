#ifndef CREDITS_H
#define CREDITS_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "input.h"
#include "scene.h"

enum credits_textures { NB_CREDITS_TEXTURES };
enum credits_buttons { NB_CREDITS_BUTTONS };
enum credits_texts { NB_CREDITS_TEXTS };
enum credits_fonts { NB_CREDITS_FONTS };
enum credits_mixers { NB_CREDITS_MIXERS };

/* **************************************************************** */

void credits_init(Scene scene, SDL_Renderer *ren);
void credits_process(Scene *scenes, Input input, SDL_Renderer *ren);

/* **************************************************************** */

#endif /* CREDITS_H */