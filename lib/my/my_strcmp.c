/*
** EPITECH PROJECT, 2023
** cpool day06
** File description:
** my_strcmp.c
*/

#include <unistd.h>
#include "../../include/my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int lens1 = my_strlen(s1);
    int lens2 = my_strlen(s2);
    int i;

    for (i = 0; i < lens1 && i < lens2; i++) {
        if (s1[i] != s2[i])
            return (s1[i] > s2[i]) ? 1 : -1;
    }
    if (lens1 == lens2)
        return 0;
    else
        return (lens1 > lens2) ? 1 : -1;
}
