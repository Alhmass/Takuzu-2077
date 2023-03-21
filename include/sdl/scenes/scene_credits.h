#ifndef SCENE_CREDITS_H
#define SCENE_CREDITS_H

#include "sdl_game.h"

// Loader, renderer, processor, and cleaner
void c_init(SDL_Window *win, SDL_Renderer *ren, int argc, char *argv[], Env *env);
void c_render(SDL_Window *win, SDL_Renderer *ren, Env *env);
bool c_process(SDL_Window *win, SDL_Renderer *ren, Env *env, SDL_Event *e);
void c_clean(SDL_Window *win, SDL_Renderer *ren, Env *env);

// Scene-specific functions

#endif /* SCENE_CREDITS_H */