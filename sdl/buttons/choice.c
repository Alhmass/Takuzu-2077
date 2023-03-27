#include "choice.h"

#include <assert.h>

#include "button.h"
#include "text.h"

Choice choice_create(SDL_Rect hitbox, char **choices, int nb_choice, int default_choice, Assets assets,
                     SDL_Renderer *ren) {
    Choice button = malloc(sizeof(struct Choice_s));
    assert(button);

    button->hitbox = hitbox;
    button->scaled = hitbox;

    // TODO: make this more accurate
    button->hitbox_prev = (SDL_Rect){hitbox.x + 20, hitbox.y + 5, hitbox.w * 10 / 100, hitbox.h - 10};
    button->scaled_prev = button->hitbox_prev;

    // TODO: make this more accurate
    button->hitbox_next =
        (SDL_Rect){hitbox.x + hitbox.w - 20 - hitbox.w * 10 / 100, hitbox.y + 5, hitbox.w * 10 / 100, hitbox.h - 10};
    button->scaled_next = button->hitbox_next;

    // TODO: make this more accurate
    button->label_hitbox =
        (SDL_Rect){hitbox.x + hitbox.w * 10 / 100 + 20, hitbox.y, hitbox.w * 80 / 100 - 40, hitbox.h};
    button->label_scaled = button->label_hitbox;

    button->choices = malloc(sizeof(struct Text_s) * nb_choice);
    for (int i = 0; i < nb_choice; i++) {
        button->choices[i] = text_create(assets, choices[i], RAJDHANI, LIGHT_BLUE, ren);
    }

    button->current_choice = default_choice;
    button->nb_choice = nb_choice;

    button->pressed = false;
    button->hovered = false;

    return button;
}

void choice_delete(Choice button) {
    for (int i = 0; i < button->nb_choice; i++) {
        text_delete(button->choices[i]);
    }
    free(button->choices);
    free(button);
}

void choice_render(Choice button, Assets assets, SDL_Renderer *ren, SDL_Rect win_rect) {
    button->scaled = scale_rect(button->hitbox, win_rect);

    // Center the text in the button
    button->label_scaled = scale_rect(button->label_hitbox, win_rect);
    button->label_scaled.x += button->scaled.w / 2 - button->label_scaled.w / 2;
    button->label_scaled.y += button->scaled.h / 2 - button->label_scaled.h / 2;

    SDL_RenderCopy(ren, BT(assets, CHOICE, CHOICE_BACKGROUND), NULL, &button->scaled_prev);
    text_render(button->choices[button->current_choice], ren, button->label_scaled);
}

int choice_pressed(Choice button, Input input, SDL_Rect win_rect, Assets assets) {
    button->scaled = scale_rect(button->hitbox, win_rect);
    button->scaled_prev = scale_rect(button->hitbox_prev, win_rect);
    button->scaled_next = scale_rect(button->hitbox_next, win_rect);

    if (is_clicked(button->scaled_prev, input)) {
        if (button->pressed == false) {
            if (button->current_choice == 0) {
                button->current_choice = button->nb_choice - 1;
            } else {
                button->current_choice--;
            }
            // play decrement sound
            (void)assets;
        }
        button->pressed = true;
    } else if (is_clicked(button->scaled_next, input)) {
        if (button->pressed == false) {
            if (button->current_choice == button->nb_choice - 1) {
                button->current_choice = 0;
            } else {
                button->current_choice++;
            }
            // play increment sound
            (void)assets;
        }
        button->pressed = true;
    }
    button->pressed = false;
    return button->current_choice;
}

bool choice_hovered(Choice button, Input input, SDL_Rect win_rect, Assets assets) {
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