/*
** EPITECH PROJECT, 2023
** my_strncpy
** File description:
** copy n char of a string
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int length;
    int k = 0;
    int j = 0;

    while (src[k] != '\0') {
        k++;
        length++;
    }
    if (n <= length) {
        for (int i = 0; i < n; i++)
            dest[i] = src[i];
    }
    if (n > length) {
        while (j < n) {
            dest[j] = src[j];
            j++;
        }
    }
    return (dest);
}
