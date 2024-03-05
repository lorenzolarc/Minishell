/*
** EPITECH PROJECT, 2023
** cpool day03
** File description:
** my_isneg.c
*/

#include <unistd.h>

int my_isneg(int n)
{
    if (n < 0) {
        write(1, "N", 1);
    } else {
        write(1, "P", 1);
    }
    return 0;
}
