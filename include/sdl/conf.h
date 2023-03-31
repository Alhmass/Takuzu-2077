#ifndef CONF_H
#define CONF_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <assert.h>
#include <stdbool.h>

#include "file.h"
#include "game.h"

/* **************************************************************** */

struct Conf_s {
    game takuzu;

    // Sounds
    int music_volume;
    int sound_volume;
    int general_volume;
    int mouse_hover;
    int mouse_click;
    int game_music;
    int game_effects;

    // Graphics
    bool fullscreen;
    char *resolution;
    bool rtx;

    // Game
    bool errors;
    bool hover;
    bool timer;
    bool accuracy;
    int timer_h;
    int timer_m;
    int timer_s;
    float accuracy_percent;

    // Status - non persistent settings
    char *save_path;
    char *conf_path;
    SDL_Rect window_size;
    int last_scene;
    int selected;
    bool quit;
};

typedef struct Conf_s *Conf;

/* **************************************************************** */

Conf conf_init();
void conf_delete(Conf conf);

bool default_conf(Conf conf);
bool conf_load(Conf conf, char *path);
bool get_conf(Conf conf);
// bool conf_save(Conf conf, char *path);

#endif /* CONF_H */