/*
** EPITECH PROJECT, 2023
** my_str_isalpha
** File description:
** string is alpha
*/

int my_str_isalpha(char const *str)
{
    int a = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] < 'A') || (str[i] > 'z')) {
            a = 0;
        }
        if ((str[i] > 'Z') && (str[i] < 'a')) {
            a = 0;
        }
    }
    return (a);
}
