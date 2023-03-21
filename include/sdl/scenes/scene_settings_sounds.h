#ifndef SCENE_SETTINGS_SOUNDS_H
#define SCENE_SETTINGS_SOUNDS_H

#include "sdl_game.h"

// Loader, renderer, processor, and cleaner
void sso_init(SDL_Window *win, SDL_Renderer *ren, int argc, char *argv[], Env *env);
void sso_render(SDL_Window *win, SDL_Renderer *ren, Env *env);
bool sso_process(SDL_Window *win, SDL_Renderer *ren, Env *env, SDL_Event *e);
void sso_clean(SDL_Window *win, SDL_Renderer *ren, Env *env);

// Scene-specific functions

#endif /* SCENE_SETTINGS_SOUNDS_H */