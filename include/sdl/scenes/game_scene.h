#ifndef GAME_SCENE_H
#define GAME_SCENE_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "input.h"
#include "scene.h"

enum game_textures { GAME_BACKGROUND, NB_GAME_TEXTURES };
enum game_buttons { MAIN_MENU, NB_GAME_BUTTONS };
enum game_texts { NB_GAME_TEXTS };
enum game_fonts { NB_GAME_FONTS };
enum game_mixers { NB_GAME_MIXERS };

/* **************************************************************** */

void game_init(Scene scene, SDL_Renderer *ren);
void game_process(Scene *scenes, Input input, SDL_Renderer *ren);

/* **************************************************************** */

bool main_menu(Scene *scenes);

#endif /* GAME_SCENE_H */