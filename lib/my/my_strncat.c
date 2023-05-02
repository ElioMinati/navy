/*
** EPITECH PROJECT, 2021
** my_strncat
** File description:
** concatenates n characters of the src string
*/

char *my_strncat(char *dest, char const *src, int nb)
{
    int i;

    for (i = 0; dest[i] != '\0'; i++) {
        continue;
    }
    for (int j = 0; src[j] != '\0' && j < nb; j++) {
        dest[i + j] = src[j];
    }
    return (dest);
}
