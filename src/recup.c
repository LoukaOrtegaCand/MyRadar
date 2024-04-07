/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** recup info for my_radar
*/

#include "my_radar.h"

static int check_char(char c)
{
    if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) ||
        (c >= 97 && c <= 122))
        return (1);
    return (0);
}

static int nbr_of_word(all_t *all)
{
    int i = 0;
    int nbr = 0;

    while (all->str[i] != '\0') {
        for (; check_char(all->str[i]); i++);
        nbr += 1;
        for (; !check_char(all->str[i]) && all->str[i] != '\0'; i++);
    }
    return (nbr);
}

static int word_size(all_t *all, int nbr)
{
    int i = 0;
    int n = 0;
    int nbch = 0;

    while (all->str[i] != '\0' && n != nbr) {
        for (; check_char(all->str[i]); i++);
        n += 1;
        for (; !check_char(all->str[i]) && all->str[i] != '\0'; i++);
    }
    for (; check_char(all->str[i]); i++)
        nbch += 1;
    return (nbch);
}

static void copytab(all_t *all)
{
    int i = 0;
    int j = 0;
    int w = 0;

    while (all->str[i] != '\0') {
        j = 0;
        for (; check_char(all->str[i]); i++) {
            all->tab[w][j] = all->str[i];
            j += 1;
        }
        all->tab[w][j] = '\0';
        w += 1;
        for (; !check_char(all->str[i]) && all->str[i] != '\0'; i++);
    }
}

static void my_str_to_word_array(all_t *all)
{
    int nbr = nbr_of_word(all);
    int nbch = 0;

    all->tab = malloc(sizeof(char *) * (nbr + 1));
    for (int i = 0; i < nbr; i++) {
        nbch = word_size(all, i);
        all->tab[i] = malloc(sizeof(char) * nbch + 1);
    }
    copytab(all);
    all->tab[nbr] = NULL;
}

static void count_a_and_t(all_t *all)
{
    all->nbr_planes = 0;
    all->nbr_towers = 0;
    for (int i = 0; all->tab[i] != NULL; i++) {
        if (my_strcmp("A", all->tab[i]) == 0)
            all->nbr_planes += 1;
        if (my_strcmp("T", all->tab[i]) == 0)
            all->nbr_towers += 1;
    }
}

void recup(all_t *all, char **argv)
{
    struct stat info;
    char *file = argv[1];
    int fd = open(file, O_RDONLY);
    int offset = 0;
    int len;
    int size = 0;

    stat(file, &info);
    size = info.st_size;
    all->str = malloc(sizeof(char) * (size + 1));
    len = read(fd, all->str + offset, size - offset);
    while (len > 0) {
        offset += len;
        len = read(fd, all->str + offset, size - offset);
    }
    all->str[offset] = '\0';
    my_str_to_word_array(all);
    count_a_and_t(all);
}
