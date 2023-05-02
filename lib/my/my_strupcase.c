/*
** EPITECH PROJECT, 2021
** strupcase
** File description:
** modify every letter of a string to upcase
*/

int my_strlen14(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

char *my_strupcase(char *str)
{
    int length = my_strlen14(str);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] - 32 < 65)
            continue;
        str[i] = str[i] - 32;
    }
    return (str);
}
