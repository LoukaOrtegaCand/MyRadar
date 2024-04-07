/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** texts init for my_radar
*/

#include "my_radar.h"

static void create_title(all_t *all, sfFont *font)
{
    all->txt[0] = sfText_create();
    sfText_setString(all->txt[0], "My Radar");
    sfText_setFont(all->txt[0], font);
    sfText_setCharacterSize(all->txt[0], 120);
    sfText_setFillColor(all->txt[0], sfColor_fromRGB(90, 106, 170));
    sfText_setPosition(all->txt[0], (sfVector2f){550, 200});
    sfText_setOutlineColor(all->txt[0], sfBlack);
    sfText_setOutlineThickness(all->txt[0], 10.0);
}

static void create_timer(all_t *all, sfFont *font)
{
    all->txt[1] = sfText_create();
    sfText_setFont(all->txt[1], font);
    sfText_setCharacterSize(all->txt[1], 30);
    sfText_setFillColor(all->txt[1], sfWhite);
    sfText_setPosition(all->txt[1], (sfVector2f){1850, 30});
    sfText_setOutlineColor(all->txt[1], sfColor_fromRGB(49, 71, 100));
    sfText_setOutlineThickness(all->txt[1], 4.0);
}

static void create_landed(all_t *all, sfFont *font)
{
    all->txt[2] = sfText_create();
    sfText_setString(all->txt[2], "Landed");
    sfText_setFont(all->txt[2], font);
    sfText_setCharacterSize(all->txt[2], 30);
    sfText_setFillColor(all->txt[2], sfColor_fromRGB(90, 106, 170));
    sfText_setPosition(all->txt[2], (sfVector2f){1800, 900});
    sfText_setOutlineColor(all->txt[2], sfBlack);
    sfText_setOutlineThickness(all->txt[2], 4.0);
}

static void create_crashed(all_t *all, sfFont *font)
{
    all->txt[3] = sfText_create();
    sfText_setString(all->txt[3], "Crashed");
    sfText_setFont(all->txt[3], font);
    sfText_setCharacterSize(all->txt[3], 30);
    sfText_setFillColor(all->txt[3], sfColor_fromRGB(90, 106, 170));
    sfText_setPosition(all->txt[3], (sfVector2f){1783, 950});
    sfText_setOutlineColor(all->txt[3], sfBlack);
    sfText_setOutlineThickness(all->txt[3], 4.0);
}

static void create_count_landed(all_t *all, sfFont *font)
{
    all->txt[4] = sfText_create();
    sfText_setFont(all->txt[4], font);
    sfText_setCharacterSize(all->txt[4], 30);
    sfText_setFillColor(all->txt[4], sfWhite);
    sfText_setPosition(all->txt[4], (sfVector2f){1700, 900});
    sfText_setOutlineColor(all->txt[4], sfColor_fromRGB(49, 71, 100));
    sfText_setOutlineThickness(all->txt[4], 4.0);
}

static void create_count_crashed(all_t *all, sfFont *font)
{
    all->txt[5] = sfText_create();
    sfText_setFont(all->txt[5], font);
    sfText_setCharacterSize(all->txt[5], 30);
    sfText_setFillColor(all->txt[5], sfWhite);
    sfText_setPosition(all->txt[5], (sfVector2f){1700, 950});
    sfText_setOutlineColor(all->txt[5], sfColor_fromRGB(49, 71, 100));
    sfText_setOutlineThickness(all->txt[5], 4.0);
}

void create_text(all_t *all)
{
    sfFont *font1 = sfFont_createFromFile("assets/title.TTF");
    sfFont *font2 = sfFont_createFromFile("assets/timer.otf");

    create_title(all, font1);
    create_timer(all, font2);
    create_landed(all, font2);
    create_crashed(all, font2);
    create_count_landed(all, font2);
    create_count_crashed(all, font2);
}

void update_txt(all_t *all)
{
    write_nbr(all->landed, all->str_landed);
    sfText_setString(all->txt[4], all->str_landed);
    write_nbr(all->crashed, all->str_crashed);
    sfText_setString(all->txt[5], all->str_crashed);
    sfRenderWindow_drawText(all->window, all->txt[2], NULL);
    sfRenderWindow_drawText(all->window, all->txt[3], NULL);
    sfRenderWindow_drawText(all->window, all->txt[4], NULL);
    sfRenderWindow_drawText(all->window, all->txt[5], NULL);
}
