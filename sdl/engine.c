#include "engine.h"

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "controls.h"
#include "create.h"
#include "credits.h"
#include "custom.h"
#include "editor.h"
#include "env.h"
#include "game_scene.h"
#include "graphics.h"
#include "main.h"
#include "saved.h"
#include "scene.h"
#include "sounds.h"
#include "stats.h"
#include "takuzu.h"

/* **************************************************************** */

Env *init(SDL_Window *win, SDL_Renderer *ren, int argc, char *argv[]) {
    Env *env = env_init(win, ren);

    if (argc > 1)
        env->takuzu = game_load(argv[1]);
    else
        env->takuzu = game_default();

    void (*init_list[])(Scene scene, SDL_Renderer * ren, SDL_Rect win_rect) = {
        main_init,   game_init,   controls_init, stats_init,    sounds_init,  saved_init,
        create_init, custom_init, editor_init,   graphics_init, credits_init, NULL};

    for (int i = 0; init_list[i] != NULL; i++) {
        SCENE(env, i) = malloc(sizeof(struct Scene_s));
        init_list[i](SCENE(env, i), env->ren, env->win_rect);
    }

    SCENE(env, MAIN)->is_active = true;

    return env;
}

/* **************************************************************** */

void render(SDL_Window *win, SDL_Renderer *ren, Env *env) {
    (void)win;
    (void)ren;

    for (int i = 0; i < NB_SCENES; i++) {
        scene_render(SCENE(env, i), env->ren, env->win_rect);
    }
}

/* **************************************************************** */

bool process(SDL_Window *win, SDL_Renderer *ren, Env *env, SDL_Event *e) {
    (void)win;
    (void)ren;

    if (e->type == SDL_QUIT) {
        return true;
    }

    void (*process_list[])(Scene * scenes, Input input, SDL_Renderer * ren) = {
        main_process,   game_process,   controls_process, stats_process,    sounds_process,  saved_process,
        create_process, custom_process, editor_process,   graphics_process, credits_process, NULL};

    for (int i = 0; process_list[i] != NULL; i++) {
        process_list[i](env->scenes, env->input, env->ren);
    }
    return false;
}

/* **************************************************************** */

void clean(SDL_Window *win, SDL_Renderer *ren, Env *env) {
    (void)win;
    (void)ren;

    for (int i = 0; i < NB_SCENES; i++) {
        scene_delete(SCENE(env, i), env->ren);
    }

    env_delete(env);
}

/* **************************************************************** */
