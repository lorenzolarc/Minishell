/*
** EPITECH PROJECT, 2023
** cpool day04
** File description:
** my_putstr.c
*/

#include <unistd.h>

int my_putstr(char const *str)
{
    char current;

    for (int index = 0; str[index] != '\0'; index++) {
        current = str[index];
        write(1, &current, 1);
    }
    return 0;
}
