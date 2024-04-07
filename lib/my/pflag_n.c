/*
** EPITECH PROJECT, 2023
** funct_n
** File description:
** function for flag 'n'
*/

#include "my.h"
#include <stdarg.h>

int pfunct_n(int count, va_list list)
{
    unsigned int *nmbr = va_arg(list, unsigned int *);

    *nmbr = count;
    return (count);
}
