/*
** EPITECH PROJECT, 2023
** cpool day06
** File description:
** my_strncpy.c
*/

#include <unistd.h>

char *my_strncpy(char *dest, char const *src, int n)
{
    int len = my_strlen(src);
    char temp;

    for (int index = 0; index < n; index++) {
        temp = src[index];
        dest[index] = temp;
        if (n > len && index >= len) {
            dest[index] = '\0';
            return dest;
        }
    }
    return dest;
}
