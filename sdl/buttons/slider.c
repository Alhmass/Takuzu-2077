#include "slider.h"

#include <assert.h>
#include <stdio.h>

#include "button.h"
#include "text.h"

Slider slider_create(SDL_Rect hitbox, int value, int min, int max, Assets assets, SDL_Renderer *ren) {
    Slider button = malloc(sizeof(struct Slider_s));
    assert(button);

    button->hitbox = hitbox;
    button->scaled = hitbox;

    // TODO: Make this more accurate
    button->hitbox = (SDL_Rect){hitbox.x + 10, hitbox.y + 10, hitbox.w - 20, hitbox.h - 20};
    button->scaled = button->hitbox;

    // TODO: Make this more accurate
    button->cursor_hitbox = (SDL_Rect){hitbox.x + hitbox.w / 2 - 20, hitbox.y + 5, 30, hitbox.h - 10};
    button->cursor_scaled = button->cursor_hitbox;

    // TODO: Make this more accurate
    button->label_hitbox = (SDL_Rect){hitbox.x + hitbox.w / 2 - 10, hitbox.y + 10, 20, hitbox.h - 20};
    button->label_scaled = button->label_hitbox;
    char label[5];
    sprintf(label, "%d", value);
    button->label = text_create(assets, label, RAJDHANI, LIGHT_BLUE, ren);

    button->value = value;
    button->min = min;
    button->max = max;

    button->dragged = false;
    button->hovered = false;

    return button;
}

void slider_delete(Slider button) {
    text_delete(button->label);
    free(button);
}

void slider_render(Slider button, Assets assets, SDL_Renderer *ren, SDL_Rect win_rect) {
    button->scaled = scale_rect(button->hitbox, win_rect);
    button->cursor_scaled = scale_rect(button->cursor_hitbox, win_rect);

    // center the label into the cursor
    button->label_scaled = scale_rect(button->label_hitbox, win_rect);
    button->label_scaled.x = button->cursor_scaled.x + button->cursor_scaled.w / 2 - button->label_scaled.w / 2;
    button->label_scaled.y = button->cursor_scaled.y + button->cursor_scaled.h / 2 - button->label_scaled.h / 2;

    SDL_RenderCopy(ren, BT(assets, SLIDER, SLIDER_BACKGROUND), NULL, &button->scaled);
    SDL_RenderCopy(ren, BT(assets, SLIDER, SLIDER_CURSOR), NULL, &button->cursor_scaled);
    text_render(button->label, ren, button->label_scaled);
}

bool slider_dragged(Slider button, Input input, SDL_Renderer *ren, SDL_Rect win_rect) {
    button->scaled = scale_rect(button->hitbox, win_rect);

    // TODO: Make this more accurate
    if (is_dragged(button->cursor_scaled, input)) {
        button->cursor_scaled.x = input->mouse_pos.x - button->cursor_scaled.w / 2;
        if (button->cursor_scaled.x < button->scaled.x + (button->cursor_scaled.w / 2 + 10)) {
            button->cursor_scaled.x = button->scaled.x + (button->cursor_scaled.w / 2 + 10);
        } else if (button->cursor_scaled.x > button->scaled.x + button->scaled.w - (button->cursor_scaled.w / 2 + 10)) {
            button->cursor_scaled.x = button->scaled.x + button->scaled.w - (button->cursor_scaled.w / 2 + 10);
        }

        button->value = (button->cursor_scaled.x - button->scaled.x) / (button->scaled.w - button->cursor_scaled.w);
        button->value *= (button->max - button->min);
        button->value += button->min;

        char label[5];
        sprintf(label, "%d", button->value);
        text_set_text(button->label, label, ren);
        button->dragged = true;
        return true;
    }
    button->dragged = false;
    return false;
}

bool slider_hovered(Slider button, Input input, SDL_Rect win_rect, Assets assets) {
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