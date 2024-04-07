/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** move functions for my_radar
*/

#include "my_radar.h"

int landed(all_t *all, int i, sfVector2f pos)
{
    if (all->pl[i].abscisse >= 0 && pos.x >= all->pl[i].ax) {
        if ((all->pl[i].ordonnee >= 0 && pos.y >= all->pl[i].ay) ||
        (all->pl[i].ordonnee <= 0 && pos.y <= all->pl[i].ay)) {
            all->pl[i].destroy = 1;
            all->landed += 1;
            return (1);
        }
    }
    if (all->pl[i].abscisse <= 0 && pos.x <= all->pl[i].ax) {
        if ((all->pl[i].ordonnee >= 0 && pos.y >= all->pl[i].ay) ||
        (all->pl[i].ordonnee <= 0 && pos.y <= all->pl[i].ay)) {
            all->pl[i].destroy = 1;
            all->landed += 1;
            return (1);
        }
    }
    return (0);
}

void movement(all_t *all)
{
    sfVector2f pos;

    for (int a = 0; a < all->nbr_planes; a++) {
        pos = sfSprite_getPosition(all->pl[a].sprite);
        pos.x += 14;
        pos.y += 13;
        if (all->timer->second >= all->pl[a].d && landed(all, a, pos) == 0) {
            sfSprite_move(all->pl[a].sprite, all->pl[a].dir);
            sfRectangleShape_move(all->pl[a].hitbox, all->pl[a].dir);
        }
    }
}
