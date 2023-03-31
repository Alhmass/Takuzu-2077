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

void conf_game_load(Conf conf) {
    char *errors = get_setting(conf->conf_path, "errors");
    char *hover = get_setting(conf->conf_path, "hover");
    char *timer = get_setting(conf->conf_path, "timer_mode");
    char *accuracy_mode = get_setting(conf->conf_path, "accuracy_mode");
    char *timer_h = get_setting(conf->conf_path, "timer_h");
    char *timer_m = get_setting(conf->conf_path, "timer_m");
    char *timer_s = get_setting(conf->conf_path, "timer_s");
    char *accuracy_percent = get_setting(conf->conf_path, "accuracy_percent");

    assert(errors);
    assert(hover);
    assert(timer);
    assert(accuracy_mode);
    assert(timer_h);
    assert(timer_m);
    assert(timer_s);
    assert(accuracy_percent);
    conf->errors = (bool)atoi(errors);
    conf->hover = (bool)atoi(hover);
    conf->timer = (bool)atoi(timer);
    conf->accuracy = (bool)atoi(accuracy_mode);
    conf->timer_h = atoi(timer_h);
    conf->timer_m = atoi(timer_m);
    conf->timer_s = atoi(timer_s);
    conf->accuracy_percent = atof(accuracy_percent);
}

void default_conf(Conf conf) {
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
        copy_file("template.conf", default_conf);
    else
        fclose(conf_file);
    conf_game_load(conf);
}

void conf_load(Conf conf, char *path) {
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
            conf_game_load(conf);
        }
    } else
        default_conf(conf);
}
bool conf_save(Conf conf, char *path) {
    char buf[256];
    if (sprintf(buf, "%d", conf->music_volume) < 0)
        return false;
    if (!set_setting("general.conf", "music_volume", buf))
        return false;
    if (sprintf(buf, "%d", conf->sound_volume) < 0)
        return false;
    if (!set_setting("general.conf", "sound_volume", buf))
        return false;
    if (sprintf(buf, "%d", conf->general_volume) < 0)
        return false;
    if (!set_setting("general.conf", "general_volume", buf))
        return false;
    if (sprintf(buf, "%d", conf->mouse_hover) < 0)
        return false;
    if (!set_setting("general.conf", "mouse_hover", buf))
        return false;
    if (sprintf(buf, "%d", conf->mouse_click) < 0)
        return false;
    if (!set_setting("general.conf", "mouse_click", buf))
        return false;
    if (sprintf(buf, "%d", conf->game_music) < 0)
        return (false);
    if (!set_setting("general.conf", "game_music", buf))
        return (false);
    if (sprintf(buf, "%d", conf->game_effects) < 0)
        return (false);
    if (!set_setting("general.conf", "game_effects", buf))
        return (false);
}