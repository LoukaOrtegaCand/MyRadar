/*
** EPITECH PROJECT, 2023
** funct_x_min
** File description:
** function for flag 'x'
*/

#include "my.h"
#include <stdarg.h>

int pfunct_x_min(int count, va_list list)
{
    count += pmy_put_hexa_min(va_arg(list, int));
    return (count);
}
