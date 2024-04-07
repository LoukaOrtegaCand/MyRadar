/*
** EPITECH PROJECT, 2023
** funct_c
** File description:
** function for flag 'c'
*/

#include "my.h"
#include <stdarg.h>

int pfunct_c(int count, va_list list)
{
    pmy_putchar((char) va_arg(list, int));
    count += 1;
    return (count);
}
