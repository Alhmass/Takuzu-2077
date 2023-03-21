#ifndef SCENE_SETTINGS_STATS_H
#define SCENE_SETTINGS_STATS_H

#include "sdl_game.h"

// Loader, renderer, processor, and cleaner
void sst_init(SDL_Window *win, SDL_Renderer *ren, int argc, char *argv[], Env *env);
void sst_render(SDL_Window *win, SDL_Renderer *ren, Env *env);
bool sst_process(SDL_Window *win, SDL_Renderer *ren, Env *env, SDL_Event *e);
void sst_clean(SDL_Window *win, SDL_Renderer *ren, Env *env);

// Scene-specific functions

#endif /* SCENE_SETTINGS_STATS_H */