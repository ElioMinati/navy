/*
** EPITECH PROJECT, 2021
** my_compute_square_root
** File description:
** function that returns the square root of the parameter
*/

int my_compute_square_root(int nb)
{
    int nb1 = nb / 2;

    if (nb == 1)
        return (1);
    if (nb <= 0)
        return (0);
    for (int init = 0; init <= nb1; init++) {
        if (init * init == nb)
            return (init);
    }
    return (0);
}
