#include "engine.h"

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <assert.h>

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

    if (argc > 1) {
        conf_load(env->conf, argv[1]);
    } else
        conf_load(env->conf, "saves/game/default.txt");

    void (*init_list[])(Conf conf, Scene scene, Assets assets, SDL_Renderer * ren) = {
        main_init,   game_init,     create_init,   editor_init, saved_init,   custom_init,
        sounds_init, controls_init, graphics_init, stats_init,  credits_init, NULL};

    for (int i = 0; i < NB_SCENES; i++) {
        SCENE(env, i) = malloc(sizeof(struct Scene_s));
        assert(SCENE(env, i));
        init_list[i](env->conf, SCENE(env, i), env->assets, env->ren);
    }

    SCENE(env, MAIN)->is_active = true;

    return env;
}

/* **************************************************************** */

void render(SDL_Window *win, SDL_Renderer *ren, Env *env) {
    (void)win;
    (void)ren;

    for (int i = 0; i < NB_SCENES; i++) {
        scene_render(SCENE(env, i), i, env->assets, env->ren, env->win_rect, env->input);
    }

    // render the cursor
    SDL_Rect cursor = {0, 0, 40, 40};
    scale_rect(cursor, env->win_rect);
    cursor.x = env->input->mouse_pos.x - cursor.w / 6;
    cursor.y = env->input->mouse_pos.y - cursor.h / 6;
    SDL_RenderCopy(ren, ST(env->assets, CURSOR), NULL, &cursor);
}

/* **************************************************************** */

bool process(SDL_Window *win, SDL_Renderer *ren, Env *env, SDL_Event *e) {
    (void)win;
    (void)ren;

    if (e->type == SDL_QUIT) {
        return true;
    }

    void (*process_list[])(Conf conf, Scene * scenes, Input input, Assets assets, SDL_Renderer * ren,
                           SDL_Rect win_rect) = {main_process,     game_process,   create_process,  editor_process,
                                                 saved_process,    custom_process, sounds_process,  controls_process,
                                                 graphics_process, stats_process,  credits_process, NULL};

    for (int i = 0; i < NB_SCENES; i++) {
        process_list[i](env->conf, env->scenes, env->input, env->assets, env->ren, env->win_rect);
    }
    return false;
}

/* **************************************************************** */

void clean(SDL_Window *win, SDL_Renderer *ren, Env *env) {
    (void)win;
    (void)ren;

    for (int i = 0; i < NB_SCENES; i++) {
        scene_delete(SCENE(env, i));
    }

    env_delete(env);
}

/* **************************************************************** */
