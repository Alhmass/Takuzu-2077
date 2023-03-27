#include "default.h"

#include <SDL_mixer.h>
#include <assert.h>

#include "button.h"

Default default_create(SDL_Rect hitbox, char *label, int type, Assets assets, SDL_Renderer *ren) {
    Default button = malloc(sizeof(struct Default_s));
    assert(button);

    button->type = type;

    if (type == DEF_TYPE_BLUE || type == DEF_TYPE_RED) {
        button->label = text_create(assets, label, RAJDHANI, BLACK, ren);
    } else if (type == DEF_TYPE_BLUE_T) {
        button->label = text_create(assets, label, OXTA, LIGHT_BLUE, ren);
    } else if (type == DEF_TYPE_RED_T) {
        button->label = text_create(assets, label, RAJDHANI, LIGHT_RED, ren);
    } else {
        button->label = text_create(assets, label, RAJDHANI, BLACK, ren);
    }

    button->hitbox = hitbox;
    button->scaled = hitbox;

    // height : center the label using hitbox %
    // width : center and keep mono-spaced font using hitbox %
    // fit the label into the button
    button->label_hitbox =
        (SDL_Rect){hitbox.x + hitbox.w * 0.1, hitbox.y + hitbox.h * 0.2, hitbox.w * 0.8, hitbox.h * 0.8};
    button->label_scaled = button->label_hitbox;

    button->hovered = false;
    button->pressed = false;

    return button;
}

void default_delete(Default button) {
    text_delete(button->label);
    free(button);
}

void default_render(Default button, Assets assets, SDL_Renderer *ren, SDL_Rect win_rect) {
    button->scaled = scale_rect(button->hitbox, win_rect);

    // center the label into the button
    button->label_scaled = scale_rect(button->label_hitbox, win_rect);
    button->label_scaled.x = button->scaled.x + button->scaled.w / 2 - button->label_scaled.w / 2;
    button->label_scaled.y = button->scaled.y + button->scaled.h / 2 - button->label_scaled.h / 2;

    SDL_RenderCopy(ren, BT(assets, DEFAULT, button->type), NULL, &button->scaled);
    text_render(button->label, ren, button->label_scaled);
}

bool default_pressed(Default button, Input input, SDL_Rect win_rect, Assets assets) {
    button->scaled = scale_rect(button->hitbox, win_rect);

    if (is_clicked(button->scaled, input)) {
        if (button->pressed == false) {
            // play press sound
            (void)assets;
        }
        button->pressed = true;
        return true;
    }
    button->pressed = false;
    return false;
}

bool default_hovered(Default button, Input input, SDL_Rect win_rect, Assets assets) {
    button->scaled = scale_rect(button->hitbox, win_rect);
    if (is_hovered(button->scaled, input)) {
        if (button->hovered == false) {
            // play hover sound
            (void)assets;
        }
        button->hovered = true;
        return true;
    }
    button->hovered = false;
    return false;
}
