/*
** EPITECH PROJECT, 2021
** my_strlowcase
** File description:
** modify every letter of a string to lower case
*/

char *my_strlowcase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] + 32 > 123)
            continue;
        str[i] = str[i] + 32;
    }
    return (str);
}
