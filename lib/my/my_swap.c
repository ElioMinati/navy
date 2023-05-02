/*
** EPITECH PROJECT, 2021
** Parameters swap
** File description:
** Swap parameters in a function
*/

void my_swap(int *a, int *b)
{
    int b1 = *b;

    *b = *a;
    *a = b1;
}
