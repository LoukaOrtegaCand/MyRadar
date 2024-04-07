/*
** EPITECH PROJECT, 2023
** funct_o
** File description:
** function for flag 'o'
*/

#include "my.h"
#include <stdarg.h>

int pfunct_o(int count, va_list list)
{
    count += pmy_put_octal(va_arg(list, int));
    return (count);
}
