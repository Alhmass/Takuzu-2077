#ifndef SOUNDS_H
#define SOUNDS_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "input.h"
#include "scene.h"

enum sounds_textures { NB_SOUNDS_TEXTURES };
enum sounds_buttons { NB_SOUNDS_BUTTONS };
enum sounds_texts { NB_SOUNDS_TEXTS };
enum sounds_fonts { NB_SOUNDS_FONTS };
enum sounds_mixers { NB_SOUNDS_MIXERS };

/* **************************************************************** */

void sounds_init(Scene scene, SDL_Renderer *ren);
void sounds_process(Scene *scenes, Input input, SDL_Renderer *ren);

/* **************************************************************** */

#endif /* SOUNDS_H */