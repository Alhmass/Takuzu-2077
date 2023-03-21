#ifndef SCENE_NEW_EDITOR_H
#define SCENE_NEW_EDITOR_H

#include "sdl_game.h"

// Loader, renderer, processor, and cleaner
void ne_init(SDL_Window *win, SDL_Renderer *ren, int argc, char *argv[], Env *env);
void ne_render(SDL_Window *win, SDL_Renderer *ren, Env *env);
bool ne_process(SDL_Window *win, SDL_Renderer *ren, Env *env, SDL_Event *e);
void ne_clean(SDL_Window *win, SDL_Renderer *ren, Env *env);

// Scene-specific functions

#endif /* SCENE_NEW_EDITOR_H */