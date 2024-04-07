/*
** EPITECH PROJECT, 2023
** my_revstr
** File description:
** reverse string
*/

char *my_revstr(char *str)
{
    int a = 0;
    int b = 0;
    char c;

    for (; str[a] != '\0'; a++);
    a--;
    while (a > b) {
        c = str[b];
        str[b] = str[a];
        str[a] = c;
        a--;
        b++;
    }
    return (str);
}
