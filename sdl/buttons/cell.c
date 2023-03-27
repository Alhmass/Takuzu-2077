#include "cell.h"

#include <SDL_mixer.h>
#include <assert.h>

#include "button.h"

Cell cell_create(SDL_Rect hitbox, int type) {
    Cell button = malloc(sizeof(struct Cell_s));
    assert(button);

    button->hitbox = hitbox;
    button->scaled = hitbox;

    button->type = type;
    button->has_error = false;

    button->hovered = false;
    button->pressed = false;

    return button;
}

void cell_delete(Cell button) { free(button); }

void cell_render(Cell button, Assets assets, SDL_Renderer *ren, SDL_Rect win_rect) {
    button->scaled = scale_rect(button->hitbox, win_rect);
    SDL_RenderCopy(ren, BT(assets, CELL, button->type), NULL, &button->scaled);

    if (button->has_error)
        SDL_RenderCopy(ren, BT(assets, CELL, CELL_ERROR), NULL, &button->scaled);

    if (button->hovered)
        SDL_RenderCopy(ren, BT(assets, CELL, CELL_HOVER), NULL, &button->scaled);
}

bool cell_pressed(Cell button, Input input, SDL_Rect win_rect, Assets assets) {
    button->scaled = scale_rect(button->hitbox, win_rect);

    if (is_clicked(button->scaled, input)) {
        if (button->pressed == false) {
            // play cell sound
            (void)assets;
            if (button->type == CELL_TYPE_EMPTY)
                button->type = CELL_TYPE_BLUE;
            else if (button->type == CELL_TYPE_BLUE)
                button->type = CELL_TYPE_RED;
            else if (button->type == CELL_TYPE_RED)
                button->type = CELL_TYPE_EMPTY;
        }
        button->pressed = true;
        return true;
    }
    button->pressed = false;
    return false;
}

bool cell_hovered(Cell button, Input input, SDL_Rect win_rect, Assets assets) {
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