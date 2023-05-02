/*
** EPITECH PROJECT, 2021
** my_strcat
** File description:
** concatenate 2 strings
*/

char *my_strcat(char *dest, char const *src)
{
    int i;

    for (i = 0; dest[i] != '\0'; i++) {
        continue;
    }
    for (int j = 0; src[j] != '\0'; j++) {
        dest[i + j] = src[j];
    }
    return (dest);
}
