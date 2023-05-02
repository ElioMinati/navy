/*
** EPITECH PROJECT, 2021
** my_atoi.c
** File description:
** my_atoi
*/

#include <stdio.h>
#include <stdlib.h>

int my_atoi(char *str)
{
    int cb = 0;
    for (int x = 0; str[x] != '\0'; x++) {
        if (str[x] >= '0' && str[x] <= '9')
            cb = cb * 10 + (str[x] - '0');
        else
            return 0;
    }
    return cb;
}