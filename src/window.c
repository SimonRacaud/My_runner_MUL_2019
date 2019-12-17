/*
** EPITECH PROJECT, 2019
** my_runner_2019
** File description:
** window object
*/

#include "my_runner.h"
#include "window.h"

extern const int W_WIDTH;
extern const int W_HEIGHT;
extern const int W_BPP;
extern const int FRAMERATE;
extern const char *TITLE_WINDOW;

static void window_destroy(window_t *w)
{
    sfRenderWindow_destroy(w->window);
    w->game.destroy(&w->game);
}

static window_t *window_display(window_t *w)
{
    w->game.display(w);
    sfRenderWindow_display(w->window);
    return w;
}

window_t *window_create(window_t *w, char *path_map)
{
    sfVideoMode mode = {W_WIDTH, W_HEIGHT, W_BPP};

    w->destroy = window_destroy;
    w->display = window_display;
    w->window = sfRenderWindow_create(mode, TITLE_WINDOW, sfClose |
    sfFullscreen, NULL);
    if (!w->window)
        return NULL;
    sfRenderWindow_setFramerateLimit(w->window, FRAMERATE);
    w->width = mode.width;
    w->height = mode.height;
    if (!game_create(w, path_map))
        return NULL;
    event_manager_create(&w->evt);
    return w;
}
