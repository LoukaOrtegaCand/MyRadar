/*
** EPITECH PROJECT, 2023
** my_strtsr
** File description:
** string in string
*/

char *my_strstr(char *str, char const *to_find)
{
    int i;

    i = 0;
    while (to_find[i] != '\0') {
        if (to_find[i] != str[i])
            return (my_strstr(str + 1, to_find));
        i = i + 1;
    }
    return (str);
}
