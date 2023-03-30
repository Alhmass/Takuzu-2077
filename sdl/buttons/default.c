#include "default.h"

#include <SDL_mixer.h>
#include <assert.h>
#include <string.h>

#include "button.h"

Default default_create(SDL_Rect hitbox, char *label, int type, Assets assets, SDL_Renderer *ren) {
    Default button = malloc(sizeof(struct Default_s));
    assert(button);

    button->type = type;

    // TODO make this more accurate
    SDL_Rect label_hitbox = {
        hitbox.x + hitbox.w * 0.05,
        hitbox.y + hitbox.h * 0.15,
        hitbox.w * 0.05 * strlen(label),
        hitbox.h * 0.8,
    };

    if (type == DEFAULT_BLUE || type == DEFAULT_RED) {
        button->label = text_create(assets, label, RAJDHANI, BLACK, label_hitbox, ren);
    } else if (type == DEFAULT_BLUE_T || type == DEFAULT_BLUE_DARK) {
        button->label = text_create(assets, label, RAJDHANI, LIGHT_BLUE, label_hitbox, ren);
    } else if (type == DEFAULT_RED_T) {
        button->label = text_create(assets, label, RAJDHANI, LIGHT_RED, label_hitbox, ren);
    } else {
        button->label = text_create(assets, label, RAJDHANI, BLACK, label_hitbox, ren);
    }

    button->hitbox = hitbox;
    button->scaled = hitbox;

    button->hovered = false;
    return button;
}

void default_delete(Default button) {
    text_delete(button->label);
    free(button);
}

void default_render(Default button, Assets assets, SDL_Renderer *ren, SDL_Rect win_rect, Input input) {
    button->scaled = scale_rect(button->hitbox, win_rect);

    // center the label into the button
    // button->label->scaled = scale_rect(button->label->hitbox, win_rect);
    // button->label->scaled.x = button->scaled.x + button->scaled.w / 2 - button->label->scaled.w / 2;
    // button->label->scaled.y = button->scaled.y + button->scaled.h / 2 - button->label->scaled.h / 2;

    SDL_RenderCopy(ren, BT(assets, DEFAULT, button->type), NULL, &button->scaled);

    default_hovered(button, input, win_rect, assets);
    if (button->hovered)
        SDL_RenderCopy(ren, BT(assets, DEFAULT, DEFAULT_BLUE_HOVER), NULL, &button->scaled);

    text_render_scaled(button->label, ren, win_rect);
}

bool default_pressed(Default button, Input input, SDL_Rect win_rect, Assets assets) {
    button->scaled = scale_rect(button->hitbox, win_rect);

    if (left_click(button->scaled, input)) {
        Mix_PlayChannel(-1, SOUND(assets, SOUND_CLICK), 0);
        return true;
    }
    return false;
}

bool default_hovered(Default button, Input input, SDL_Rect win_rect, Assets assets) {
    button->scaled = scale_rect(button->hitbox, win_rect);

    if (is_hovered(button->scaled, input)) {
        if (button->hovered == false) {
            Mix_PlayChannel(-1, SOUND(assets, SOUND_HOVER), 0);
        }
        button->hovered = true;
        return true;
    }
    button->hovered = false;
    return false;
}
