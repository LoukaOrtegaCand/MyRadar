/*
** EPITECH PROJECT, 2023
** My_put_hexa_min_long
** File description:
** my_put_hexa_min but with a long
*/

#include "my.h"

int pmy_put_hexa_min_long(unsigned long nb)
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
        number += pmy_put_hexa_min_long(nb / 16);
        number += pmy_put_hexa_min_long(nb % 16);
    }
    return number;
}
