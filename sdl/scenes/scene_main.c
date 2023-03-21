#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "engine.h"
#include "env.h"
#include "sdl_game.h"
#include "takuzu.h"

// Loader
void m_init(SDL_Window *win, SDL_Renderer *ren, int argc, char *argv[], Env *env) {
    env->background = IMG_LoadTexture(ren, "assets/img/main/main.png");
    if (!env->background)
        ERROR("Error: IMG_LoadTexture (%s)", SDL_GetError());

    env->button1 = IMG_LoadTexture(ren, "assets/img/buttons/default.png");
    if (!env->button1)
        ERROR("Error: IMG_LoadTexture (%s)", SDL_GetError());
}

// Renderer
void m_render(SDL_Window *win, SDL_Renderer *ren, Env *env) {
    if (env->active_scene != MAIN)
        return;

    SDL_Rect rect;
    int w, h;
    SDL_GetWindowSize(win, &w, &h);

    SDL_RenderCopy(ren, env->background, NULL, NULL);

    SDL_QueryTexture(env->button1, NULL, NULL, &rect.w, &rect.h);
    rect.x = X(300, env);
    rect.y = Y(500, env);
    rect.w = X(330, env);
    rect.h = Y(50, env);
    SDL_RenderCopy(ren, env->button1, NULL, &rect);
}

// Input Processor
bool m_process(SDL_Window *win, SDL_Renderer *ren, Env *env, SDL_Event *e) {
    if (env->active_scene != MAIN)
        return;

    return false;
}

// Destructor
void m_clean(SDL_Window *win, SDL_Renderer *ren, Env *env) { return; }

/* ************************************************************************************** */

// Event Handler
