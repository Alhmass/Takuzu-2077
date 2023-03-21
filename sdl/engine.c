#include "takuzu.h"

/* **************************************************************** */

Env *init(SDL_Window *win, SDL_Renderer *ren, int argc, char *argv[]) {
    Env *env = malloc(sizeof(struct Env_t));

    void (*init_list[])(SDL_Window * win, SDL_Renderer * ren, int argc, char *argv[], Env *env) = {
        m_init, c_init, g_init, lc_init, ls_init, nc_init, ne_init, sc_init, sg_init, sso_init, sst_init, NULL};
    for (int i = 0; init_list[i] != NULL; i++) {
        (*init_list[i])(win, ren, argc, argv, env);
    }
    return env;
}

/* **************************************************************** */

void render(SDL_Window *win, SDL_Renderer *ren, Env *env) {
    /* PUT YOUR CODE HERE TO RENDER TEXTURES, ... */

    void (*render_list[])(SDL_Window * win, SDL_Renderer * ren, Env * env) = {
        m_render,  c_render,  g_render,  lc_render,  ls_render,  nc_render,
        ne_render, sc_render, sg_render, sso_render, sst_render, NULL};
    for (int i = 0; render_list[i] != NULL; i++) {
        (*render_list[i])(win, ren, env);
    }
}

/* **************************************************************** */

bool process(SDL_Window *win, SDL_Renderer *ren, Env *env, SDL_Event *e) {
    if (e->type == SDL_QUIT) {
        return true;
    }

    bool (*process_list[])(SDL_Window * win, SDL_Renderer * ren, Env * env, SDL_Event * e) = {
        m_process,  c_process,  g_process,  lc_process,  ls_process,  nc_process,
        ne_process, sc_process, sg_process, sso_process, sst_process, NULL};
    for (int i = 0; process_list[i] != NULL; i++) {
        if ((*process_list[i])(win, ren, env, e))
            return true;
    }

    return false;
}

/* **************************************************************** */

void clean(SDL_Window *win, SDL_Renderer *ren, Env *env) {
    void (*clean_list[])(SDL_Window * win, SDL_Renderer * ren, Env * env) = {m_clean,  c_clean,   g_clean,   lc_clean,
                                                                             ls_clean, nc_clean,  ne_clean,  sc_clean,
                                                                             sg_clean, sso_clean, sst_clean, NULL};
    for (int i = 0; clean_list[i] != NULL; i++) {
        (*clean_list[i])(win, ren, env);
    }

    free(env);
}

/* **************************************************************** */
