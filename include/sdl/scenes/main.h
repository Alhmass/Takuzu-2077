#ifndef MAIN_H
#define MAIN_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "input.h"
#include "scene.h"

enum main_textures { MAIN_BACKGROUND, NB_MAIN_TEXTURES };
enum main_buttons { LOAD_GAME, NB_MAIN_BUTTONS };
enum main_texts { NB_MAIN_TEXTS };
enum main_fonts { NB_MAIN_FONTS };
enum main_mixers { NB_MAIN_MIXERS };

/* **************************************************************** */

void main_init(Scene scene, SDL_Renderer *ren);
void main_process(Scene *scenes, Input input, SDL_Renderer *ren);

/* **************************************************************** */

// bool new_game(Scene *scenes);
bool load_game(Scene *scenes);
// bool settings(Scene *scenes);
// bool credits(Scene *scenes);
// bool quit_game(Scene *scenes);

#endif /* MAIN_H */