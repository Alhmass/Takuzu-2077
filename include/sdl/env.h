#ifndef ENV_H
#define ENV_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "game.h"

/* **************************************************************** */

/**
 * @brief The active scene
 * @details Contains all the scenes of the game
 */
enum scenes {
    MAIN,
    GAME,
    NEW_CREATE,
    NEW_EDITOR,
    LOAD_SAVED,
    LOAD_CUSTOM,
    SETTINGS_SOUNDS,
    SETTINGS_CONTROLS,
    SETTINGS_GRAPHICS,
    SETTINGS_STATS,
    CREDITS
};

/* **************************************************************** */

/**
 * @brief The environment
 * @details This structure contains all the data of the game
 */
struct Env_t {
    SDL_Window *win;
    SDL_Renderer *ren;

    int active_scene;

    uint screen_width;
    uint screen_height;

    game game;

    SDL_Texture *background;
    SDL_Texture *button1;
    int button1_x, button1_y;
};

/**
 * @brief Environment type definition (opaque)
 */
typedef struct Env_t Env;

/* **************************************************************** */

/**
 * @brief Update the environment
 * @param env The environment
 */
void env_update(Env *env);

/**
 * @brief Destroy the environment
 * @param env The environment
 */
void env_delete(Env *env);

#endif /* ENV_H */