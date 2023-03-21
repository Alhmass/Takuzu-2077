#include "takuzu.h"

// Loader
void lc_init(SDL_Window *win, SDL_Renderer *ren, int argc, char *argv[], Env *env) { return; }

// Renderer
void lc_render(SDL_Window *win, SDL_Renderer *ren, Env *env) {
    if (env->active_scene != LOAD_CUSTOM)
        return;
}

// Input Processor
bool lc_process(SDL_Window *win, SDL_Renderer *ren, Env *env, SDL_Event *e) {
    if (env->active_scene != LOAD_CUSTOM)
        return;

    return false;
}

// Destructor
void lc_clean(SDL_Window *win, SDL_Renderer *ren, Env *env) { return; }

/* ************************************************************************************** */

// Event Handler
