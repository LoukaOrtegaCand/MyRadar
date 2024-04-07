/*
** EPITECH PROJECT, 2023
** funct_s
** File description:
** function for flag 's'
*/

#include "my.h"
#include <stdarg.h>

int pfunct_s(int count, va_list list)
{
    count += pmy_putstr(va_arg(list, char *));
    return (count);
}
