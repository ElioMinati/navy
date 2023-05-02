/*
** EPITECH PROJECT, 2021
** array2d.c
** File description:
** array2d
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "include/navy.h"

char **mallocarray2d(int rows, int cols)
{
    char **mapmalloc;
    int i;

    mapmalloc = malloc(sizeof(char *) * (rows + 1));
    for (i = 0; i < rows; i++) {
        mapmalloc[i] = malloc(sizeof(char) * (cols + 1));
        mapmalloc[i][cols] = '\0';
    }
    mapmalloc[rows] = NULL;
    return (mapmalloc);
}

char **malo(char *map)
{
    char **copymap;
    int cols = 0;
    int rows = 0;

    for (int i = 0; map[i] != '\n'; i++) {
        cols++;
    }
    for (int i = 0; map[i] != '\0'; i++) {
        if (map[i] == '\n')
            rows++;
    }
    copymap = mallocarray2d(rows, cols);
    return (copymap);
}

char **array2d(char *map, unsigned long size)
{
    char **copymap;
    int i = 0;
    int tmp = 0;

    copymap = malo(map);
    for (unsigned long p = 0, i = 0; map[p] != '\0' ; p++, i++) {
        for (int j = 0; map[p] != '\n' && p < size; p++, j++) {
            copymap[i][j] = map[p];
        }
    }
    return (copymap);
}
