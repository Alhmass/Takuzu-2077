#ifndef SCENE_LOAD_SAVED_H
#define SCENE_LOAD_SAVED_H

#include "sdl_game.h"

// Loader, renderer, processor, and cleaner
void ls_init(SDL_Window *win, SDL_Renderer *ren, int argc, char *argv[], Env *env);
void ls_render(SDL_Window *win, SDL_Renderer *ren, Env *env);
bool ls_process(SDL_Window *win, SDL_Renderer *ren, Env *env, SDL_Event *e);
void ls_clean(SDL_Window *win, SDL_Renderer *ren, Env *env);

// Scene-specific functions

#endif /* SCENE_LOAD_SAVED_H */