/*
** EPITECH PROJECT, 2023
** funct_i
** File description:
** function for flag 'i'
*/

#include "my.h"
#include <stdarg.h>

int pfunct_i(int count, va_list list)
{
    count += pmy_put_nbr(va_arg(list, int));
    return (count);
}
