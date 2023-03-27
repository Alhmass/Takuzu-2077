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

    scene->default_b = malloc(sizeof(Default) * nb_default);
    scene->switch_b = malloc(sizeof(Switch) * nb_switch);
    scene->toggle_b = malloc(sizeof(Toggle) * nb_toggle);
    scene->choice_b = malloc(sizeof(Choice) * nb_choice);
    scene->slider_b = malloc(sizeof(Slider) * nb_slider);
    scene->cell_btn = malloc(sizeof(Cell) * nb_cell);

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
        else
            SDL_RenderCopy(ren, assets->sprite_texture[SETTINGS_BG], NULL, NULL);
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
        cell_render(scene->cell_btn[i], assets, ren, win_rect);
    }

    for (int i = 0; i < scene->nb_texts; i++) {
        text_render(scene->text[i], ren, win_rect);
    }
}

void scene_delete(Scene scene, SDL_Renderer *ren) {
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
        cell_delete(scene->cell_btn[i]);
    }
    free(scene->cell_btn);

    for (int i = 0; i < scene->nb_texts; i++) {
        text_delete(scene->text[i]);
    }
    free(scene->text);

    free(scene);
}