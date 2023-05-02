/*
** EPITECH PROJECT, 2021
** comunication
** File description:
** 
*/

#include "include/navy.h"
#include <string.h>

char *static_msg(char *msg)
{
    static char ret[255];
    if(msg[0]!='\0')
        my_strcpy(ret, msg);
    return ret;
}

int static_status(int status)
{
    static int ret = 0;
    if (status != -1)
        ret = status;
    return ret;
}

void get_msg(int sig)
{
    static char buffer[255];
    static int i = 0;
    static int u1 = 0;
    static int u2 = 0;

    if (sig == SIGUSR1) {
        u1 += 1;
        u2 = 0;
    } else if (sig == SIGUSR2) {
        u2 +=1;
        if (u1 != 0) {
            buffer[i] = u1 + '0';
            i++;
            u1 = 0;
        }
        if (u2 == 2) {
                u1 = 0;
                u2 = 0;
                buffer[i] = '\0';
                i = 0;
                static_msg(buffer);
                static_status(1);
        }
    }
}

void wait_init(void)
{
    struct sigaction sig;
    sig.sa_handler = get_msg;
    sigemptyset(&sig.sa_mask);
    sig.sa_flags = 0;
    sigaction(SIGUSR1, &sig, NULL);
    sigaction(SIGUSR2, &sig, NULL);
}

char *wait_msg(void)
{
    char *msg;
    while(static_status(-1) != 1)
        usleep(5);
    msg = static_msg("");
    static_status(0);
    return msg;
}

void send_kill(int pid, int sig)
{
    usleep(5);
    kill(pid, sig);
    usleep(5);
}

void send_msg(int pid, char *msg)
{
    for(int i = 0; msg[i] != '\0'; i++) {
        for(int j = 1; j <= msg[i] - '0'; j++)
            send_kill(pid, SIGUSR1);
        send_kill(pid,SIGUSR2);
    }
    send_kill(pid, SIGUSR2);
}
