#ifndef TEXT_H
#define TEXT_H

#include <SDL.h>
#include <stdbool.h>

#include "assets.h"
#include "input.h"

/* **************************************************************** */

enum font_color { LIGHT_BLUE, DARK_BLUE, LIGHT_RED, DARK_RED, BLACK, WHITE, NB_COLORS };

struct Text_s {
    char *text;

    SDL_Rect hitbox;
    SDL_Rect scaled;

    int font_type;
    TTF_Font *font;

    int font_color;
    SDL_Color color;

    SDL_Surface *surface;
    SDL_Texture *texture;
};

typedef struct Text_s *Text;

/* **************************************************************** */

Text text_create(Assets a, char *label, int font_type, int font_color, SDL_Rect hitbox, SDL_Renderer *ren);
void text_delete(Text text);

void text_render(Text text, SDL_Renderer *ren);
void text_render_scaled(Text text, SDL_Renderer *ren, SDL_Rect win_rect);

Text text_set_text(Text text, char *new_text, Assets assets, SDL_Renderer *ren);
void text_set_color(Text text, int new_color, SDL_Renderer *ren);
void text_set_font(Text text, Assets assets, int new_font, SDL_Renderer *ren);

#endif /* TEXT_H */