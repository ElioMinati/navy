/*
** EPITECH PROJECT, 2021
** my_put_nbr
** File description:
** print number passed as arg
*/

void my_putchar(char c);

int my_put_nbr(int nb)
{
    int a;
    int mod;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb >= 10) {
        mod = (nb % 10);
        nb = (nb - mod) / 10;
        my_put_nbr(nb);
        my_putchar(mod + 48);
    } else {
        my_putchar(48 + nb % 10);
    }
}
