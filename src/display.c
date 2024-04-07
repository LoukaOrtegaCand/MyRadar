/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** display screen for my_radar
*/

#include "my_radar.h"

static void switch_events(all_t *all)
{
    if (all->event.key.code == sfKeyL && all->event.type == sfEvtKeyReleased
    && all->screen == 1) {
        if (all->switch_h == 1)
            all->switch_h = 0;
        else
            all->switch_h = 1;
    }
    if (all->event.key.code == sfKeyS && all->event.type == sfEvtKeyReleased
    && all->screen == 1) {
        if (all->switch_e == 1)
            all->switch_e = 0;
        else
            all->switch_e = 1;
    }
}

static void analyse_events(all_t *all)
{
    if (all->mouse.x >= 850 && all->mouse.x <= 1120 &&
        all->mouse.y >= 450 && all->mouse.y <= 542 && all->screen == 0) {
        sfSprite_setScale(all->sprite[1].sprite, (sfVector2f){12, 12});
        sfSprite_setPosition(all->sprite[1].sprite, (sfVector2f){823, 429});
        if (all->event.type == sfEvtMouseButtonPressed) {
            all->screen = 1;
            sfClock_restart(all->timer->clock);
        }
    } else {
        sfSprite_setScale(all->sprite[1].sprite, (sfVector2f){10, 10});
        sfSprite_setPosition(all->sprite[1].sprite, (sfVector2f){850, 440});
    }
    if (all->event.type == sfEvtClosed ||
    all->event.key.code == sfKeyQ)
        sfRenderWindow_close(all->window);
    if (all->event.key.code == sfKeyEscape && all->screen == 1) {
        all->screen = 0;
    }
    switch_events(all);
}

char *write_nbr(int nbr, char *count)
{
    int j = nbr;
    int i = 0;

    if (nbr < 10) {
        count[0] = nbr + '0';
        count[1] = '\0';
    } else {
        for (; j > 0; i++) {
            count[i] = (j % 10) + '0';
            j = j / 10;
        }
        count[i] = '\0';
    }
    if (nbr > 9)
        my_revstr(count);
    return (count);
}

static void display_elapsed_time(all_t *all)
{
    all->timer->time = sfClock_getElapsedTime(all->timer->clock);
    all->timer->second = all->timer->time.microseconds / 1000000.0;
    write_nbr(all->timer->second, all->timer->str);
    sfText_setString(all->txt[1], all->timer->str);
    sfRenderWindow_drawText(all->window, all->txt[1], NULL);
    all->tick->time = sfClock_getElapsedTime(all->tick->clock);
    all->tick->second = all->tick->time.microseconds / 1000000.0;
}

static void drawplanes(all_t *all)
{
    for (int a = 0; a < all->nbr_planes; a++) {
        if (all->switch_e == 1 && all->timer->second >= all->pl[a].d)
            SFDS(all->window, all->pl[a].sprite, NULL);
        if (all->switch_h == 1 && all->timer->second >= all->pl[a].d)
            SDRS(all->window, all->pl[a].hitbox, NULL);
    }
}

static void drawtowers(all_t *all)
{
    for (int t = 0; t < all->nbr_towers; t++) {
        if (all->switch_e == 1)
            SFDS(all->window, all->to[t].sprite, NULL);
        if (all->switch_h == 1)
            SDCS(all->window, all->to[t].area, NULL);
    }
}

static void drawscreen(all_t *all)
{
    if (all->screen == 0) {
        SFDS(all->window, all->sprite[0].sprite, NULL);
        SFDS(all->window, all->sprite[1].sprite, NULL);
        sfRenderWindow_drawText(all->window, all->txt[0], NULL);
    }
    if (all->screen == 1) {
        SFDS(all->window, all->sprite[2].sprite, NULL);
        drawtowers(all);
        drawplanes(all);
        update_txt(all);
        display_elapsed_time(all);
        check_collide(all);
        destroy(all);
        if (all->tick->second >= 0.1) {
            movement(all);
            sfClock_restart(all->tick->clock);
        }
    }
}

void setwindow(all_t *all)
{
    while (sfRenderWindow_isOpen(all->window)) {
        all->mouse = sfMouse_getPositionRenderWindow(all->window);
        while (sfRenderWindow_pollEvent(all->window, &all->event))
            analyse_events(all);
        sfRenderWindow_clear(all->window, sfBlack);
        drawscreen(all);
        if (all->nbr_planes == 0)
            sfRenderWindow_close(all->window);
        sfRenderWindow_display(all->window);
    }
}
