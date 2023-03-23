#include "button_create.h"

// Default constructor takes label as param                  v
// Button default_create(SDL_Renderer *ren, SDL_Rect hitbox, Text label, bool transparent)
Button default_create(SDL_Renderer *ren, SDL_Rect hitbox, bool transparent) {
    Button button = malloc(sizeof(struct Button_s));
    assert(button);

    // Button Assets
    button->texture = malloc(sizeof(SDL_Texture *) * 2);
    assert(button->texture);
    if (transparent == false) {
        button->type = DEFAULT;
        button->texture[0] = IMG_LoadTexture(ren, DEFAULT_TEXTURE);
        button->texture[1] = IMG_LoadTexture(ren, DEFAULT_HOVER);
    } else {
        button->type = TRANSPARENT;
        button->texture[0] = IMG_LoadTexture(ren, TRANSPARENT_TEXTURE);
        button->texture[1] = IMG_LoadTexture(ren, TRANSPARENT_HOVER);
    }
    button->nb_textures = 2;

    button->active_texture = malloc(sizeof(bool) * 2);
    assert(button->active_texture);
    button->active_texture[0] = true;
    button->active_texture[1] = false;

    // button->mixer = sound_create(...);
    button->nb_mixers = 0;

    // button->label = text_create(...);
    button->active_label = 0;
    button->nb_labels = 0;

    // Button Properties
    button->hitbox = hitbox;
    button->scaled_hitbox = hitbox;
    button->hovered = false;
    button->error = false;  // No error for default button

    // No value for default button
    button->value = 0;
    button->min = 0;
    button->max = 0;

    return button;
}

Button switch_create(SDL_Renderer *ren, SDL_Rect hitbox, bool default_state) {
    Button button = malloc(sizeof(struct Button_s));
    assert(button);

    // Button Assets
    button->texture = malloc(sizeof(SDL_Texture *) * 2);
    assert(button->texture);
    button->type = SWITCH;
    button->texture[0] = IMG_LoadTexture(ren, SWITCH_OFF);
    button->texture[1] = IMG_LoadTexture(ren, SWITCH_ON);
    button->nb_textures = 2;

    button->active_texture = malloc(sizeof(bool) * 2);
    assert(button->active_texture);
    button->active_texture[0] = !default_state;
    button->active_texture[1] = default_state;

    // button->mixer = sound_create(...);
    button->nb_mixers = 0;

    // button->label = text_create(...);
    button->nb_labels = 0;
    button->active_label = 0;

    // Button Properties
    button->hitbox = hitbox;
    button->scaled_hitbox = hitbox;
    button->hovered = false;  // No hover for switch button
    button->error = false;    // No error for choice button

    button->value = default_state;
    button->min = 0;
    button->max = 1;

    return button;
}

Button slider_create(SDL_Renderer *ren, SDL_Rect hitbox, int min, int max, int default_value) {
    Button button = malloc(sizeof(struct Button_s));
    assert(button);

    // Button Assets
    button->texture = malloc(sizeof(SDL_Texture *) * 4);
    assert(button->texture);
    button->type = SLIDER;
    button->texture[0] = IMG_LoadTexture(ren, BACKGROUND_TEXTURE);
    button->texture[1] = IMG_LoadTexture(ren, LEFT_TEXTURE);
    button->texture[2] = IMG_LoadTexture(ren, RIGHT_TEXTURE);
    button->texture[3] = IMG_LoadTexture(ren, SLIDER_CURSOR);
    button->nb_textures = 4;

    button->active_texture = malloc(sizeof(bool) * 4);
    assert(button->active_texture);
    button->active_texture[0] = true;
    button->active_texture[1] = true;
    button->active_texture[2] = true;
    button->active_texture[3] = true;

    // button->mixer = sound_create(...);
    button->nb_mixers = 0;

    // button->label = text_create(...);
    button->nb_labels = 0;
    button->active_label = 0;

    // Button Properties
    button->hitbox = hitbox;
    button->scaled_hitbox = hitbox;
    button->hovered = false;  // No hover for slider button
    button->error = false;    // No error for choice button

    button->value = default_value;
    button->min = min;
    button->max = max;

    return button;
}

Button choice_create(SDL_Renderer *ren, SDL_Rect hitbox, int nb_choice, char **choices) {
    Button button = malloc(sizeof(struct Button_s));
    assert(button);

    // Button Assets
    button->texture = malloc(sizeof(SDL_Texture *) * 3);
    assert(button->texture);
    button->type = CHOICE;
    button->texture[0] = IMG_LoadTexture(ren, BACKGROUND_TEXTURE);
    button->texture[1] = IMG_LoadTexture(ren, LEFT_TEXTURE);
    button->texture[2] = IMG_LoadTexture(ren, RIGHT_TEXTURE);
    button->nb_textures = 3;

    button->active_texture = malloc(sizeof(bool) * 3);
    assert(button->active_texture);
    button->active_texture[0] = true;
    button->active_texture[1] = true;
    button->active_texture[2] = true;

    // button->mixer = sound_create(...);
    button->nb_mixers = 0;

    // button->label = text_create(...);
    button->nb_labels = 0;
    button->active_label = 0;
    (void)choices;

    // Button Properties
    button->hitbox = hitbox;
    button->scaled_hitbox = hitbox;
    button->hovered = false;  // No hover for choice button
    button->error = false;    // No error for choice button

    button->value = 0;
    button->min = 0;
    button->max = nb_choice - 1;

    return button;
}

Button cell_create(SDL_Renderer *ren, SDL_Rect hitbox, int value) {
    Button button = malloc(sizeof(struct Button_s));
    assert(button);

    // Button Assets
    button->texture = malloc(sizeof(SDL_Texture *) * 5);
    assert(button->texture);
    button->type = CELL;
    button->texture[0] = IMG_LoadTexture(ren, BLACK);
    button->texture[1] = IMG_LoadTexture(ren, WHITE);
    button->texture[2] = IMG_LoadTexture(ren, EMPTY);
    button->texture[3] = IMG_LoadTexture(ren, ERROR_HOVER);
    button->texture[4] = IMG_LoadTexture(ren, HOVER);
    button->nb_textures = 5;

    button->active_texture = malloc(sizeof(bool) * 5);
    assert(button->active_texture);
    button->active_texture[0] = false;
    button->active_texture[1] = false;
    button->active_texture[2] = true;
    button->active_texture[3] = false;
    button->active_texture[4] = false;

    // button->mixer = sound_create(...);
    button->nb_mixers = 0;

    // button->label = text_create(...);
    button->nb_labels = 0;
    button->active_label = 0;

    // Button Properties
    button->hitbox = hitbox;
    button->scaled_hitbox = hitbox;
    button->hovered = false;
    button->error = false;

    button->value = value;
    button->min = -1;
    button->max = 1;

    return button;
}
