/*
** EPITECH PROJECT, 2021
** my_getnbr
** File description:
** get number
*/

int my_is_num_char(char c);

int my_getnbr(char const *str)
{
    int i;
    int count = 0;
    int nb = 0;

    for (i = 0; str[i] == '-' || str[i] == '+' ||
    my_is_num_char(str[i]) == 0; i++) {
        if (str[i] == '\0')
            return nb;
        if (str[i] == '-')
            count++;
    }
    for (; my_is_num_char(str[i]) == 1; i++) {
        nb = nb * 10 + (str[i] - '0');
    }
    if (count % 2 == 1)
        return (nb * -1);
    return (nb);
}
