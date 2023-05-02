/*
** EPITECH PROJECT, 2022
** game_end.c
** File description:
** functions that handle game end
*/

#include "navy.h"

int is_end(my_map *maps)
{
    if (fini(maps->map1) == 0) {
        my_putstr("my positions:\n");
        affiche_map(maps->map1);
        my_putstr("enemy's positions:\n");
        affiche_map(maps->enemy1);
        my_putstr("Enemy won\n");
        return 1;
    }
    if (fini(maps->map2) == 0) {
        my_putstr("my positions:\n");
        affiche_map(maps->map1);
        my_putstr("enemy's positions:\n");
        affiche_map(maps->enemy1);
        my_putstr("I won\n");
        return 1;
    }
    return 0;
}

int is_end_enemy(my_map *maps)
{
    if (fini(maps->map1) == 0) {
        my_putstr("my positions:\n");
        affiche_map(maps->map2);
        my_putstr("enemy's positions:\n");
        affiche_map(maps->enemy2);
        my_putstr("I won\n");
        return 1;
    }
    if (fini(maps->map2) == 0) {
        my_putstr("my positions:\n");
        affiche_map(maps->map2);
        my_putstr("enemy's positions:\n");
        affiche_map(maps->enemy2);
        my_putstr("Enemy won\n");
        return 1;
    }
    return 0;
}