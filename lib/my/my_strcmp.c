/*
** EPITECH PROJECT, 2023
** my_strcmp
** File description:
** string cmp
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int nbr;

    for (; s1[i] != '\0' && s1[i] == s2[i]; i++);
    nbr = (s1[i] - s2[i]);
    return (nbr);
}
