/*
** EPITECH PROJECT, 2023
** cpool day07
** File description:
** my_strcat.c
*/

#include "../../include/my.h"

char *my_strcat(char *dest, char const *src)
{
    int lendest = my_strlen(dest);
    int index;

    for (index = 0; src[index] != '\0'; index++) {
        dest[lendest + index] = src[index];
    }
    dest[lendest + index] = '\0';
    return dest;
}
