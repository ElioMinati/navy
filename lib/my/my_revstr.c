/*
** EPITECH PROJECT, 2021
** reverse string
** File description:
** function that reverses a string
*/

int my_strlen1(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

char *my_revstr(char *str)
{
    int temp;
    int length = my_strlen1(str) - 1;

    for (int i = 0; i < length; i++) {
        temp = str[length];
        str[length] = str[i];
        str[i] = temp;
        length--;
    }
    return (str);
}
