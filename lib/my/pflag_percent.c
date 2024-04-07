/*
** EPITECH PROJECT, 2023
** funct_percent
** File description:
** function for flag '%'
*/

#include <stdarg.h>
#include "my.h"

int pfunct_percent(int count, va_list list)
{
    pmy_putchar('%');
    count += 1;
    return (count);
}
