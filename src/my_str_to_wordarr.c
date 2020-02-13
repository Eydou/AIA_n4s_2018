/*
** EPITECH PROJECT, 2019
** my_str_to_wordarr.c
** File description:
** my_str_to_word_array.
*/

#include "my_ia.h"

static int count_len(char *str, char c, int i)
{
    int len;

    for (len = 0; str[i] && str[i] != c; i++)
        len++;
    return (len);
}

static int count_arg(char *str, char c)
{
    int count = 1;

    for (int i = 0; str[i]; i++)
        str[i] == c ? count++ : 0;
    return (count);
}

char **my_str_to_wordarr(char *str, char c)
{
    char **arr = malloc(sizeof(char *) * count_arg(str, c));
    int j = 0;
    int k = 0;

    for (int i = 0; str[i]; j++) {
        arr[j] = malloc(sizeof(char) * count_len(str, c, i) + 1);
        for (k = 0; str[i] && str[i] != c; i++, k++)
            arr[j][k] = str[i];
        while (str[i] == c)
            i++;
        arr[j][k] = '\0';
    }
    return (arr);
}
