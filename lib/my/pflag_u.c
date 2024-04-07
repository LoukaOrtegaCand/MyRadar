/*
** EPITECH PROJECT, 2023
** funct_u
** File description:
** function for flag 'u'
*/

#include "my.h"
#include <stdarg.h>

int pfunct_u(int count, va_list list)
{
    count += pmy_put_unbr(va_arg(list, int));
    return (count);
}
