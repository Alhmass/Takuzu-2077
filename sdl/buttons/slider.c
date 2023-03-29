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

    button->cursor_hitbox.x = 0;
    button->cursor_hitbox.y = hitbox.y + (1.5 * hitbox.y / 100);
    button->cursor_hitbox.w = 17 * hitbox.w / 100;
    button->cursor_hitbox.h = 83 * hitbox.h / 100;

    button->cursor_scaled = button->cursor_hitbox;

    // TODO: Make this more accurate
    SDL_Rect label_hitbox;
    label_hitbox.x = button->cursor_hitbox.x + (30 * button->cursor_hitbox.x / 100);
    label_hitbox.y = button->cursor_hitbox.y + (1.5 * button->cursor_hitbox.y / 100);
    label_hitbox.w = 40 * button->cursor_hitbox.w / 100;
    label_hitbox.h = button->cursor_hitbox.h;

    char label[5];
    sprintf(label, "%d", value);
    button->label = text_create(assets, label, RAJDHANI, LIGHT_BLUE, label_hitbox, ren);

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

    // move the cursor to the correct position given the value
    button->cursor_hitbox.x = button->value *
                                  ((button->hitbox.w + 5 * button->cursor_hitbox.w / 100) -
                                   (button->cursor_hitbox.w + 8 * button->cursor_hitbox.w / 100)) /
                                  100 +
                              button->hitbox.x;
    button->cursor_scaled = scale_rect(button->cursor_hitbox, win_rect);

    // center the label into the cursor
    button->label->scaled = scale_rect(button->label->hitbox, win_rect);
    button->label->scaled.x = button->cursor_scaled.x + button->cursor_scaled.w / 2 - button->label->scaled.w / 2;
    button->label->scaled.y = button->cursor_scaled.y + button->cursor_scaled.h / 2 - button->label->scaled.h / 2;

    SDL_RenderCopy(ren, BT(assets, SLIDER, SLIDER_BACKGROUND), NULL, &button->scaled);
    SDL_RenderCopy(ren, BT(assets, SLIDER, SLIDER_CURSOR), NULL, &button->cursor_scaled);
    text_render(button->label, ren);
}

bool slider_dragged(Slider button, Input input, Assets assets, SDL_Renderer *ren, SDL_Rect win_rect) {
    button->cursor_scaled = scale_rect(button->cursor_hitbox, win_rect);

    if (button->dragged == false && left_click(button->cursor_scaled, input)) {
        button->dragged = true;
        return true;
    } else if (button->dragged == true && left_drag((SDL_Rect){0, 0, win_rect.w, win_rect.h}, input)) {
        button->cursor_scaled.x = input->mouse_pos.x - button->cursor_scaled.w / 2;

        if (button->cursor_scaled.x < button->scaled.x + 2 * button->cursor_scaled.w / 100) {
            button->cursor_scaled.x = button->scaled.x - 2 * button->cursor_scaled.w / 100;
        }

        if (button->cursor_scaled.x > (button->scaled.x + button->scaled.w) - button->cursor_scaled.w) {
            button->cursor_scaled.x = (button->scaled.x + button->scaled.w) - button->cursor_scaled.w;
        }

        button->value =
            (button->cursor_scaled.x - button->scaled.x) * 100 / (button->scaled.w - button->cursor_scaled.w);

        char label[5];
        sprintf(label, "%d", button->value);
        button->label = text_set_text(button->label, label, assets, ren);
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