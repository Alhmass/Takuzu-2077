#include "scene.h"

#include "assets.h"
#include "button.h"

void scene_init(Scene scene, int nb_default, int nb_switch, int nb_toggle, int nb_choice, int nb_slider, int nb_cell,
                int nb_texts) {
    scene->nb_default = nb_default;
    scene->nb_switch = nb_switch;
    scene->nb_toggle = nb_toggle;
    scene->nb_choice = nb_choice;
    scene->nb_slider = nb_slider;
    scene->nb_cell = nb_cell;

    scene->default_b = malloc(sizeof(struct Default_s) * nb_default);
    scene->switch_b = malloc(sizeof(struct Switch_s) * nb_switch);
    scene->toggle_b = malloc(sizeof(struct Toggle_s) * nb_toggle);
    scene->choice_b = malloc(sizeof(struct Choice_s) * nb_choice);
    scene->slider_b = malloc(sizeof(struct Slider_s) * nb_slider);
    scene->cell_b = malloc(sizeof(struct Cell_s) * nb_cell);

    scene->nb_texts = nb_texts;
    scene->text = malloc(sizeof(struct Text_s) * nb_texts);

    scene->is_active = false;
}

void scene_render(Scene scene, int type, Assets assets, SDL_Renderer *ren, SDL_Rect win_rect) {
    if (scene->is_active == false)
        return;

    if (scene->is_active == true) {
        if (type == MAIN)
            SDL_RenderCopy(ren, assets->sprite_texture[MAIN_BG], NULL, NULL);
        else if (type == GAME || type == CREATE || type == EDITOR || type == CUSTOM || type == SAVED)
            SDL_RenderCopy(ren, assets->sprite_texture[GAME_BG], NULL, NULL);
        else if (type == SOUNDS) {
            SDL_RenderCopy(ren, assets->sprite_texture[SOUNDS_BG], NULL, NULL);
        } else if (type == GRAPHICS) {
            SDL_RenderCopy(ren, assets->sprite_texture[GRAPHICS_BG], NULL, NULL);
        } else if (type == CONTROLS) {
            SDL_RenderCopy(ren, assets->sprite_texture[CONTROLS_BG], NULL, NULL);
        } else if (type == STATS) {
            SDL_RenderCopy(ren, assets->sprite_texture[STATS_BG], NULL, NULL);
        } else {
            SDL_RenderCopy(ren, assets->sprite_texture[SETTINGS_BG], NULL, NULL);
        }
    }

    for (int i = 0; i < scene->nb_default; i++) {
        default_render(scene->default_b[i], assets, ren, win_rect);
    }

    for (int i = 0; i < scene->nb_switch; i++) {
        switch_render(scene->switch_b[i], assets, ren, win_rect);
    }

    for (int i = 0; i < scene->nb_toggle; i++) {
        toggle_render(scene->toggle_b[i], assets, ren, win_rect);
    }

    for (int i = 0; i < scene->nb_choice; i++) {
        choice_render(scene->choice_b[i], assets, ren, win_rect);
    }

    for (int i = 0; i < scene->nb_slider; i++) {
        slider_render(scene->slider_b[i], assets, ren, win_rect);
    }

    for (int i = 0; i < scene->nb_cell; i++) {
        cell_render(scene->cell_b[i], assets, ren, win_rect);
    }

    for (int i = 0; i < scene->nb_texts; i++) {
        text_render_scaled(scene->text[i], ren, win_rect);
    }
}

void scene_delete(Scene scene) {
    for (int i = 0; i < scene->nb_default; i++) {
        default_delete(scene->default_b[i]);
    }
    free(scene->default_b);

    for (int i = 0; i < scene->nb_switch; i++) {
        switch_delete(scene->switch_b[i]);
    }
    free(scene->switch_b);

    for (int i = 0; i < scene->nb_toggle; i++) {
        toggle_delete(scene->toggle_b[i]);
    }
    free(scene->toggle_b);

    for (int i = 0; i < scene->nb_choice; i++) {
        choice_delete(scene->choice_b[i]);
    }
    free(scene->choice_b);

    for (int i = 0; i < scene->nb_slider; i++) {
        slider_delete(scene->slider_b[i]);
    }
    free(scene->slider_b);

    for (int i = 0; i < scene->nb_cell; i++) {
        cell_delete(scene->cell_b[i]);
    }
    free(scene->cell_b);

    for (int i = 0; i < scene->nb_texts; i++) {
        text_delete(scene->text[i]);
    }
    free(scene->text);

    free(scene);
}