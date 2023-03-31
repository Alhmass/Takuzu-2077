#include "conf.h"

#include "takuzu.h"

Conf conf_init() {
    Conf conf = malloc(sizeof(struct Conf_s));
    assert(conf);

    conf->takuzu = NULL;

    // Sounds
    char *music_volume = get_setting("general.conf", "music_volume");
    char *sound_volume = get_setting("general.conf", "sound_volume");
    char *general_volume = get_setting("general.conf", "general_volume");
    char *mouse_hover = get_setting("general.conf", "mouse_hover");
    char *mouse_click = get_setting("general.conf", "mouse_click");
    char *game_music = get_setting("general.conf", "game_music");
    char *game_effects = get_setting("general.conf", "game_effects");
    assert(music_volume);
    assert(sound_volume);
    assert(general_volume);
    assert(mouse_hover);
    assert(mouse_click);
    assert(game_music);
    assert(game_effects);
    conf->music_volume = atoi(music_volume);
    conf->sound_volume = atoi(sound_volume);
    conf->general_volume = atoi(sound_volume);
    conf->mouse_hover = (bool)atoi(mouse_hover);
    conf->mouse_click = (bool)atoi(mouse_click);
    conf->game_music = (bool)atoi(game_music);
    conf->game_effects = (bool)atoi(game_effects);
    // Graphics
    char *fullscreen = get_setting("general.conf", "fullscreen");
    char *resolution = get_setting("general.conf", "resolution");
    char *rtx = get_setting("general.conf", "rtx");
    assert(fullscreen);
    assert(resolution);
    assert(rtx);
    conf->fullscreen = (bool)atoi(fullscreen);
    conf->resolution = resolution;
    conf->rtx = (bool)atoi(rtx);
    // Game

    // Non persistent settings
    conf->save_path = NULL;
    conf->conf_path = NULL;
    conf->window_size = (SDL_Rect){0, 0, 1600, 900};
    conf->last_scene = 0;
    conf->selected = 0;
    conf->quit = false;
    free(music_volume);
    free(sound_volume);
    free(general_volume);
    free(mouse_hover);
    free(mouse_click);
    free(game_music);
    free(game_effects);
    free(fullscreen);
    free(rtx);
    return conf;
}

void conf_delete(Conf conf) {
    game_delete(conf->takuzu);
    free(conf);
}

bool default_conf(Conf conf) {
    // copy "default.txt" to save path
    char *default_path = "saves/game/default.txt";
    conf->save_path = malloc(sizeof(char) * (strlen(default_path) + 1));
    assert(conf->save_path);
    strcpy(conf->save_path, default_path);

    // copy "default.conf" to conf path
    char *default_conf = "saves/game/default.conf";
    conf->conf_path = malloc(sizeof(char) * (strlen(default_conf) + 1));
    assert(conf->conf_path);
    strcpy(conf->conf_path, default_conf);

    conf->takuzu = game_default();
    FILE *conf_file = fopen(default_conf, "r");
    if (!conf_file)
        copy_file("stats.txt", default_conf);
    else {
        fclose(conf_file);
    }
    return true;
}

bool conf_load(Conf conf, char *path) {
    (void)conf;
    (void)path;

    if (strcmp(path, "saves/game/default.txt") != 0) {
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
                copy_file("template.conf", conf_path);
                conf->conf_path = malloc(sizeof(char) * (strlen(conf_path) + 1));
                assert(conf->conf_path);
                strcpy(conf->conf_path, conf_path);
                free(conf_path);
            } else {
                conf->conf_path = malloc(sizeof(char) * (strlen(conf_path) + 1));
                assert(conf->conf_path);
                strcpy(conf->conf_path, conf_path);
            }
        }
    } else {
        default_conf(conf);
    }

    return true;
}
bool conf_save(Conf conf, char *path) {
    // char buf[256];
    // remove(path);
    // copy_file("default.conf", path);
    // if (sprintf(buf, "%d", conf->music_volume) < 0)
    //     return false;
    // if (!set_setting(path, "volume_music", buf))
    //     return false;
    // if (sprintf(buf, "%d", conf->sound_volume) < 0)
    //     return false;
    // if (!set_setting(path, "volume_effects", buf))
    //     return false;
    // if (sprintf(buf, "%d", conf->general_volume) < 0)
    //     return false;
    // if (!set_setting(path, "volume_general", buf))
    //     return false;
    // if (sprintf(buf, "%d", conf->timer) < 0)
    //     return false;
    // if (!set_setting(path, "Timer", buf))
    //     return false;
    // if (sprintf(buf, "%d", conf->accuracy) < 0)
    //     return false;
    // if (!set_setting(path, "Accuracy", buf))
    //     return false;
    return true;
}