#include "stats.h"

#include "button.h"
#include "button_create.h"
#include "env.h"
#include "input.h"

/* **************************************************************** */

static void stats_create(Scene stats) {
    stats->texture = malloc(sizeof(SDL_Texture *) * NB_STATS_TEXTURES);
    assert(stats->texture);
    stats->button = malloc(sizeof(struct Button_s) * NB_STATS_BUTTONS);
    assert(stats->button);
    // stats->text = malloc(sizeof(SDL_Text) * NB_STATS_TEXTS);
    // assert(stats->text);
    // stats->font = malloc(sizeof(SDL_Font) * NB_STATS_FONTS);
    // assert(stats->font);
    // stats->mixer = malloc(sizeof(SDL_Mixer) * NB_STATS_MIXERS);
    // assert(stats->mixer);

    stats->nb_textures = NB_STATS_TEXTURES;
    stats->nb_buttons = NB_STATS_BUTTONS;
    stats->nb_texts = NB_STATS_TEXTS;
    stats->nb_fonts = NB_STATS_FONTS;
    stats->nb_mixers = NB_STATS_MIXERS;

    stats->is_active = false;
}

void stats_init(Scene stats, SDL_Renderer *ren) { stats_create(stats); }

void stats_process(Scene *scenes, Input input, SDL_Renderer *ren) {}

/* **************************************************************** */
