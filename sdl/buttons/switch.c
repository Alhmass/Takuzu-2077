#include "switch.h"

#include <assert.h>

#include "button.h"

Switch switch_create(SDL_Rect hitbox, bool default_state) {
    Switch button = malloc(sizeof(struct Switch_s));
    assert(button);

    button->render_hitbox = hitbox;
    button->scaled_hitbox = hitbox;

    // TODO: Make this pixel perfect
    button->hitbox = (SDL_Rect){hitbox.x + 10, hitbox.y + 10, hitbox.w - 20, hitbox.h - 20};
    button->scaled = button->hitbox;

    button->state = default_state;
    button->hovered = false;

    return button;
}

void switch_delete(Switch button) { free(button); }

void switch_render(Switch button, Assets a, SDL_Renderer *ren, SDL_Rect win_rect) {
    button->scaled_hitbox = scale_rect(button->render_hitbox, win_rect);
    if (button->state) {
        SDL_RenderCopy(ren, BT(a, SWITCH, SWITCH_ON), NULL, &button->scaled_hitbox);
    } else {
        SDL_RenderCopy(ren, BT(a, SWITCH, SWITCH_OFF), NULL, &button->scaled_hitbox);
    }
}

bool switch_pressed(Switch button, Input input, SDL_Rect win_rect, Assets assets) {
    button->scaled = scale_rect(button->hitbox, win_rect);

    if (left_click(button->scaled, input)) {
        if (button->state == false) {
            // play affirmative sound
            (void)assets;
            button->state = true;
        } else if (button->state == true) {
            // play negative sound
            (void)assets;
            button->state = false;
        }
        return true;
    }
    return false;
}

bool switch_hovered(Switch button, Input input, SDL_Rect win_rect, Assets assets) {
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