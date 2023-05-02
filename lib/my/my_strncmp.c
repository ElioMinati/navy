/*
** EPITECH PROJECT, 2021
** my_strncmp
** File description:
** reproduce the my_strncmp function of linux
*/

int my_strlen4(char const *str, int n)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    if (i > n)
        i = n;
    return (i);
}

int my_strncmp(char const *s1, char const *s2, int n)
{
    int length_s1 = my_strlen4(s1, n);
    int length_s2 = my_strlen4(s2, n);

    if (length_s1 - length_s2 == 0) {
        return (0);
    }
    if (length_s1 - length_s2 > 0) {
        return (length_s1 - length_s2);
    }
    return (length_s1 - length_s2);
}
