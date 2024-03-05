/*
** EPITECH PROJECT, 2023
** cpool day04
** File description:
** my_put_nbr.c
*/

#include <unistd.h>

void show_nbr(int nb)
{
    if (nb >= 10) {
        show_nbr(nb / 10);
    }
    my_putchar('0' + (nb % 10));
}

void my_put_nbr(int nb)
{
    if (nb <= -2147483648) {
        my_putstr("-2147483648");
        return;
    }
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb == 0) {
        my_putchar('0');
    } else {
        show_nbr(nb);
    }
}
