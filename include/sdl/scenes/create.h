#ifndef CREATE_H
#define CREATE_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "input.h"
#include "scene.h"

enum create_textures { NB_CREATE_TEXTURES };
enum create_buttons { NB_CREATE_BUTTONS };
enum create_texts { NB_CREATE_TEXTS };
enum create_fonts { NB_CREATE_FONTS };
enum create_mixers { NB_CREATE_MIXERS };

/* **************************************************************** */

void create_init(Scene scene, SDL_Renderer *ren);
void create_process(Scene *scenes, Input input, SDL_Renderer *ren);

/* **************************************************************** */

#endif /* CREATE_H */