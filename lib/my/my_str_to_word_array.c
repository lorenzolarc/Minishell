/*
** EPITECH PROJECT, 2024
** B-PSU-200-LYN-2-1-bsminishell1-lorenzo.la-rocca
** File description:
** my_str_to_word_array
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../../include/my.h"

static int len_tab(char *str)
{
    int nb = 0;

    for (int index = 0; str[index] != '\0'; index++) {
        if (str[index] == ' ' || str[index + 1] == '\0') {
            nb++;
        }
    }
    return nb;
}

static void len_word(int *index, char *str, char **tab, int fill)
{
    int temp = *index;
    int start = *index;
    int len = 0;

    while (str[temp] != '\0' && str[temp] != ' ' && str[temp] != '\n') {
        len++;
        temp++;
    }
    tab[fill] = (char *)malloc(sizeof(char) * (len + 1));
    tab[fill][len] = '\0';
    for (int ind = 0; start < temp; ind++) {
        tab[fill][ind] = str[start];
        start++;
    }
    *index = temp - 1;
}

char **my_str_to_word_array(char *str)
{
    int nb_words = len_tab(str);
    char **tab = (char **)malloc(sizeof(char *) * (nb_words + 1));
    int fill = 0;

    tab[nb_words] = NULL;
    for (int index = 0; str[index] != '\0'; index++) {
        if (str[index] != ' ' && str[index + 1] != '\0') {
            len_word(&index, str, tab, fill);
            fill++;
        }
    }
    return tab;
}
