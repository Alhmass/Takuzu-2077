#include "conf.h"

#include "takuzu.h"

Conf conf_init() {
    Conf conf = malloc(sizeof(struct Conf_s));
    assert(conf);

    conf->takuzu = game_default();

    return conf;
}

void conf_delete(Conf conf) {
    game_delete(conf->takuzu);
    free(conf);
}

bool conf_load(Conf conf, const char *path) {
    (void)conf;
    (void)path;
    return false;
}
bool conf_save(Conf conf, const char *path) {
    (void)conf;
    (void)path;
    return false;
}