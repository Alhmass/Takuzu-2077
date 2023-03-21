#include "takuzu.h"

// Loader
void m_init(SDL_Window *win, SDL_Renderer *ren, int argc, char *argv[], Env *env) {
    env->background = IMG_LoadTexture(ren, "assets/img/main/main.png");
    if (!env->background)
        ERROR("Error: IMG_LoadTexture (%s)", SDL_GetError());
}

// Renderer
void m_render(SDL_Window *win, SDL_Renderer *ren, Env *env) {
    // RENDER TEXUTRES
    SDL_RenderCopy(ren, env->background, NULL, NULL);
}

// Input Processor
bool m_process(SDL_Window *win, SDL_Renderer *ren, Env *env, SDL_Event *e) { return false; }

// Destructor
void m_clean(SDL_Window *win, SDL_Renderer *ren, Env *env) { return; }

/* ************************************************************************************** */

// Event Handler
