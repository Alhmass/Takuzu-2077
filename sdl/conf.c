#include "conf.h"

#include "takuzu.h"

Conf conf_init() {
    Conf conf = malloc(sizeof(struct Conf_s));
    assert(conf);

    conf->takuzu = NULL;

    // Sounds

    // Graphics

    // Game

    // Non persistent settings
    // conf->save_path;
    // conf->conf_path;
    // conf->window_size;
    // conf->last_scene;
    // conf->selected;
    // conf->quit;
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
        if (!get_conf(conf))
            return false;
    }
    return true;
}

bool get_conf(Conf conf) {
    char *music_volume = get_setting(conf->conf_path, "volume_music");
    char *sound_volume = get_setting(conf->conf_path, "volume_effects");
    char *general_volume = get_setting(conf->conf_path, "volume_general");
    char *game_timer = get_setting(conf->conf_path, "Timer");
    char *accuracy = get_setting(conf->conf_path, "Accuracy");
    if (!music_volume || !sound_volume || !general_volume || !game_timer || !accuracy)
        return false;
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
                copy_file("stats.conf", conf_path);
                conf->conf_path = malloc(sizeof(char) * (strlen(conf_path) + 1));
                assert(conf->conf_path);
                strcpy(conf->conf_path, conf_path);
                free(conf_path);
            } else {
                conf->conf_path = malloc(sizeof(char) * (strlen(conf_path) + 1));
                assert(conf->conf_path);
                strcpy(conf->conf_path, conf_path);
                if (!get_conf(conf))
                    return false;
            }
        }
    } else {
        default_conf(conf);
    }

    return true;
}
bool conf_save(Conf conf, char *path) {
    char buf[256];
    remove(path);
    copy_file("default.conf", path);
    if (sprintf(buf, "%d", conf->music_volume) < 0)
        return false;
    if (!set_setting(path, "volume_music", buf))
        return false;
    if (sprintf(buf, "%d", conf->sound_volume) < 0)
        return false;
    if (!set_setting(path, "volume_effects", buf))
        return false;
    if (sprintf(buf, "%d", conf->general_volume) < 0)
        return false;
    if (!set_setting(path, "volume_general", buf))
        return false;
    if (sprintf(buf, "%d", conf->timer) < 0)
        return false;
    if (!set_setting(path, "Timer", buf))
        return false;
    if (sprintf(buf, "%d", conf->accuracy) < 0)
        return false;
    if (!set_setting(path, "Accuracy", buf))
        return false;
    return true;
}