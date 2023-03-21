// SDL2 Model by aurelien.esnard@u-bordeaux.fr

#ifndef ENGINE_H
#define ENGINE_H

#include <SDL.h>
#include <stdbool.h>
#include <stdio.h>

#include "env.h"

/* **************************************************************** */

#ifdef __ANDROID__
#define PRINT(STR, ...)              \
    do {                             \
        SDL_Log(STR, ##__VA_ARGS__); \
    } while (0)
#define ERROR(STR, ...)              \
    do {                             \
        SDL_Log(STR, ##__VA_ARGS__); \
        exit(EXIT_FAILURE);          \
    } while (0)
#else
#define PRINT(STR, ...)             \
    do {                            \
        printf(STR, ##__VA_ARGS__); \
    } while (0)
#define ERROR(STR, ...)                      \
    do {                                     \
        fprintf(stderr, STR, ##__VA_ARGS__); \
        exit(EXIT_FAILURE);                  \
    } while (0)
#endif

/* **************************************************************** */

#define APP_NAME "Takuzu_2077"
#define SCREEN_WIDTH 1600
#define SCREEN_HEIGHT 900
// #define DELAY 100

/* **************************************************************** */

#define X(x, env) ((x) * (env)->screen_width / 1920)
#define Y(y, env) ((y) * (env)->screen_height / 1080)

/* **************************************************************** */

Env* init(SDL_Window* win, SDL_Renderer* ren, int argc, char* argv[]);
void render(SDL_Window* win, SDL_Renderer* ren, Env* env);
void clean(SDL_Window* win, SDL_Renderer* ren, Env* env);
bool process(SDL_Window* win, SDL_Renderer* ren, Env* env, SDL_Event* e);

/* **************************************************************** */

#endif /* ENGINE_H */
