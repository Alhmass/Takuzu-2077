#include "takuzu.h"

// Loader
void g_init(SDL_Window *win, SDL_Renderer *ren, int argc, char *argv[], Env *env) { return; }

// Renderer
void g_render(SDL_Window *win, SDL_Renderer *ren, Env *env) {
    if (env->active_scene != GAME)
        return;
}

// Input Processor
bool g_process(SDL_Window *win, SDL_Renderer *ren, Env *env, SDL_Event *e) {
    if (env->active_scene != GAME)
        return;

    return false;
}

// Destructor
void g_clean(SDL_Window *win, SDL_Renderer *ren, Env *env) { return; }

/* ************************************************************************************** */

// Event Handler
