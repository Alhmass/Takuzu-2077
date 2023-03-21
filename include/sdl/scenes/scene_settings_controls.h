#ifndef SCENE_SETTINGS_CONTROLS_H
#define SCENE_SETTINGS_CONTROLS_H

#include "sdl_game.h"

// Loader, renderer, processor, and cleaner
void sc_init(SDL_Window *win, SDL_Renderer *ren, int argc, char *argv[], Env *env);
void sc_render(SDL_Window *win, SDL_Renderer *ren, Env *env);
bool sc_process(SDL_Window *win, SDL_Renderer *ren, Env *env, SDL_Event *e);
void sc_clean(SDL_Window *win, SDL_Renderer *ren, Env *env);

// Scene-specific functions

#endif /* SCENE_SETTINGS_CONTROLS_H */