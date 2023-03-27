#ifndef TEXT_H
#define TEXT_H

#include <SDL.h>
#include <stdbool.h>

#include "assets.h"
#include "input.h"

/* **************************************************************** */

enum font_type { CYBERPUNK, OXTA, RAJDHANI };

enum font_color { LIGHT_BLUE, DARK_BLUE, LIGHT_RED, DARK_RED, BLACK, WHITE, NB_COLORS };

struct Text_s {
    char *text;

    // SDL_Rect hitbox;

    enum font_type font_type;
    TTF_Font *font;

    enum font_color font_color;
    SDL_Color color;

    SDL_Surface *surface;
    SDL_Texture *texture;
};

typedef struct Text_s *Text;

/* **************************************************************** */

Text text_create(Assets a, char *label, int font_type, int font_color, SDL_Renderer *ren);
void text_delete(Text text);
void text_render(Text text, SDL_Renderer *ren, SDL_Rect rect);

void text_set_text(Text text, char *new_text, SDL_Renderer *ren);
void text_set_color(Text text, enum font_color new_color, SDL_Renderer *ren);
void text_set_font(Text text, Assets assets, enum font_type new_font, SDL_Renderer *ren);

#endif /* TEXT_H */