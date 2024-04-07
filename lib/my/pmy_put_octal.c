/*
** EPITECH PROJECT, 2023
** my_put_octal
** File description:
** my_put_octal for my_printf
*/

#include "my.h"

int pmy_put_octal(int nb)
{
    int count = 0;

    if (nb < 8 && nb >= 0) {
        pmy_putchar(nb + 48);
        count += 1;
    }
    if (nb < 0) {
        pmy_putchar('-');
        count += 1;
        count += pmy_put_octal(nb * -1);
    }
    if (nb > 7) {
        count += pmy_put_octal(nb / 8);
        count += pmy_put_octal(nb % 8);
    }
    return (count);
}
