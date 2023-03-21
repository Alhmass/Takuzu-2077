#include "takuzu.h"

// Loader
void sc_init(SDL_Window *win, SDL_Renderer *ren, int argc, char *argv[], Env *env) { return; }

// Renderer
void sc_render(SDL_Window *win, SDL_Renderer *ren, Env *env) {
    if (env->active_scene != SETTINGS_CONTROLS)
        return;
}

// Input Processor
bool sc_process(SDL_Window *win, SDL_Renderer *ren, Env *env, SDL_Event *e) {
    if (env->active_scene != SETTINGS_CONTROLS)
        return;

    return false;
}

// Destructor
void sc_clean(SDL_Window *win, SDL_Renderer *ren, Env *env) { return; }

/* ************************************************************************************** */

// Event Handler
