#ifndef STATS_H
#define STATS_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "input.h"
#include "scene.h"

enum stats_textures { NB_STATS_TEXTURES };
enum stats_buttons { NB_STATS_BUTTONS };
enum stats_texts { NB_STATS_TEXTS };
enum stats_fonts { NB_STATS_FONTS };
enum stats_mixers { NB_STATS_MIXERS };

/* **************************************************************** */

void stats_init(Scene scene, SDL_Renderer *ren);
void stats_process(Scene *scenes, Input input, SDL_Renderer *ren);

/* **************************************************************** */

#endif /* STATS_H */