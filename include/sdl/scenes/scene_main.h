#ifndef SCENE_MAIN_H
#define SCENE_MAIN_H

#include "sdl_game.h"

// Loader, renderer, processor, and cleaner
void m_init(SDL_Window *win, SDL_Renderer *ren, int argc, char *argv[], Env *env);
void m_render(SDL_Window *win, SDL_Renderer *ren, Env *env);
bool m_process(SDL_Window *win, SDL_Renderer *ren, Env *env, SDL_Event *e);
void m_clean(SDL_Window *win, SDL_Renderer *ren, Env *env);

// Scene-specific functions

#endif /* SCENE_MAIN_H */