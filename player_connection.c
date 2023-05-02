/*
** EPITECH PROJECT, 2021
** player_connection.c
** File description:
** functions that handle player connection in navy
*/

#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "navy.h"

char *put_enemy(my_map *maps, char *msg)
{
    my_putstr("my positions:\n");
    affiche_map(maps->map2);
    my_putstr("enemy's positions:\n");
    affiche_map(maps->enemy2);
    my_putstr("waiting for enemy's attack...\n");
    msg = wait_msg();
    my_putstr(msg);
    return msg;
}
