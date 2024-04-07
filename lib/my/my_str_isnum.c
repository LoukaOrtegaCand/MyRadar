/*
** EPITECH PROJECT, 2023
** my_str_isnum
** File description:
** str is num
*/

int my_str_isnum(char const *str)
{
    int a = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] < '0') || (str[i] > '9')) {
            a = 0;
        }
    }
    return (a);
}
