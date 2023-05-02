/*
** EPITECH PROJECT, 2021
** my_strlen
** File description:
** function that counts and returns the nb of chars in string
*/

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}
