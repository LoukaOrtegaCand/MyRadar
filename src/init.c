/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** init for my_radar
*/

#include "my_radar.h"

static void create_obj(all_t *all, val_t *val, int i)
{
    all->sprite[i].sprite = SFCR;
    all->sprite[i].texture = SFCF(val[i].path, NULL);
    all->sprite[i].scale.x = val[i].size;
    all->sprite[i].scale.y = val[i].size;
    all->sprite[i].pos.x = val[i].posx;
    all->sprite[i].pos.y = val[i].posy;
    all->sprite[i].rect.top = val[i].rtop;
    all->sprite[i].rect.left = val[i].rleft;
    all->sprite[i].rect.width = val[i].rwidth;
    all->sprite[i].rect.height = val[i].rheight;
    all->sprite[i].ori.x = val[i].orix;
    all->sprite[i].ori.y = val[i].oriy;
}

static void fill(all_t *all)
{
    int a = 0;
    int t = 0;

    for (int i = 0; all->tab[i] != NULL; i++) {
        if (my_strcmp(all->tab[i], "A") == 0) {
            all->pl[a].dx = my_getnbr(all->tab[i + 1]);
            all->pl[a].dy = my_getnbr(all->tab[i + 2]);
            all->pl[a].ax = my_getnbr(all->tab[i + 3]);
            all->pl[a].ay = my_getnbr(all->tab[i + 4]);
            all->pl[a].s = my_getnbr(all->tab[i + 5]);
            all->pl[a].d = my_getnbr(all->tab[i + 6]);
            a += 1;
        }
        if (my_strcmp(all->tab[i], "T") == 0) {
            all->to[t].x = my_getnbr(all->tab[i + 1]);
            all->to[t].y = my_getnbr(all->tab[i + 2]);
            all->to[t].r = my_getnbr(all->tab[i + 3]);
            t += 1;
        }
    }
}

static void create_square(all_t *all, int i)
{
    sfVector2f pos;

    pos.x = all->pl[i].dx + 5;
    pos.y = all->pl[i].dy + 3;
    all->pl[i].hitbox = sfRectangleShape_create();
    sfRectangleShape_setSize(all->pl[i].hitbox, (sfVector2f){20, 20});
    sfRectangleShape_setFillColor(all->pl[i].hitbox, sfTransparent);
    sfRectangleShape_setOutlineColor(all->pl[i].hitbox, sfGreen);
    sfRectangleShape_setOutlineThickness(all->pl[i].hitbox, 1);
    sfRectangleShape_setPosition(all->pl[i].hitbox, pos);
}

static void calculate_vector(all_t *all, int i)
{
    float xe2;
    float ye2;
    float length;

    all->pl[i].abscisse = all->pl[i].ax - all->pl[i].dx;
    all->pl[i].ordonnee = all->pl[i].ay - all->pl[i].dy;
    xe2 = all->pl[i].abscisse * all->pl[i].abscisse;
    ye2 = all->pl[i].ordonnee * all->pl[i].ordonnee;
    length = sqrtf(xe2 + ye2);
    if (length != 0) {
        all->pl[i].dir.x = (all->pl[i].abscisse / length * all->pl[i].s) / 10;
        all->pl[i].dir.y = (all->pl[i].ordonnee / length * all->pl[i].s) / 10;
    } else {
        all->pl[i].dir.x = 0;
        all->pl[i].dir.y = 0;
    }
}

static void create_planes(all_t *all)
{
    sfTexture *plane_txt = SFCF("assets/plane.png", NULL);
    sfVector2f scale;
    sfVector2f pos;

    scale.x = 0.1;
    scale.y = 0.1;
    for (int i = 0; i < all->nbr_planes; i++) {
        all->pl[i].destroy = 0;
        all->pl[i].sprite = SFCR;
        pos.x = all->pl[i].dx;
        pos.y = all->pl[i].dy;
        SFST(all->pl[i].sprite, plane_txt, sfFalse);
        sfSprite_setScale(all->pl[i].sprite, scale);
        sfSprite_setPosition(all->pl[i].sprite, pos);
        create_square(all, i);
        calculate_vector(all, i);
    }
}

static void create_circle(all_t *all, int i, sfVector2f scale)
{
    sfVector2f center;

    center.x = all->to[i].x - (all->to[i].r * 19.20) + (256 * scale.x);
    center.y = all->to[i].y - (all->to[i].r * 19.20) + (256 * scale.y);
    all->to[i].area = sfCircleShape_create();
    sfCircleShape_setRadius(all->to[i].area, all->to[i].r * 19.20);
    sfCircleShape_setFillColor(all->to[i].area, sfTransparent);
    sfCircleShape_setOutlineColor(all->to[i].area, sfBlue);
    sfCircleShape_setOutlineThickness(all->to[i].area, 1);
    sfCircleShape_setPosition(all->to[i].area, center);
}

static void create_towers(all_t *all)
{
    sfTexture *tower_txt = SFCF("assets/tower.png", NULL);
    sfVector2f scale;
    sfVector2f pos;

    scale.x = 0.1;
    scale.y = 0.1;
    for (int i = 0; i < all->nbr_towers; i++) {
        all->to[i].sprite = SFCR;
        pos.x = all->to[i].x;
        pos.y = all->to[i].y;
        SFST(all->to[i].sprite, tower_txt, sfFalse);
        sfSprite_setScale(all->to[i].sprite, scale);
        sfSprite_setPosition(all->to[i].sprite, pos);
        create_circle(all, i, scale);
    }
}

static void apply(all_t *all)
{
    for (int j = 0; j < SPRITE_NBR; j++) {
        SFST(all->sprite[j].sprite, all->sprite[j].texture, sfFalse);
        sfSprite_setScale(all->sprite[j].sprite, all->sprite[j].scale);
        sfSprite_setPosition(all->sprite[j].sprite, all->sprite[j].pos);
    }
    create_planes(all);
    create_towers(all);
}

void init(all_t *all)
{
    val_t val[] = {
        {"assets/menu.png", 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {"assets/start_button.png", 10, 850, 440, 0, 0, 0, 0, 0, 0},
        {"assets/map.png", 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {NULL, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    all->landed = 0;
    all->crashed = 0;
    all->switch_e = 1;
    all->switch_h = 1;
    memory_allocation(all);
    all->timer->clock = sfClock_create();
    all->tick->clock = sfClock_create();
    for (int i = 0; i < SPRITE_NBR; i++) {
        create_obj(all, val, i);
    }
    create_text(all);
    fill(all);
    apply(all);
}
