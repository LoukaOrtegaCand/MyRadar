/*
** EPITECH PROJECT, 2023
** my_is_prime
** File description:
** is prime
*/

int my_is_prime(int nb)
{
    int i = 2;
    int a = 1;

    for (; i < nb; i++) {
        if (nb % i == 0) {
            a = 0;
        }
    }
    if (nb <= 1) {
        return (0);
    } else {
        return (a);
    }
}
