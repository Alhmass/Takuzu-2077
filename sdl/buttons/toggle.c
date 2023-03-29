#include "toggle.h"

#include <assert.h>

#include "button.h"

Toggle toggle_create(SDL_Rect hitbox, bool default_state) {
    Toggle button = malloc(sizeof(struct Toggle_s));
    assert(button);

    button->render_hitbox = hitbox;
    button->scaled_hitbox = hitbox;

    // TODO: Make this pixel perfect
    button->hitbox_off = (SDL_Rect){hitbox.x, hitbox.y, hitbox.w / 2, hitbox.h};
    button->scaled_off = button->hitbox_off;

    // TODO: Make this pixel perfect
    button->hitbox_on = (SDL_Rect){hitbox.x + hitbox.w / 2, hitbox.y, hitbox.w / 2, hitbox.h};
    button->scaled_on = button->hitbox_on;

    button->state = default_state;

    button->hovered = false;

    return button;
}

void toggle_delete(Toggle button) { free(button); }

void toggle_render(Toggle button, Assets assets, SDL_Renderer *ren, SDL_Rect win_rect) {
    button->scaled_hitbox = scale_rect(button->render_hitbox, win_rect);
    if (button->state) {
        SDL_RenderCopy(ren, BT(assets, TOGGLE, TOGGLE_ON), NULL, &button->scaled_hitbox);
    } else {
        SDL_RenderCopy(ren, BT(assets, TOGGLE, TOGGLE_OFF), NULL, &button->scaled_hitbox);
    }
}

bool toggle_pressed(Toggle button, Input input, SDL_Rect win_rect, Assets a) {
    button->scaled_off = scale_rect(button->hitbox_off, win_rect);
    button->scaled_on = scale_rect(button->hitbox_on, win_rect);

    if (left_click(button->scaled_off, input)) {
        if (button->state == true) {
            // play negative sound
            (void)a;
            button->state = false;
        } else {
            // play error sound
        }
        return true;
    } else if (left_click(button->scaled_on, input)) {
        if (button->state == false) {
            // play affirmative sound
            (void)a;
            button->state = true;
        } else {
            // play error sound
        }
        return true;
    }
    return false;
}

bool toggle_hovered(Toggle button, Input input, SDL_Rect win_rect, Assets assets) {
    button->scaled_hitbox = scale_rect(button->render_hitbox, win_rect);

    if (is_hovered(button->scaled_hitbox, input)) {
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
