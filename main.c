/*
** EPITECH PROJECT, 2021
** navy
** File description:
** main for my_navy
*/

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include "include/navy.h"
#include <sys/stat.h>
#include <fcntl.h>

char *my_itos(pid_t p1)
{
    char *pid = malloc(sizeof(char) * 7);
    int tmp;
    int i;
    for (i = 0; p1 != 0; i++) {
        tmp = p1 % 10;
        pid[i] = tmp + '0';
        p1 = p1 / 10;
    }
    pid[i + 1] = '\0';
    pid = my_revstr(pid);
    return pid;
}

char my_itoc(int p1)
{
    char pid;
    int tmp;
    tmp = p1 % 10;
    pid = tmp + '0';
    return pid;
}

char **posse_batteaux(char **map, char **positions)
{
    int n_b = 2;
    for (int i = 0; positions[i] != NULL; i++, n_b++) {
        if (positions[i][2] == positions[i][5]) {
            int n_col = (positions[i][2] - 'A');
            for (int n_l = positions[i][3] - '0' - 1; n_l != positions[i][6] - '0'; n_l++) {
                map[n_l][n_col] = my_itoc(n_b);
            }
        } else {
            int n_l = (positions[i][3] - '0' - 1);
            for (int n_col = positions[i][2] - 'A' - 1; n_col != positions[i][5] - 'A'; n_col++) {
                map[n_l][n_col] = my_itoc(n_b);
            }
        }
    }
    return map;
}

char **init_tb_malloc(int rows, int cols)
{
    char **mapmalloc = malloc(sizeof(char *) * (rows + 1));
    for (int i = 0; i < rows; i++) {
        mapmalloc[i] = malloc(sizeof(char) * (cols + 1));
        mapmalloc[i][cols] = '\0';
    }
    mapmalloc[rows] = NULL;
    return (mapmalloc);
}

char **remplir2(void)
{
    char **map = init_tb_malloc(8, 8);
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            map[i][j] = '.';
    return (map);
}

char **remplir(char *av)
{
    char **map = init_tb_malloc(8, 8);
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            map[i][j] = '.';

    struct stat st;
    int fd = open(av, O_RDONLY);
    char *buffer = malloc(33 * sizeof(char));
    int rd = read(fd, buffer, 33);
    unsigned long size = 33 * sizeof(char);
    char **positions = array2d(buffer, size);

    map = posse_batteaux(map, positions);

    return (map);
}

void affiche_map(char **map)
{
    int j;
    my_putstr(" |A B C D E F G H\n-+---------------\n");
    for (int i = 1; map[i - 1] != NULL; i++) {
        my_put_nbr(i);
        my_putchar('|');
        for (j = 0; map[i - 1][j + 1] != '\0'; j++) {
            my_putchar(map[i - 1][j]);
            my_putstr(" ");
        }
        my_putchar(map[i - 1][j]);
        my_putstr("\n");
    }
    my_putstr("\n");
}

int check_msg(char *msg)
{
    if (my_strlen(msg) > 3 || my_strlen(msg) < 3)
        return -1;
    if (msg[1] < 49 || msg[1] > 56)
        return -1;
    if (msg[0] < 65 || msg[0] > 72)
        return -1;
}

my_map *maps_init(void)
{
    my_map *maps;
    maps = malloc(sizeof(my_map *));
    maps->map1 = remplir("pos1");
    maps->enemy1 = remplir2();
    maps->map2 = remplir("pos2");
    maps->enemy2 = remplir2();
    return maps;
}

int hit1(char *msg, my_map *map)
{
    if (map->map2[msg[1] - '0' - 1][msg[0] - 'A'] < 48 ||
        map->map2[msg[1] - '0' - 1][msg[0] - 'A'] > 55) {
        if (map->map2[msg[1] - '0' - 1][msg[0] - 'A'] == 'x' ||
            map->map2[msg[1] - '0' - 1][msg[0] - 'A'] == 'o')
            return -1;
        map->map2[msg[1] - '0' - 1][msg[0] - 'A'] = 'o';
        map->enemy1[msg[1] - '0' - 1][msg[0] - 'A'] = 'o';
        return -1;
    } else {
        if (map->map2[msg[1] - '0' - 1][msg[0] - 'A'] == 'x' ||
            map->map2[msg[1] - '0' - 1][msg[0] - 'A'] == 'o')
            return -1;
        map->enemy1[msg[1] - '0' - 1][msg[0] - 'A'] = 'x';
        map->map2[msg[1] - '0' - 1][msg[0] - 'A'] = 'x';
        return 1;
    }
}

int hit2(char *msg, my_map *map)
{
    if (map->map1[msg[1] - '0' - 1][msg[0] - 'A'] < 48 ||
        map->map1[msg[1] - '0' - 1][msg[0] - 'A'] > 55) {
        if (map->map1[msg[1] - '0' - 1][msg[0] - 'A'] == 'x' ||
            map->map1[msg[1] - '0' - 1][msg[0] - 'A'] == 'o')
            return -1;
        map->map1[msg[1] - '0' - 1][msg[0] - 'A'] = 'o';
        map->enemy2[msg[1] - '0' - 1][msg[0] - 'A'] = 'o';
        return -1;
    } else {
        if (map->map1[msg[1] - '0' - 1][msg[0] - 'A'] == 'x' ||
            map->map1[msg[1] - '0' - 1][msg[0] - 'A'] == 'o')
            return -1;
        map->enemy2[msg[1] - '0' - 1][msg[0] - 'A'] = 'x';
        map->map1[msg[1] - '0' - 1][msg[0] - 'A'] = 'x';
        return 1;
    }
}

int my_putstr_bizar(char const *str)
{
    int nb = 0;

    while (str[nb] != '\n') {
        my_putchar(str[nb]);
        nb++;
    }
    return (0);
}

int fini(char **map)
{
    int count = 0;
    for (int i = 0; map[i] != NULL; i++)
        for (int j = 0; map[i][j] != '\0'; j++)
            if (map[i][j] > 47 && map[i][j] < 58)
                count++;
    return count;
}

int main(int ac, char **av)
{
    if (error_handling(ac, av) == -1) {
        return 84;
    }

    pid_t player2;
    pid_t player1 = getpid();
    char *msg;
    char *line = NULL;
    size_t len = 0;
    my_map *maps = maps_init();

    wait_init();
    my_putstr("my_pid: ");
    my_put_nbr(player1);
    my_putstr("\n");
    if (ac == 3) {
        player2 = my_atoi(av[1]);
        char *str = my_itos(player1);
        send_msg(player2, str);
        free(str);
        my_putstr("successfully connected\n\n");
    } else {
        my_putstr("Waiting for enemy connection...\n\n");
        msg = wait_msg();
        player2 = my_atoi(msg);
    }
    do_game(ac, maps, msg, len, line, player2);
    free(maps);
    return 0;
}