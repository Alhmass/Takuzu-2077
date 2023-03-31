#include "env.h"

#include "conf.h"
#include "input.h"

/* **************************************************************** */

Env *env_init(SDL_Window *win, SDL_Renderer *ren) {
    Env *env = (Env *)malloc(sizeof(struct Env_t));
    assert(env);

    env->conf = conf_init();
    env->input = input_init();

    /****** SDL ******/
    env->win = win;
    env->ren = ren;
    SDL_GetWindowPosition(env->win, &WIN_X(env), &WIN_Y(env));
    SDL_GetWindowSize(env->win, &WIN_W(env), &WIN_H(env));
    SDL_SetWindowMinimumSize(env->win, 800, 450);
    SDL_SetWindowMaximumSize(env->win, 1920, 1080);
    SDL_SetWindowPosition(env->win, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
    // SDL_SetWindowFullscreen(win, SDL_WINDOW_FULLSCREEN_DESKTOP);

    /****** Backend ******/
    env->scenes = malloc(sizeof(struct Scene_s) * NB_SCENES);
    assert(env->scenes);

    env->assets = assets_init(env->ren);
    assert(env->assets);
    if (Mix_PlayMusic(MUSIC(env->assets, MENU_LOOP), -1) == -1)
        fprintf(stderr, "Mix_PlayMusic: %s\n", Mix_GetError());
    Mix_VolumeMusic(env->conf->music_volume);

    env->input = malloc(sizeof(struct Input_s));
    assert(env->input);

    return env;
}

void env_update(Env *env, SDL_Event *event) {
    SDL_GetWindowPosition(env->win, &WIN_X(env), &WIN_Y(env));
    SDL_GetWindowSize(env->win, &WIN_W(env), &WIN_H(env));

    // if (env->conf->fullscreen) {
    //     SDL_SetWindowFullscreen(env->win, SDL_WINDOW_FULLSCREEN_DESKTOP);
    //     SDL_DisplayMode DM;
    //     SDL_GetCurrentDisplayMode(0, &DM);
    //     WIN_W(env) = DM.w;
    //     WIN_H(env) = DM.h;
    // } else {
    //     SDL_SetWindowFullscreen(env->win, 0);
    //     WIN_W(env) = env->conf->window_size.w;
    //     WIN_H(env) = env->conf->window_size.h;
    //     SDL_SetWindowSize(env->win, WIN_W(env), WIN_H(env));
    //     SDL_SetWindowPosition(env->win, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
    // }

    input_update(env->input, event);
}

/* **************************************************************** */

void env_delete(Env *env) {
    free(env->scenes);
    free(env->input);
    SDL_DestroyRenderer(env->ren);
    SDL_DestroyWindow(env->win);
    conf_delete(env->conf);
    free(env);
}