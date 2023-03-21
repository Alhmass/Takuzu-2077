#include "takuzu.h"

// Loader
void ls_init(SDL_Window *win, SDL_Renderer *ren, int argc, char *argv[], Env *env) { return; }

// Renderer
void ls_render(SDL_Window *win, SDL_Renderer *ren, Env *env) {
    if (env->active_scene != LOAD_SAVED)
        return;
}

// Input Processor
bool ls_process(SDL_Window *win, SDL_Renderer *ren, Env *env, SDL_Event *e) {
    if (env->active_scene != LOAD_SAVED)
        return;

    return false;
}

// Destructor
void ls_clean(SDL_Window *win, SDL_Renderer *ren, Env *env) { return; }

/* ************************************************************************************** */

// Event Handler
