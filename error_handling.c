/*
** EPITECH PROJECT, 2021
** error_handling
** File description:
** error handling for navy
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "navy.h"

int check_number_and_size_of_boat(char *buffer)
{
    int count_2 = 0;
    int count_3 = 0;
    int count_4 = 0;
    int count_5 = 0;

    for (int i = 0; i < 33; i += 8) {
        if (buffer[i] == '2')
            count_2++;
        if (buffer[i] == '3')
            count_3++;
        if (buffer[i] == '4')
            count_4++;
        if (buffer[i] == '5')
            count_5++;
    }
    if (count_2 == count_3 && count_3 == count_4 &&
    count_4 == count_5 && count_5 != 0)
        return 0;
    return -1;
}

static int check_boat_pos(char *buffer)
{
    if (check_number_and_size_of_boat(buffer) == -1)
        return -1;
    if (my_strlen(buffer) != 32)
        return -1;
    return 0;
}

static int is_valid_file(int ac, char **av)
{
    char *buffer;
    int rd;
    int fd;
    int stt;
    struct stat st;

    if (ac == 2) {
        fd = open(av[1], O_RDONLY);
    } else {
        fd = open(av[2], O_RDONLY);
    }
    if (fd == -1)
        return -1;
    buffer = malloc(st.st_size * sizeof(char));
    rd = read(fd, buffer, st.st_size);
    if (rd == -1)
        return -1;
    if (check_boat_pos(buffer) == -1)
        return -1;
    close(fd);
    return 0;
}

static int incorrect_nb_of_params(int ac)
{
    if (ac != 2 && ac != 3)
        return 1;
    return 0;
}

int error_handling(int ac, char **av)
{
    if (incorrect_nb_of_params(ac) == 1) {
        my_putstr("ERROR: Invalid number of parameters\n");
        return -1;
    }
    if (is_valid_file(ac, av) == -1) {
        my_putstr("ERROR: Invalid configuration file\n");
        return -1;
    }
    return 0;
}