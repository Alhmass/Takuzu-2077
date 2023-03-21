#include "takuzu.h"

// Loader
void ne_init(SDL_Window *win, SDL_Renderer *ren, int argc, char *argv[], Env *env) { return; }

// Renderer
void ne_render(SDL_Window *win, SDL_Renderer *ren, Env *env) {
    if (env->active_scene != NEW_EDITOR)
        return;
}

// Input Processor
bool ne_process(SDL_Window *win, SDL_Renderer *ren, Env *env, SDL_Event *e) {
    if (env->active_scene != NEW_EDITOR)
        return;

    return false;
}

// Destructor
void ne_clean(SDL_Window *win, SDL_Renderer *ren, Env *env) { return; }

/* ************************************************************************************** */

// Event Handler
