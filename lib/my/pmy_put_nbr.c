/*
** EPITECH PROJECT, 2023
** my_put_nbr
** File description:
** my_put_nbr for my_printf
*/

#include "my.h"

int pmy_put_nbr(int nb)
{
    int count = 0;

    if (nb < 10 && nb >= 0) {
        pmy_putchar(nb + 48);
        count += 1;
    }
    if (nb < 0) {
        pmy_putchar('-');
        count += 1;
        count += pmy_put_nbr(nb * -1);
    }
    if (nb > 9) {
        count += pmy_put_nbr(nb / 10);
        count += pmy_put_nbr(nb % 10);
    }
    return count;
}
