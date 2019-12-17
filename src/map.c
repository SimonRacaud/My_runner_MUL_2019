/*
** EPITECH PROJECT, 2019
** my_runner_2019
** File description:
** map object
*/

#include "my_runner.h"
#include "map.h"

extern const int NB_TYPE_BLOCK;
extern const int BLOCK_SIZE;

static void map_destroy(map_t *map)
{
    map->parallax.destroy(&map->parallax);
    if (map->buffer != NULL) {
        free(map->buffer);
    }
    /*for (int i = 0; i < NB_TYPE_BLOCK; i++) {
        map->type_block[i]->destroy(map->type_block[i]);
    }
    free(map->type_block);
    for (int i = 0; i < map->width; i++)
        free(map->map[i]);*/
}

static map_t *map_display(window_t *w)
{
    w->game.map.parallax.display(&w->game.map.parallax, w->window,
    w->game.clock);
    w->game.map.parallax.move(&w->game.map.parallax);
    return (&w->game.map);
}

map_t *map_create(window_t *w, char *file_name)
{
    w->game.map.destroy = map_destroy;
    w->game.map.display = map_display;
    w->game.map.block_size = BLOCK_SIZE;
    w->game.map.file_name = file_name;
    w->game.map.buffer = NULL;
    w->game.map.height = 0;
    w->game.map.width = 0;
    if (map_load_from_file(&w->game.map) == EXIT_ERROR)
        return NULL;
    parallax_create(w, w->width, w->height);
    return (&w->game.map);
}
