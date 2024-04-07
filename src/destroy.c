/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** destroy sprite for my_radar
*/

#include "my_radar.h"

static void slide_tab(all_t *all, int a)
{
    for (; a < all->nbr_planes; a++) {
        all->pl[a] = all->pl[a + 1];
    }
}

void destroy(all_t *all)
{
    for (int a = 0; a < all->nbr_planes; a++) {
        if (all->pl[a].destroy == 1) {
            sfSprite_destroy(all->pl[a].sprite);
            sfRectangleShape_destroy(all->pl[a].hitbox);
            all->nbr_planes -= 1;
            slide_tab(all, a);
        }
    }
}

void memory_allocation(all_t *all)
{
    all->txt = malloc(sizeof(sfText *) * 6);
    all->sprite = malloc(SPRITE_NBR * sizeof(sprite_t));
    all->pl = malloc(sizeof(plane_t) * all->nbr_planes);
    all->to = malloc(sizeof(tower_t) * all->nbr_towers);
    all->timer = malloc(sizeof(gt_t) * 1);
    all->timer->str = malloc(sizeof(char) * 5);
    all->str_landed = malloc(sizeof(char) * 5);
    all->str_crashed = malloc(sizeof(char) * 5);
    all->tick = malloc(sizeof(tick_t) * 1);
}

void destroy_all(all_t *all)
{
    for (int i = 0; i < SPRITE_NBR; i++)
        sfSprite_destroy(all->sprite[i].sprite);
    sfClock_destroy(all->tick->clock);
    sfClock_destroy(all->timer->clock);
    for (int i = 0; i < 5; i++)
        sfText_destroy(all->txt[i]);
    for (int i = 0; i < all->nbr_towers; i++) {
        sfSprite_destroy(all->to[i].sprite);
        sfCircleShape_destroy(all->to[i].area);
    }
}

void free_all(all_t *all)
{
    free(all->txt);
    free(all->sprite);
    free(all->pl);
    free(all->to);
    free(all->timer->str);
    free(all->timer);
    free(all->str_landed);
    free(all->str_crashed);
    free(all->tick);
    free(all->str);
    for (int i = 0; all->tab[i - 1] != NULL; i++)
        free(all->tab[i]);
    free(all->tab);
}
