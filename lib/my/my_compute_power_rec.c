/*
** EPITECH PROJECT, 2021
** my_compute_power_rec
** File description:
** recursive function that returns the parameter to the power of the other one
*/

int my_compute_power_rec(int nb, int p)
{
    int result;

    if (p < 0)
        return (0);
    if (p == 0)
        return (1);
    result = nb * my_compute_power_rec(nb, p - 1);
    return (result);
}
