/*
** EPITECH PROJECT, 2019
** start_ai.c
** File description:
** strat_ai.
*/

#include "my_ia.h"

static void set_speed(mouv_t *mv)
{
    char *str = NULL;
    size_t bufsize = 0;
    float mid_dist[7] = {2000, 1500, 1000, 600, 400, 100, 75};
    char *speed[7] = {"1\n", "0.8\n", "0.6\n", "0.4\n", "0.2\n",
    "0.1\n", "0.3\n"};

    mv->dist_mid <= 75 ? dprintf(1, "CAR_BACKWARDS:") :
    dprintf(1, "CAR_FORWARD:");
    for (int i = 0; i != 7; i++) {
        if (mv->dist_mid >= mid_dist[i]) {
            dprintf(1, speed[i]);
            break;
        }
    }
    getline(&str, &bufsize, stdin) == -1 ? exit(1) : 0;
    check_end(str) == -1 ? exit(0) : 0;
}

static void set_direction(mouv_t *mv)
{
    float dir = mv->array[0] - mv->array[31];
    char *str = NULL;
    size_t bufsize = 0;
    float mid_dist[7] = {1500, 1000, 600, 400, 300, 200, 100};
    char *set_dir[7] = {"0.01\n", "0.1\n", "0.15\n", "0.25\n", "0.4\n",
    "0.5\n", "0.75\n"};

    dprintf(1, "WHEELS_DIR:");
    dir < 0 ? dprintf(1, "-") : 0;
    for (int i = 0; i != 7; i++) {
        if (mv->dist_mid >= mid_dist[i]) {
            dprintf(1, set_dir[i]);
            break;
        }
    }
    getline(&str, &bufsize, stdin) == -1 ? exit(1) : 0;
    check_end(str) == -1 ? exit(0) : 0;
}

static void get_info(mouv_t *mv)
{
    char *str = NULL;
    char **array = NULL;
    size_t bufsize = 0;

    write(1, "GET_INFO_LIDAR\n", 15);
    getline(&str, &bufsize, stdin) == -1 ? exit(1) : 0;
    array = my_str_to_wordarr(str, ':');
    if (!array[0] || !array[1] || !array[2])
        return;
    for (int i = 0; i != 32; i++) {
        if (!array[i + 3])
            return;
        mv->array[i] = atof(array[i + 3]);
    }
    mv->dist_mid = mv->array[15];
    check_end(str) == -1 ? exit(0) : 0;
}

int start_ai(mouv_t *mv)
{
    while (1) {
        get_info(mv);
        set_direction(mv);
        get_info(mv);
        set_speed(mv);
    }
    return (0);
}
