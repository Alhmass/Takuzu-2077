#include "env.h"

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "engine.h"
#include "sdl_game.h"
#include "takuzu.h"

/* **************************************************************** */

void env_update(Env *env) {
    SDL_Rect rect;
    int w, h;
    SDL_GetWindowSize(env->win, &w, &h);
    env->screen_width = w;
    env->screen_height = h;
}

/* **************************************************************** */

void env_delete(Env *env) {
    SDL_DestroyRenderer(env->ren);
    SDL_DestroyWindow(env->win);
    free(env);
}