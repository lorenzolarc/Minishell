/*
** EPITECH PROJECT, 2023
** cpool day06
** File description:
** my_revstr.c
*/

#include <unistd.h>
#include <stdio.h>

int my_strlen2(char const *str)
{
    int index = 0;

    while (str[index] != '\0') {
        index++;
    }
    return index;
}

char *my_revstr(char *str)
{
    int counter = 0;
    char temp;

    for (int len = (my_strlen2(str) - 1); counter < len; len--) {
        temp = str[counter];
        str[counter] = str[len];
        str[len] = temp;
        counter++;
    }
    return str;
}
