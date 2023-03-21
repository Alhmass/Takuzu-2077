#include "takuzu.h"

// Loader
void sg_init(SDL_Window *win, SDL_Renderer *ren, int argc, char *argv[], Env *env) { return; }

// Renderer
void sg_render(SDL_Window *win, SDL_Renderer *ren, Env *env) {
    if (env->active_scene != SETTINGS_GRAPHICS)
        return;
}

// Input Processor
bool sg_process(SDL_Window *win, SDL_Renderer *ren, Env *env, SDL_Event *e) {
    if (env->active_scene != SETTINGS_GRAPHICS)
        return;

    return false;
}

// Destructor
void sg_clean(SDL_Window *win, SDL_Renderer *ren, Env *env) { return; }

/* ************************************************************************************** */

// Event Handler
