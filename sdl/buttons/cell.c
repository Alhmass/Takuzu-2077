#include "cell.h"

#include <SDL_mixer.h>
#include <assert.h>

#include "button.h"
#include "input.h"

Cell cell_create(SDL_Rect hitbox, int type) {
    Cell button = malloc(sizeof(struct Cell_s));
    assert(button);

    button->hitbox = hitbox;
    button->scaled = hitbox;

    button->type = type;
    button->has_error = false;
    button->selected = false;
    button->hovered = false;

    return button;
}

void cell_delete(Cell button) { free(button); }

void cell_render(Cell button, Assets assets, SDL_Renderer *ren, SDL_Rect win_rect, Input input) {
    (void)input;
    button->scaled = scale_rect(button->hitbox, win_rect);
    SDL_RenderCopy(ren, BT(assets, CELL, button->type), NULL, &button->scaled);

    if (button->has_error)
        SDL_RenderCopy(ren, BT(assets, CELL, CELL_ERROR), NULL, &button->scaled);

    if (button->hovered || button->selected)
        SDL_RenderCopy(ren, BT(assets, CELL, CELL_HOVER), NULL, &button->scaled);
}

bool cell_pressed(Cell button, Input input, SDL_Rect win_rect, Assets assets) {
    button->scaled = scale_rect(button->hitbox, win_rect);

    if (left_click(button->scaled, input)) {
        // play cell sound
        (void)assets;
        if (button->type == CELL_EMPTY)
            button->type = CELL_BLUE;
        else if (button->type == CELL_BLUE)
            button->type = CELL_RED;
        else if (button->type == CELL_RED)
            button->type = CELL_EMPTY;
        return true;
    } else if (right_click(button->scaled, input)) {
        // play cell sound
        (void)assets;
        if (button->type == CELL_EMPTY)
            button->type = CELL_RED;
        else if (button->type == CELL_RED)
            button->type = CELL_BLUE;
        else if (button->type == CELL_BLUE)
            button->type = CELL_EMPTY;
        return true;
    }
    return false;
}

bool cell_hovered(Cell button, Input input, SDL_Rect win_rect, Assets assets) {
    button->scaled = scale_rect(button->hitbox, win_rect);

    if (is_hovered(button->scaled, input)) {
        if (button->hovered == false) {
            // Mix_PlayChannel(-1, assets->sounds[HOVER_SOUND], 0);
            (void)assets;
        }
        button->selected = true;
        button->hovered = true;
        return true;
    }
    button->selected = false;
    button->hovered = false;
    return false;
}