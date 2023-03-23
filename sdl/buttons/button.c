#include "button.h"

SDL_Rect scale_rect(SDL_Rect rect, SDL_Rect win_rect) {
    SDL_Rect scaled_rect;
    scaled_rect.x = rect.x * win_rect.w / 1920;
    scaled_rect.y = rect.y * win_rect.h / 1080;
    scaled_rect.w = rect.w * win_rect.w / 1920;
    scaled_rect.h = rect.h * win_rect.h / 1080;
    return scaled_rect;
}

void button_render(Button button, SDL_Renderer *ren, SDL_Rect win_rect) {
    for (int i = 0; i < button->nb_textures; i++) {
        if (button->active_texture[i] == true) {
            button->scaled_hitbox = scale_rect(button->hitbox, win_rect);
            SDL_RenderCopy(ren, button->texture[i], NULL, &button->scaled_hitbox);
        }
    }

    // for (int i = 0; i < button->nb_labels; i++) {
    //     text_render(button->label[i], ren);
    // }
}

void button_delete(Button button) {
    for (int i = 0; i < button->nb_textures; i++) SDL_DestroyTexture(button->texture[i]);
    free(button->texture);

    // for (int i = 0; i < button->nb_labels; i++) text_delete(button->label[i]);
    // free(button->label);

    // for (int i = 0; i < button->nb_mixers; i++) mixer_delete(button->mixer[i]);
    // free(button->mixer);

    free(button);
}

bool button_down(Button button, Input input) {
    return (input->mouse_action == LEFT_CLICK && SDL_PointInRect(&input->mouse_pos, &button->scaled_hitbox));
}

bool button_hovered(Button button, Input input) {
    return (input->mouse_action == NO_ACTION && SDL_PointInRect(&input->mouse_pos, &button->scaled_hitbox));
}

bool button_up(Button button, Input input) {
    return (input->mouse_action == LEFT_DRAG && SDL_PointInRect(&input->mouse_pos, &button->scaled_hitbox));
}
