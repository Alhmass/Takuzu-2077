#include "text.h"

#include <assert.h>
#include <stdlib.h>
#include <string.h>

Text text_create(Assets a, char *label, int font_type, int font_color, SDL_Renderer *ren) {
    Text text = malloc(sizeof(struct Text_s));
    assert(text);

    // copy label to text
    text->text = malloc(strlen(label) + 1);
    assert(text->text);
    strcpy(text->text, label);

    // set font type and color
    text->font_type = font_type;
    text->font = F(a, font_type);

    SDL_Color colors[NB_COLORS] = {
        [LIGHT_BLUE] = {0x90, 0xf5, 0xf9, 0xff}, [DARK_BLUE] = {0x00, 0xb8, 0xff, 0xff},
        [LIGHT_RED] = {0xff, 0x74, 0x6d, 0xff},  [DARK_RED] = {0xbf, 0x2f, 0x20, 0xff},
        [BLACK] = {0x06, 0x04, 0x0d, 0xff},      [WHITE] = {0xfc, 0xfe, 0xff, 0xff},
    };
    text->font_color = font_color;
    text->color = colors[font_color];

    text->surface = TTF_RenderText_Solid(text->font, text->text, text->color);
    text->texture = SDL_CreateTextureFromSurface(ren, text->surface);
    return text;
}

void text_delete(Text text) {
    free(text->text);
    SDL_FreeSurface(text->surface);
    SDL_DestroyTexture(text->texture);
    free(text);
}

void text_render(Text text, SDL_Renderer *ren, SDL_Rect rect) { SDL_RenderCopy(ren, text->texture, NULL, &rect); }

void text_set_text(Text text, char *new_text, SDL_Renderer *ren) {
    free(text->text);
    text->text = malloc(strlen(new_text) + 1);
    assert(text->text);
    strcpy(text->text, new_text);

    SDL_FreeSurface(text->surface);
    text->surface = TTF_RenderText_Solid(text->font, text->text, text->color);
    SDL_DestroyTexture(text->texture);
    text->texture = SDL_CreateTextureFromSurface(ren, text->surface);
}

void text_set_color(Text text, enum font_color new_color, SDL_Renderer *ren) {
    text->font_color = new_color;
    SDL_Color colors[NB_COLORS] = {
        [LIGHT_BLUE] = {0x90, 0xf5, 0xf9, 0xff}, [DARK_BLUE] = {0x00, 0xb8, 0xff, 0xff},
        [LIGHT_RED] = {0xff, 0x74, 0x6d, 0xff},  [DARK_RED] = {0xbf, 0x2f, 0x20, 0xff},
        [BLACK] = {0x06, 0x04, 0x0d, 0xff},      [WHITE] = {0xfc, 0xfe, 0xff, 0xff},
    };
    text->color = colors[new_color];
    SDL_FreeSurface(text->surface);
    text->surface = TTF_RenderText_Solid(text->font, text->text, text->color);
    SDL_DestroyTexture(text->texture);
    text->texture = SDL_CreateTextureFromSurface(ren, text->surface);
}

void text_set_font(Text text, Assets assets, enum font_type new_font, SDL_Renderer *ren) {
    text->font_type = new_font;
    text->font = F(assets, new_font);
    SDL_FreeSurface(text->surface);
    text->surface = TTF_RenderText_Solid(text->font, text->text, text->color);
    SDL_DestroyTexture(text->texture);
    text->texture = SDL_CreateTextureFromSurface(ren, text->surface);
}
