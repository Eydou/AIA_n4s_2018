/*
** EPITECH PROJECT, 2019
** need4steck
** File description:
** main
*/

#include "my_ia.h"

mouv_t *init_struct_mouv(mouv_t *mv)
{
    mv = malloc(sizeof(mouv_t));
    mv->dist_mid = 0;
    return (mv);
}

int main(int ac, char **av)
{
    (void)ac;
    (void)av;
    mouv_t *mv = NULL;
    char *str;
    size_t bufsize = 0;

    dprintf(1, "START_SIMULATION\n");
    mv = init_struct_mouv(mv);
    if (getline(&str, &bufsize, stdin) == -1)
        exit(1);
    check_end(str) == -1 ? exit(0) : 0;
    start_ai(mv) == -1 ? exit(84) : 0;

    return (0);
}
