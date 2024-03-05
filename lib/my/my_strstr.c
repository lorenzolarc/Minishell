/*
** EPITECH PROJECT, 2023
** cpool day06
** File description:
** my_strstr.c
*/

#include <unistd.h>

char *my_strstr(char *str, const char *to_find)
{
    char *str_tmp;
    const char *to_find_tmp;

    if (*to_find == '\0') {
        return str;
    }
    while (*str != '\0') {
        str_tmp = str;
        to_find_tmp = to_find;
        while (*str_tmp == *to_find_tmp && *to_find_tmp != '\0') {
            str_tmp++;
            to_find_tmp++;
        }
        if (*to_find_tmp == '\0') {
            return str;
        }
        str++;
    }
    return NULL;
}
