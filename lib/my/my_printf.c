/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** my_printf
*/

#include <stddef.h>
#include <stdarg.h>
#include "my.h"

static const link_t handler[] = {
    {.flag = 'd', .funct = &pfunct_d},
    {.flag = 'i', .funct = &pfunct_i},
    {.flag = 'c', .funct = &pfunct_c},
    {.flag = 's', .funct = &pfunct_s},
    {.flag = '%', .funct = &pfunct_percent},
    {.flag = 'o', .funct = &pfunct_o},
    {.flag = 'u', .funct = &pfunct_u},
    {.flag = 'x', .funct = &pfunct_x_min},
    {.flag = 'X', .funct = &pfunct_x_maj},
    {.flag = 'p', .funct = &pfunct_p},
    {.flag = 'n', .funct = &pfunct_n},
    {'\0', NULL}
};

int handthefunct(va_list list, int count, int i, char const *format)
{
    for (int j = 0; handler[j].funct != NULL; j++) {
        if (format[i] == handler[j].flag) {
            count = handler[j].funct(count, list);
        }
    }
    return (count);
}

int my_printf(char const *format, ...)
{
    va_list list;
    int count = 0;

    va_start(list, format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            i += 1;
            count = handthefunct(list, count, i, format);
        } else {
            pmy_putchar(format[i]);
            count += 1;
        }
    }
    va_end(list);
    return (count);
}
