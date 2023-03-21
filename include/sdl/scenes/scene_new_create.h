#ifndef SCENE_NEW_CREATE_H
#define SCENE_NEW_CREATE_H

#include "sdl_game.h"

// Loader, renderer, processor, and cleaner
void nc_init(SDL_Window *win, SDL_Renderer *ren, int argc, char *argv[], Env *env);
void nc_render(SDL_Window *win, SDL_Renderer *ren, Env *env);
bool nc_process(SDL_Window *win, SDL_Renderer *ren, Env *env, SDL_Event *e);
void nc_clean(SDL_Window *win, SDL_Renderer *ren, Env *env);

// Scene-specific functions

#endif /* SCENE_NEW_CREATE_H */