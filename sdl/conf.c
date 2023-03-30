#include "conf.h"

#include "takuzu.h"

Conf conf_init() {
    Conf conf = malloc(sizeof(struct Conf_s));
    assert(conf);

    // default value for all settings

    conf->sound_volume = 50 * 20 / 100;
    conf->music_volume = 20 * 20 / 100;
    conf->general_volume = 100;

    conf->quit = false;
    return conf;
}

void conf_delete(Conf conf) {
    game_delete(conf->takuzu);
    free(conf);
}

bool conf_load(Conf conf, const char *path) {
    (void)conf;
    (void)path;

    // if (file.conf == false)
    //     return false;

    // load settings from file.conf
    return true;
}
bool conf_save(Conf conf, const char *path) {
    (void)conf;
    (void)path;

    // if (file.conf == true) {
    //     destroy file.conf
    // }

    // save settings to file.conf

    return true;
}