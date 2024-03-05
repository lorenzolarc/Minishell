/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** flag_ou.c
*/

#include <stdarg.h>
#include "../../include/my.h"

int octal_type(const char *format, int len, int index, va_list list)
{
    unsigned int a;
    int b = 0;
    unsigned int oc_res[100];

    a = va_arg(list, unsigned int);
    while (a != 0) {
        oc_res[b] = a % 8;
        a = a / 8;
        b++;
    }
    b--;
    while (b >= 0) {
        my_put_nbr(oc_res[b]);
        b--;
    }
    return 0;
}

void my_put_signed_nbr(int nb)
{
    if (nb < 0) {
        nb = -nb;
    }
    if (nb >= 10) {
        my_put_signed_nbr(nb / 10);
    }
    my_putchar(nb % 10 + '0');
}

static void my_put_unsigned_nbr(unsigned int nb)
{
    if (nb >= 10) {
        my_put_unsigned_nbr(nb / 10);
    }
    my_putchar(nb % 10 + '0');
}

void unsigned_type(int *nb)
{
    if (nb > 2147483647) {
        my_put_unsigned_nbr(nb);
    } else {
        my_put_signed_nbr(nb);
    }
}

static void show(char *hexadec, int decount, int flag, int count)
{
    decount = count - 1;
    while (decount >= 0) {
        if (hexadec[decount] >= 'A' && hexadec[decount] <= 'F'
        && flag == 1) {
            my_putchar(hexadec[decount] + 32);
        } else {
            my_putchar(hexadec[decount]);
        }
        decount--;
    }
}

void hexadecimal(unsigned int nb, int flag)
{
    char hexadec[100];
    int decount;
    int count = 0;
    int mem;

    if (nb == 0) {
        my_putchar('0');
    }
    while (nb != 0) {
        mem = nb % 16;
        if (mem < 10) {
            hexadec[count] = mem + 48;
        } else {
            hexadec[count] = mem + 55;
        }
        count++;
        nb = nb / 16;
    }
    show(hexadec, decount, flag, count);
}
