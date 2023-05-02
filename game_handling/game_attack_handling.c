/*
** EPITECH PROJECT, 2022
** game_attack_handling
** File description:
** functions that handle attacks in navy
*/

#include <stdio.h>
#include "navy.h"

void verify_if_hit(char *line, my_map *maps, int hit)
{
    if (hit == 1) {
        if (hit1(line, maps) == 1)
            my_putstr(": hit\n\n");
        else
            my_putstr(": missed\n\n");
    } else {
        if (hit2(line, maps) == 1)
            my_putstr(": hit\n\n");
        else
            my_putstr(": missed\n\n");
    }
}

void player_attack_handling(my_map *maps, char *msg)
{
    my_putstr("waiting for enemy's attack...\n");
    msg = wait_msg();
    my_putstr(msg);
    if (hit2(msg, maps) == 1)
        my_putstr(": hit\n\n");
    else
        my_putstr(": missed\n\n");
}

void player_do_attack(my_map *maps, size_t len, char *line, pid_t player2)
{
    while (1) {
        usleep(100);
        my_putstr("attack: ");
        usleep(1);
        getline(&line, &len, stdin);
        if (check_msg(line) == -1)
            my_putstr("wrong position\n");
        else {
            my_putstr_bizar(line);
            send_msg(player2, line);
            if (hit1(line, maps) == 1)
                my_putstr(": hit\n\n");
            else
                my_putstr(": missed\n\n");
            break;
        }
    }
    // while (1) {
    //     usleep(100);
    //     my_putstr("attack: ");
    //     usleep(1);
    //     getline(&line, &len, stdin);
    //     if (check_msg(line) == -1)
    //         my_putstr("wrong position\n");
    //     else {
    //         my_putstr_bizar(line);
    //         send_msg(player2, line);
    //         verify_if_hit(line, maps, 1);
    //         break;
    //     }
    // }
}

void enemy_do_attack(my_map *maps, size_t len, char *line, pid_t player2)
{
    while (1) {
        usleep(100);
        my_putstr("attack: ");
        usleep(1);
        getline(&line, &len, stdin);
        if (check_msg(line) == -1)
            my_putstr("wrong position\n");
        else {
            my_putstr_bizar(line);
            send_msg(player2, line);
            verify_if_hit(line, maps, 2);
            break;
        }
    }
}