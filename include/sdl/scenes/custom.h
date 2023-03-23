#ifndef CUSTOM_H
#define CUSTOM_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "input.h"
#include "scene.h"

enum custom_textures { NB_CUSTOM_TEXTURES };
enum custom_buttons { NB_CUSTOM_BUTTONS };
enum custom_texts { NB_CUSTOM_TEXTS };
enum custom_fonts { NB_CUSTOM_FONTS };
enum custom_mixers { NB_CUSTOM_MIXERS };

/* **************************************************************** */

void custom_init(Scene scene, SDL_Renderer *ren);
void custom_process(Scene *scenes, Input input, SDL_Renderer *ren);

/* **************************************************************** */

#endif /* CUSTOM_H */