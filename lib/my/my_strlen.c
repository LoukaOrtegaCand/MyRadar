/*
** EPITECH PROJECT, 2023
** my_strlen
** File description:
** Function that counts and returns the number of caracters of a string
*/

int my_strlen(char const *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    return (i);
}
