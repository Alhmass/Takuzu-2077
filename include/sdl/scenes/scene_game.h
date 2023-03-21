#ifndef SCENE_GAME_H
#define SCENE_GAME_H

#include "sdl_game.h"

// Loader, renderer, processor, and cleaner
void g_init(SDL_Window *win, SDL_Renderer *ren, int argc, char *argv[], Env *env);
void g_render(SDL_Window *win, SDL_Renderer *ren, Env *env);
bool g_process(SDL_Window *win, SDL_Renderer *ren, Env *env, SDL_Event *e);
void g_clean(SDL_Window *win, SDL_Renderer *ren, Env *env);

// Scene-specific functions

#endif /* SCENE_GAME_H */