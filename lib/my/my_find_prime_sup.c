/*
** EPITECH PROJECT, 2021
** my_find_prime_sup
** File description:
** function that returns the smallest prime number that is greater
*/

int my_is_prime1(int nb)
{
    if (nb <= 1)
        return (2);
    for (int i = 2; i < nb; i++) {
        if (nb % i == 0)
            return (0);
    }
    return (1);
}

int my_find_prime_sup(int nb)
{
    if (my_is_prime1(nb) == 2)
        return (2);
    for (int i = nb; i < nb * 2; i++) {
        if (my_is_prime1(i) == 1)
            return (i);
    }
}
