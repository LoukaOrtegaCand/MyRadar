/*
** EPITECH PROJECT, 2023
** my_strncat
** File description:
** catenates n char of a string
*/

char *my_strncat(char *dest, char const *src, int nb)
{
    int j = 0;
    int k = 0;

    for (; dest[j] != '\0'; j++)
    while (k != nb) {
        dest[j] = src[k];
        j++;
        k++;
    }
    dest[j] = '\0';
    return (dest);
}
