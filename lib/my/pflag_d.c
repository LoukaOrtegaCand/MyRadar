/*
** EPITECH PROJECT, 2023
** funct_d
** File description:
** function for flag 'd'
*/

#include "my.h"
#include <stdarg.h>

int pfunct_d(int count, va_list list)
{
    count += pmy_put_nbr(va_arg(list, int));
    return (count);
}
