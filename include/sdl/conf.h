#ifndef CONF_H
#define CONF_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <assert.h>
#include <stdbool.h>

#include "game.h"

/* **************************************************************** */

struct Conf_s {
    game takuzu;
};

typedef struct Conf_s *Conf;

/* **************************************************************** */

Conf conf_init();
void conf_delete(Conf conf);

bool conf_load(Conf conf, const char *path);
bool conf_save(Conf conf, const char *path);

#endif /* CONF_H */