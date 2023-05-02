/*
** EPITECH PROJECT, 2021
** my_strcpy
** File description:
** copy str to another on
*/

int my_strlen15(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

char *my_strcpy(char *dest, char const *src)
{
    for (int i = 0; i <= my_strlen15(src); i++) {
        dest[i] = src[i];
    }
    return (dest);
}
