/*
** EPITECH PROJECT, 2019
** my_ia.h
** File description:
** my_ia.h
*/

#ifndef my_ia_h
#define my_ia_h

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

typedef struct mouv {
    float array[32];
    double dist_mid;
} mouv_t;

int start_ai(mouv_t *mv);
char **my_str_to_wordarr(char *, char);
void my_putchar(char c);
void my_putnbr(int nb);
int my_strcmp(char *str, char *cmp);

static inline int check_end(char *str)
{
    char *buff = NULL;
    size_t bufsize = 0;

    if (!strcmp(str, "Track Cleared")) {
        dprintf(1, "CAR_FORWARD:0\n");
        if (getline(&buff, &bufsize, stdin) == -1)
            exit(1);
        dprintf(1, "STOP_SIMULATION\n");
        return (-1);
    }
    return (0);
}

#endif /* my_ia_h */
