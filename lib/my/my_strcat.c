/*
** EPITECH PROJECT, 2023
** my_strcat
** File description:
** catenates string
*/

char *my_strcat(char *dest, char const *src)
{
    int j = 0;
    int k = 0;

    for (; dest[j] != '\0'; j++);
    while (src[k] != '\0') {
        dest[j] = src[k];
        j++;
        k++;
    }
    dest[j] = src[k];
    return (dest);
}
