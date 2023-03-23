#ifndef EDITOR_H
#define EDITOR_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "input.h"
#include "scene.h"

enum editor_textures { NB_EDITOR_TEXTURES };
enum editor_buttons { NB_EDITOR_BUTTONS };
enum editor_texts { NB_EDITOR_TEXTS };
enum editor_fonts { NB_EDITOR_FONTS };
enum editor_mixers { NB_EDITOR_MIXERS };

/* **************************************************************** */

void editor_init(Scene scene, SDL_Renderer *ren);
void editor_process(Scene *scenes, Input input, SDL_Renderer *ren);

/* **************************************************************** */

#endif /* EDITOR_H */