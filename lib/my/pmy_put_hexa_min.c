/*
** EPITECH PROJECT, 2023
** my_put_hexa_min
** File description:
** my_put_hexa_min for my_printf
*/

#include "my.h"

int pmy_put_hexa_min(unsigned int nb)
{
    int number = 0;

    if (nb < 10 && nb >= 0) {
        pmy_putchar(nb + 48);
        number += 1;
    }
    if (nb < 16 && nb >= 10) {
        pmy_putchar(nb + 87);
        number += 1;
    }
    if (nb > 15) {
        number += pmy_put_hexa_min(nb / 16);
        number += pmy_put_hexa_min(nb % 16);
    }
    return number;
}
