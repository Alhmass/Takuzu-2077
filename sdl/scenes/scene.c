#include "scene.h"

void scene_render(Scene scene, SDL_Renderer *ren, SDL_Rect win_rect) {
    if (scene->is_active == false)
        return;

    for (int i = 0; i < scene->nb_textures; i++) {
        SDL_RenderCopy(ren, scene->texture[i], NULL, NULL);
    }

    for (int i = 0; i < scene->nb_buttons; i++) {
        button_render(scene->button[i], ren, win_rect);
    }

    // for (int i = 0; i < scene->nb_text; i++) {
    //     text_render(scene->text[i], ren);
    // }
}

void scene_delete(Scene scene, SDL_Renderer *ren) {
    for (int i = 0; i < scene->nb_textures; i++) {
        SDL_DestroyTexture(scene->texture[i]);
    }
    free(scene->texture);

    for (int i = 0; i < scene->nb_buttons; i++) {
        button_delete(scene->button[i]);
    }
    free(scene->button);

    // for (int i = 0; i < scene->nb_text; i++) {
    //     text_delete(scene->text[i]);
    // }
    // free(scene->text);

    free(scene);
}