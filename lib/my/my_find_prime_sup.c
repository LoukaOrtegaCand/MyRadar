/*
** EPITECH PROJECT, 2023
** my_find_prime_sup
** File description:
** find sup prime
*/

#include "my.h"

int my_find_prime_sup(int nb)
{
    int i = 0;

    for (; my_is_prime(nb + i) == 0; i++);
    return (nb + i);
}
