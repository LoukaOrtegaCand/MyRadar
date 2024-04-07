/*
** EPITECH PROJECT, 2023
** my_str_islower
** File description:
** str slower
*/

int my_str_islower(char const *str)
{
    int a = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] < 'a') || (str[i] > 'z')) {
            a = 0;
        }
    }
    return (a);
}
