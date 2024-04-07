/*
** EPITECH PROJECT, 2023
** my_strncmp
** File description:
** string n cmp
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;
    int nbr;

    for (; s1[i] != '\0' && s1[i] == s2[i] && i < n; i++);
    nbr = (s1[i] - s2[i]);
    return (nbr);
}
