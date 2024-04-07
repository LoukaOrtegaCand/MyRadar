/*
** EPITECH PROJECT, 2023
** my_putstr
** File description:
** my_putstr for my_printf
*/

#include "my.h"

int pmy_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        pmy_putchar(str[i]);
        i += 1;
    }
    return (i);
}
