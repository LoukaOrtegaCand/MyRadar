/*
** EPITECH PROJECT, 2023
** my_strcapitalize
** File description:
** capitalize a string
*/

#include "my.h"

char *select(char *str, int i)
{
    if ((str[i - 1] < 'a' || str[i - 1] > 'z') &&
        (str[i - 1] < 'A' || str[i - 1] > 'Z') &&
        (str[i - 1] < '0' || str[i - 1] > '9')) {
        if ((str[i] >= 'a') && (str[i] <= 'z')) {
            str[i] -= 32;
        }
    }
    return (str);
}

char *my_strcapitalize(char *str)
{
    str = my_strlowcase(str);
    if ((str[0] >= 'a') && (str[0] <= 'z'))
        str[0] -= 32;
    for (int i = 1; str[i] != '\0'; i++) {
        select(str, i);
    }
    return (str);
}
