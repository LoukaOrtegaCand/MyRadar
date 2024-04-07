/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** functions to check collide between planes for my_radar
*/

#include "my_radar.h"

static int is_in_radius(all_t *all, int a)
{
    sfVector2f coo = sfSprite_getPosition(all->pl[a].sprite);
    float distance;
    float radius;
    float len_x;
    float len_y;

    for (int t = 0; t < all->nbr_towers; t++) {
        len_x = coo.x + 14 - all->to[t].x;
        len_y = coo.y + 13 - all->to[t].y;
        distance = sqrtf(len_x * len_x + len_y * len_y);
        radius = all->to[t].r * 19.20;
        if (distance < radius)
            return (1);
    }
    return (0);
}

static void hitbox_collide(all_t *all, int a)
{
    sfVector2f sq1 = sfRectangleShape_getPosition(all->pl[a].hitbox);
    sfVector2f sq2;

    for (int i = 0; i < all->nbr_planes; i++) {
        sq2 = sfRectangleShape_getPosition(all->pl[i].hitbox);
        if (a != i && sq1.x - 20 < sq2.x && sq1.x + 20 > sq2.x &&
        sq1.y - 20 < sq2.y && sq1.y + 20 > sq2.y) {
            all->pl[a].destroy = 1;
            all->pl[i].destroy = 1;
            all->crashed += 2;
        }
        destroy(all);
    }
}

void check_collide(all_t *all)
{
    for (int a = 0; a < all->nbr_planes; a++) {
        if (is_in_radius(all, a))
            continue;
        hitbox_collide(all, a);
    }
}
