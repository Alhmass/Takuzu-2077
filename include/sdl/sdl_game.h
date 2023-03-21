#ifndef SDL_GAME_H
#define SDL_GAME_H

/* Libraries */
#include <SDL.h>
#include <SDL_image.h>  // required to load transparent texture from PNG
#include <SDL_mixer.h>  // required to play sounds
#include <SDL_ttf.h>    // required to use TTF fonts

/* Game */
#include "engine.h"
#include "env.h"

/* Scenes */
#include "scene_credits.h"
#include "scene_game.h"
#include "scene_load_custom.h"
#include "scene_load_saved.h"
#include "scene_main.h"
#include "scene_new_create.h"
#include "scene_new_editor.h"
#include "scene_settings_controls.h"
#include "scene_settings_graphics.h"
#include "scene_settings_sounds.h"
#include "scene_settings_stats.h"

#endif /* SDL_GAME_H */