/*
** EPITECH PROJECT, 2022
** game_start.c
** File description:
** start game functions
*/

#include "navy.h"

static void start_player_game(my_map *maps, char *msg, size_t len, char *line, pid_t player2)
{
    my_putstr("enemy connected\n\n");
    while (1) {
        my_putstr("my positions:\n");
        affiche_map(maps->map1);
        my_putstr("enemy's positions:\n");
        affiche_map(maps->enemy1);
        player_do_attack(maps, len, line, player2);
        if (is_end(maps) == 1)
            break;
        player_attack_handling(maps, msg);
    }
}

static void start_enemy_game(my_map *maps, char *msg, size_t len, char *line, pid_t player2)
{
    while (1) {
        msg = put_enemy(maps, msg);
        if (hit1(msg, maps) == 1)
            my_putstr(": hit\n\n");
        else
            my_putstr(": missed\n\n");
        if (is_end_enemy(maps) == 1)
            break;
        enemy_do_attack(maps, len, line, player2);
    }
}

void do_game(int ac, my_map *maps, char *msg, size_t len, char *line, pid_t player2)
{
    if(ac == 3) {
        start_enemy_game(maps, msg, len, line, player2);
    } else {
        start_player_game(maps, msg, len, line, player2);
    }
}
