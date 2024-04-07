/*
** EPITECH PROJECT, 2023
** my_putchar
** File description:
** my_putchar for my_printf
*/

#include <unistd.h>

int pmy_putchar(char c)
{
    write(1, &c, 1);
}
