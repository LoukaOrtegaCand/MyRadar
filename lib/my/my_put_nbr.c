/*
** EPITECH PROJECT, 2023
** my_put_nbr
** File description:
** displays a number
*/

#include "my.h"

int my_put_nbr(int nb)
{
    int dizaines;
    int unites;

    if (nb < 0) {
        my_putchar('-');
        my_put_nbr(-nb);
    } else {
        dizaines = nb / 10;
        unites = nb % 10;
        if (dizaines != 0)
            my_put_nbr(dizaines);
        my_putchar(unites + '0');
    }
    return (0);
}
