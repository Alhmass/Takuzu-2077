#include "takuzu.h"

// Loader
void nc_init(SDL_Window *win, SDL_Renderer *ren, int argc, char *argv[], Env *env) { return; }

// Renderer
void nc_render(SDL_Window *win, SDL_Renderer *ren, Env *env) {
    if (env->active_scene != NEW_CREATE)
        return;
}

// Input Processor
bool nc_process(SDL_Window *win, SDL_Renderer *ren, Env *env, SDL_Event *e) {
    if (env->active_scene != NEW_CREATE)
        return;

    return false;
}

// Destructor
void nc_clean(SDL_Window *win, SDL_Renderer *ren, Env *env) { return; }

/* ************************************************************************************** */

// Event Handler
