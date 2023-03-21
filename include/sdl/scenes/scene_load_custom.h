#ifndef SCENE_LOAD_CUSTOM_H
#define SCENE_LOAD_CUSTOM_H

#include "sdl_game.h"

// Loader, renderer, processor, and cleaner
void lc_init(SDL_Window *win, SDL_Renderer *ren, int argc, char *argv[], Env *env);
void lc_render(SDL_Window *win, SDL_Renderer *ren, Env *env);
bool lc_process(SDL_Window *win, SDL_Renderer *ren, Env *env, SDL_Event *e);
void lc_clean(SDL_Window *win, SDL_Renderer *ren, Env *env);

// Scene-specific functions

#endif /* SCENE_LOAD_CUSTOM_H */