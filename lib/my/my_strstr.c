/*
** EPITECH PROJECT, 2021
** my_strstr
** File description:
** reproduce my_strstr function of linux
*/

char *my_strstr_pt2 (char *str, char const *to_find, int i)
{
    int if_true = 0;

    for (int j = 1; to_find[j] != '\0'; j++) {
        if (str[i + j] == to_find[j]) {
            continue;
        } else {
            if_true = 1;
        }
    }
    return (str + i);
}

char *my_strstr (char *str, char const *to_find)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == to_find[0]) {
            my_strstr_pt2(str, to_find, i);
            return (str + i);
        }
    }
}
