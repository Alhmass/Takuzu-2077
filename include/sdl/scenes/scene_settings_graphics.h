#ifndef SCENE_SETTINGS_GRAPHICS_H
#define SCENE_SETTINGS_GRAPHICS_H

#include "sdl_game.h"

// Loader, renderer, processor, and cleaner
void sg_init(SDL_Window *win, SDL_Renderer *ren, int argc, char *argv[], Env *env);
void sg_render(SDL_Window *win, SDL_Renderer *ren, Env *env);
bool sg_process(SDL_Window *win, SDL_Renderer *ren, Env *env, SDL_Event *e);
void sg_clean(SDL_Window *win, SDL_Renderer *ren, Env *env);

// Scene-specific functions

#endif /* SCENE_SETTINGS_GRAPHICS_H */