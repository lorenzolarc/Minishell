/*
** EPITECH PROJECT, 2023
** cpool day05
** File description:
** my_find_prime_sup.c
*/

#include <stdio.h>

int my_find_prime_sup(int nb)
{
    while (my_is_prime(nb) != 1) {
        nb++;
    }
    return nb;
}
