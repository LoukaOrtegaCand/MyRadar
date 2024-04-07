/*
** EPITECH PROJECT, 2023
** my_str_isupper
** File description:
** str is upper
*/

#include "my.h"

int my_str_isupper(char const *str)
{
    int a = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] < 'A') || (str[i] > 'Z')) {
            a = 0;
        }
    }
    my_put_nbr(a);
    return (a);
}
