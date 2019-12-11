/*
** EPITECH PROJECT, 2019
** my_runner_2019
** File description:
** parallax
*/

#include "my_runner.h"
#include "parallax.h"

extern const char *PATH_SETT01;
extern const char *PATH_SETT02;
extern const char *PATH_CLOUD;
extern const char *PATH_BG;
extern const double PARALLAX_SPEED;

static parallax_t *parallax_display(parallax_t *parallax,
sfRenderWindow *window)
{
    parallax->background[0]->display(parallax->background[0], window);
    parallax->background[1]->display(parallax->background[1], window);
    parallax->cloud[0]->display(parallax->cloud[0], window);
    parallax->cloud[1]->display(parallax->cloud[1], window);
    parallax->sett01[0]->display(parallax->sett01[0], window);
    parallax->sett01[1]->display(parallax->sett01[1], window);
    parallax->sett02[0]->display(parallax->sett02[0], window);
    parallax->sett02[1]->display(parallax->sett02[1], window);
    return parallax;
}

static void parallax_destroy(parallax_t *parallax)
{
    for (int i = 0; i < 2; i++) {
        parallax->background[i]->destroy(parallax->background[i]);
        parallax->cloud[i]->destroy(parallax->cloud[i]);
        parallax->sett01[i]->destroy(parallax->sett01[i]);
        parallax->sett02[i]->destroy(parallax->sett02[i]);
    }
}

void parallax_create(parallax_t *parallax, int width, int height)
{
    parallax_t *pa = parallax;
    sfVector2f pos_left = {-width, 0};
    sfVector2f pos_right = {0, 0};

    parallax->size = (sfVector2i){width, height};
    pa->background[0] = object_create(PATH_BG, &pos_left, &pa->size, 1);
    pa->background[1] = object_create(PATH_BG, &pos_right, &pa->size, 1);
    pa->cloud[0] = object_create(PATH_CLOUD, &pos_left, &pa->size, 1);
    pa->cloud[1] = object_create(PATH_CLOUD, &pos_right, &pa->size, 1);
    pa->sett01[0] = object_create(PATH_SETT01, &pos_left, &pa->size, 1);
    pa->sett01[1] = object_create(PATH_SETT01, &pos_right, &pa->size, 1);
    pa->sett02[0] = object_create(PATH_SETT02, &pos_left, &pa->size, 1);
    pa->sett02[1] = object_create(PATH_SETT02, &pos_right, &pa->size, 1);
    parallax_set_speed(parallax, PARALLAX_SPEED);
    parallax->destroy = &parallax_destroy;
    parallax->display = &parallax_display;
    parallax->set_speed = &parallax_set_speed;
    parallax->move = &parallax_move;
}
