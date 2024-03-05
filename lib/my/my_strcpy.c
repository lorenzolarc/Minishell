/*
** EPITECH PROJECT, 2023
** cpool day06
** File description:
** my_strcpy.c
*/

#include <unistd.h>
#include <stdio.h>

char *my_strcpy(char *dest, char const *src)
{
    int len = my_strlen(src);
    char temp;

    for (int index = 0; index <= len; index++) {
        temp = src[index];
        dest[index] = temp;
    }
    return dest;
}
