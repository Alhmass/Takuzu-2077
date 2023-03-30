#include "conf.h"

#include "takuzu.h"

Conf conf_init() {
    Conf conf = malloc(sizeof(struct Conf_s));
    assert(conf);

    // Sounds
    conf->sound_volume = 50 * 20 / 100;
    conf->music_volume = 20 * 20 / 100;
    conf->general_volume = 100;

    // Game
    conf->errors = true;
    conf->hover = true;
    conf->timer = true;
    conf->accuracy = true;
    conf->save_path = NULL;
    conf->conf_path = NULL;

    // Graphics
    conf->fullscreen = 0;
    conf->window_size = (SDL_Rect){0, 0, 1600, 900};

    // Status
    conf->last_scene = 0;
    conf->quit = false;
    return conf;
}

void conf_delete(Conf conf) {
    game_delete(conf->takuzu);
    free(conf);
}

void default_conf(Conf conf) {
    // copy "default.txt" to save path
    char *default_path = "default.txt";
    conf->save_path = malloc(sizeof(char) * (strlen(default_path) + 1));
    assert(conf->save_path);
    strcpy(conf->save_path, default_path);

    // copy "default.conf" to conf path
    char *default_conf = "default.conf";
    conf->conf_path = malloc(sizeof(char) * (strlen(default_conf) + 1));
    assert(conf->conf_path);
    strcpy(conf->conf_path, default_conf);

    conf->takuzu = game_default();
}

bool conf_load(Conf conf, char *path) {
    (void)conf;
    (void)path;

    if (strcmp(path, "default.conf") != 0) {
        conf->takuzu = game_load(path);
        if (conf->takuzu == NULL) {
            default_conf(conf);
        } else {
            // copy the file path to the save_path
            conf->save_path = malloc(sizeof(char) * (strlen(path) + 1));
            assert(conf->save_path);
            strcpy(conf->save_path, path);
        }
    } else {
        default_conf(conf);
    }

    // if (file.conf == false)
    //     return false;

    // load settings from file.conf
    return true;
}
bool conf_save(Conf conf, char *path) {
    (void)conf;
    (void)path;

    // if (file.conf == true) {
    //     destroy file.conf
    // }

    // save settings to file.conf

    return true;
}