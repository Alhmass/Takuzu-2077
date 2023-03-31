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
            // Load custom conf if exists
            char *first = strtok(path, ".");
            char *conf_path = malloc(sizeof(char) * (strlen(first) + 5));
            assert(conf_path);
            strcpy(conf_path, first);
            strcat(conf_path, ".conf");
            FILE *conf_file = fopen(conf_path, "r");
            if (!conf_file) {
                copy_file("default.conf", conf_path);
                conf->conf_path = malloc(sizeof(char) * (strlen(conf_path) + 1));
                assert(conf->conf_path);
                strcpy(conf->conf_path, conf_path);
                free(conf_path);
            } else {
                conf->conf_path = malloc(sizeof(char) * (strlen(conf_path) + 1));
                assert(conf->conf_path);
                strcpy(conf->conf_path, conf_path);
                char *music_volume = get_setting(conf_path, "volume_music");
                char *sound_volume = get_setting(conf_path, "volume_effects");
                char *general_volume = get_setting(conf_path, "volume_general");
                char *game_timer = get_setting(conf_path, "Timer");
                char *accuracy = get_setting(conf_path, "Accuracy");
                conf->music_volume = atoi(music_volume);
                conf->sound_volume = atoi(sound_volume);
                conf->general_volume = atoi(general_volume);
                conf->timer = atoi(game_timer);
                conf->accuracy = atoi(accuracy);
                free(music_volume);
                free(sound_volume);
                free(general_volume);
                free(game_timer);
                free(accuracy);
                free(conf_path);
            }
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
    remove(path);
    copy_file("default.conf", path);
    set_setting(path, "volume_music", conf->music_volume);
    set_setting(path, "volume_effects", conf->sound_volume);
    set_setting(path, "volume_general" conf->general_volume);
    set_setting(path, "Timer", (int)conf->timer);
    set_setting(path, "Accuracy", (int)conf->accuracy);
    // save settings to file.conf
    return true;
}