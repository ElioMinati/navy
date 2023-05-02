/*
** EPITECH PROJECT, 2021
** strcapitalize
** File description:
** capitalize every letter of each word in a string
*/

int my_strlen6(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

char *my_strcapitalize(char *str)
{
    int length = my_strlen6(str);

    for (int i = 0; i <= length; i++) {
        if (i == 0 && str[i] >= 97) {
            str[0] = str[i] - 32;
        }
        if (str[i] == ' ' && str[i + 1] > 91) {
            str[i + 1] = str[i + 1] - 32;
        }
    }
    return (str);
}
