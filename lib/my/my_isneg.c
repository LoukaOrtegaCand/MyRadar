/*
** EPITECH PROJECT, 2023
** my_isneg
** File description:
** Function that displays 'N' if the integer passed as
** parameter is negative or 'P', if positive or null
*/

#include "my.h"

int my_isneg(int a)
{
    if (a >= 0)
        my_putchar('P');
    else {
        my_putchar('N');
    }
    return (0);
}
