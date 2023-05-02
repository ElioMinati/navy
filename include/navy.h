/*
** EPITECH PROJECT, 2021
** navy header
** File description:
** function prototypes for navy
*/

#ifndef NAVY_H_
# define NAVY_H_
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

int my_atoi(char *str);

int my_strcmp(char const *s1, char const *s2);

int my_putstr(char *str);

void my_putchar(char c);

int my_put_nbr(int nb);

int my_strlen(char const *str);

int error_handling(int ac, char **av);

char *static_msg(char *msg);

int static_status(int status);

void get_msg(int sig);

void wait_init();

char *wait_msg();

void send_msg(int pid, char *msg);

char **array2d(char *map, unsigned long size);

char *my_revstr(char *str);

typedef struct {
    char **map1;
    char **enemy1;
    char **map2;
    char **enemy2;
} my_map;

char *my_strcpy(char *dest, char const *src);

void do_game(int ac, my_map *maps, char *msg, size_t len, char *line, pid_t player2);

int is_end(my_map *maps);

int is_end_enemy(my_map *maps);

char *put_enemy(my_map *maps, char *msg);

#endif /* !NAVY_H_ */
