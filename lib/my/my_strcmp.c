/*
** EPITECH PROJECT, 2021
** my_str cmp.c
** File description:
** reproduce the str cmp unix function
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int res = 0;

    while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]) {
        i++;
    }
    if (s1[i] == s2[i])
        return 0;
    else {
        res = s1[i] - s2[i];
        if (res < 0)
            return -1;
        else
            return 1;
    }
}
