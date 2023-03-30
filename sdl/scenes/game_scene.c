#include "game_scene.h"

#include "button.h"
#include "engine.h"
#include "env.h"
#include "input.h"
#include "takuzu.h"

/* **************************************************************** */

void game_init(Conf conf, Scene game, Assets assets, SDL_Renderer *ren) {
    int nb_cell = conf->takuzu->nb_rows * conf->takuzu->nb_cols;
    scene_init(game, 12, 4, 0, 0, 0, nb_cell, 0);
    (void)conf;

    // Defaults
    SDL_Rect hitbox[12] = {{63, 90, 365, 56},  {63, 173, 365, 56},   {63, 255, 365, 56},   {63, 406, 365, 56},
                           {63, 489, 365, 56}, {63, 620, 365, 56},   {63, 702, 365, 56},   {63, 851, 365, 56},
                           {63, 934, 365, 56}, {1493, 769, 365, 56}, {1493, 851, 365, 56}, {1493, 934, 365, 56}};
    for (int i = 0; i < 12; i++) game->default_b[i] = default_create(hitbox[i], " ", DEFAULT_T, assets, ren);

    // Switches
    SDL_Rect switch_hitbox[4] = {{1619, 90, 239, 43}, {1619, 158, 239, 43}, {1619, 226, 239, 43}, {1619, 295, 239, 43}};
    for (int i = 0; i < 4; i++) game->switch_b[i] = switch_create(switch_hitbox[i], true);

    // Cells
    int cell_size =
        (conf->takuzu->nb_cols > conf->takuzu->nb_rows) ? 900 / conf->takuzu->nb_cols : 900 / conf->takuzu->nb_rows;

    SDL_Rect offset;
    offset.x = 610 + (450 - cell_size * conf->takuzu->nb_cols / 2);
    offset.y = 110 + (450 - cell_size * conf->takuzu->nb_rows / 2);
    offset = scale_rect(offset, conf->window_size);
    SDL_Rect cell_hitbox = {offset.x, offset.y, cell_size, cell_size};

    game->cell_b = malloc(sizeof(Cell) * nb_cell);
    for (uint i = 0; i < conf->takuzu->nb_rows; i++) {
        for (uint j = 0; j < conf->takuzu->nb_cols; j++) {
            game->cell_b[i * conf->takuzu->nb_cols + j] = cell_create(cell_hitbox, game_get_square(conf->takuzu, i, j));
            cell_hitbox.x += cell_size;
        }
        cell_hitbox.x = offset.x;
        cell_hitbox.y += cell_size;
    }
}

void game_process(Conf conf, Scene *scenes, Input input, Assets assets, SDL_Renderer *ren, SDL_Rect win_rect) {
    if (scenes[GAME]->is_active == false)
        return;

    (void)ren;

    // Defaults
    for (int i = 0; i < scenes[GAME]->nb_default; i++) {
        default_pressed(scenes[GAME]->default_b[i], input, win_rect, assets);
    }

    // click or key 'U'
    if (default_pressed(scenes[GAME]->default_b[9], input, win_rect, assets) || key_down(input, SDLK_u)) {
        scenes[SOUNDS]->is_active = true;
        scenes[GAME]->is_active = false;
    }

    if (default_pressed(scenes[GAME]->default_b[10], input, win_rect, assets) || key_down(input, SDLK_m)) {
        scenes[GAME]->is_active = false;
        scenes[MAIN]->is_active = true;
        conf->last_scene = MAIN;
    }

    if (default_pressed(scenes[GAME]->default_b[11], input, win_rect, assets) || key_down(input, SDLK_q)) {
        conf->quit = true;
    }

    // Switches
    if (switch_pressed(scenes[GAME]->switch_b[0], input, win_rect, assets))
        conf->errors = scenes[GAME]->switch_b[0]->state;

    if (switch_pressed(scenes[GAME]->switch_b[1], input, win_rect, assets))
        conf->hover = scenes[GAME]->switch_b[1]->state;

    if (switch_pressed(scenes[GAME]->switch_b[2], input, win_rect, assets))
        conf->timer = scenes[GAME]->switch_b[2]->state;

    if (switch_pressed(scenes[GAME]->switch_b[3], input, win_rect, assets))
        conf->accuracy = scenes[GAME]->switch_b[3]->state;

    // Cells
    for (int i = 0; i < scenes[GAME]->nb_cell; i++) {
        if (scenes[GAME]->cell_b[i]->type != CELL_IMM_BLUE && scenes[GAME]->cell_b[i]->type != CELL_IMM_RED) {
            if (game_has_error(conf->takuzu, i / conf->takuzu->nb_rows, i % conf->takuzu->nb_cols) && conf->errors) {
                scenes[GAME]->cell_b[i]->has_error = true;
            } else {
                scenes[GAME]->cell_b[i]->has_error = false;
            }

            if (cell_pressed(scenes[GAME]->cell_b[i], input, win_rect, assets)) {
                game_play_move(conf->takuzu, i / conf->takuzu->nb_rows, i % conf->takuzu->nb_cols,
                               scenes[GAME]->cell_b[i]->type);
            }
        }
    }
}

/* **************************************************************** */
