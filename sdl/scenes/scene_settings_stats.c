#include "takuzu.h"

// Loader
void sst_init(SDL_Window *win, SDL_Renderer *ren, int argc, char *argv[], Env *env) { return; }

// Renderer
void sst_render(SDL_Window *win, SDL_Renderer *ren, Env *env) {
    if (env->active_scene != SETTINGS_STATS)
        return;
}

// Input Processor
bool sst_process(SDL_Window *win, SDL_Renderer *ren, Env *env, SDL_Event *e) {
    if (env->active_scene != SETTINGS_STATS)
        return;

    return false;
}

// Destructor
void sst_clean(SDL_Window *win, SDL_Renderer *ren, Env *env) { return; }

/* ************************************************************************************** */

// Event Handler
