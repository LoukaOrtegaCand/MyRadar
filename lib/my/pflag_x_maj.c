/*
** EPITECH PROJECT, 2023
** funct_x_maj
** File description:
** function for flag 'X'
*/

#include "my.h"
#include <stdarg.h>

int pfunct_x_maj(int count, va_list list)
{
    count += pmy_put_hexa_maj(va_arg(list, int));
    return (count);
}
