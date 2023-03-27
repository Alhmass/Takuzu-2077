#ifndef ENV_H
#define ENV_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <assert.h>

#include "assets.h"
#include "game.h"
#include "input.h"
#include "scene.h"

/* **************************************************************** */

struct Env_t {
    /****** SDL ******/
    SDL_Window *win;
    SDL_Renderer *ren;
    SDL_Rect win_rect;

    /****** Backend ******/
    game takuzu;
    Scene *scenes;
    Assets assets;
    Input input;
};

typedef struct Env_t Env;

/* **************************************************************** */

// Direct Access to Window Properties
#define WIN_X(env) ((env)->win_rect.x)
#define WIN_Y(env) ((env)->win_rect.y)
#define WIN_W(env) ((env)->win_rect.w)
#define WIN_H(env) ((env)->win_rect.h)

// Dynamic Scaling
#define X(dim, rect) ((dim) * (rect).w / 1920)
#define Y(dim, rect) ((dim) * (rect).h / 1080)
#define W(dim, rect) ((dim) * (rect).w / 1920)
#define H(dim, rect) ((dim) * (rect).h / 1080)

// Direct Access to Scenes
#define SCENE(env, i) ((env)->scenes[(i)])

// Direct Access to User Input
#define MOUSE_X(env) ((env)->input->mouse_pos.x)
#define MOUSE_Y(env) ((env)->input->mouse_pos.y)
#define CLICK(env) ((env)->input->mouse_action)

/* **************************************************************** */

Env *env_init(SDL_Window *win, SDL_Renderer *ren);
void env_update(Env *env, SDL_Event *event);
void env_delete(Env *env);

#endif /* ENV_H */