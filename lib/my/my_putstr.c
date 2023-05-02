/*
** EPITECH PROJECT, 2021
** my_putstr
** File description:
** display one by one charachters of a string
*/

void my_putchar(char c);

int my_putstr(char const *str)
{
    int nb = 0;

    while (str[nb] != '\0') {
        my_putchar(str[nb]);
        nb++;
    }
    return (0);
}
