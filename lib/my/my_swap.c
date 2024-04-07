/*
** EPITECH PROJECT, 2023
** my_swap
** File description:
** Function that swaps the content of two integers.
*/

void my_swap(int *a, int *b)
{
    int c = *a;

    *a = *b;
    *b = c;
}
