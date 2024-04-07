/*
** EPITECH PROJECT, 2023
** my_getnbr
** File description:
** return a number in a string
*/

int my_getnbr(char const *str)
{
    int count = 0;
    int sign = 1;
    int res = 0;

    while (str[count] < '0' || str[count] > '9') {
        if (str[count] == '-')
            sign = sign * -1;
        count = count + 1;
    }
    for (count; str[count] != '\0'; count++) {
        if (str[count] >= '0' && str[count] <= '9') {
            res = res * 10 + str[count] - '0';
        } else
            return (res * sign);
    }
    return (res * sign);
}
