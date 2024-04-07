/*
** EPITECH PROJECT, 2023
** flag_p
** File description:
** flag 'p' for myprintf
*/

#include "my.h"
#include <stdio.h>

int pfunct_p(int count, va_list list)
{
    unsigned long number = va_arg(list, unsigned long);
    unsigned long pa = (unsigned long) &number;

    pmy_put_nbr(0);
    pmy_putchar('x');
    count += 2;
    count += pmy_put_hexa_min_long(pa);
    return count;
}
