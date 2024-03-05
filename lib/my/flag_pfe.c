/*
** EPITECH PROJECT, 2023
** my_printf.c
** File description:
** flag_p.c
*/

#include <stdarg.h>
#include "../../include/my.h"

static void show_long(char *hexadec, int decount, int count)
{
    decount = count - 1;
    while (decount >= 0) {
        if (hexadec[decount] >= 'A' && hexadec[decount] <= 'F') {
            my_putchar(hexadec[decount] + 32);
        } else {
            my_putchar(hexadec[decount]);
        }
        decount--;
    }
}

static void hexadecimal_long(unsigned long nb)
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
    show_long(hexadec, decount, count);
}

static void show_float(int upper, int prec, int defaut, int whole)
{
    char str[defaut];

    if (upper >= 5 && upper <= 9) {
        prec++;
    }
    my_put_nbr(whole);
    my_putchar('.');
    for (int count = 1; count < defaut; count++) {
        upper = prec % 10;
        prec = prec / 10;
        str[count] = upper;
    }
    for (int count = defaut - 1; count > 0; count--) {
        my_put_nbr(str[count]);
    }
}

static void error_float_handling(double nb, int defaut)
{
    my_putstr("0.");
    for (int count = 0; count < defaut - 1; count++) {
        my_put_nbr(0);
    }
}

void print_float(double nb)
{
    int whole;
    int prec;
    int defaut = 7;
    int virg = 1;
    int upper;

    if ((int)nb == 0) {
        error_float_handling(nb, defaut);
        return;
    }
    for (int count = 0; count < defaut; count++) {
        virg *= 10;
    }
    whole = (nb / 1);
    nb = nb - whole;
    prec = (nb * virg);
    upper = prec % 10;
    prec = prec / 10;
    show_float(upper, prec, defaut, whole);
}

void print_pointer(void *addr)
{
    my_putstr("0x");
    hexadecimal_long(addr);
}

void show_float_modified(int upper, int prec, int defaut)
{
    char str[defaut];

    if (upper >= 5 && upper <= 9) {
        prec++;
    }
    for (int count = 1; count < defaut; count++) {
        upper = prec % 10;
        prec = prec / 10;
        str[count] = upper;
    }
    for (int count = defaut - 1; count > 0; count--) {
        my_put_nbr(str[count]);
    }
}

void static print_float_modified(double nb, int defaut)
{
    int whole;
    int prec;
    int virg = 1;
    int upper;

    if ((int)nb == 0) {
        error_float_handling(nb, defaut);
        return;
    }
    for (int count = 0; count < defaut; count++) {
        virg *= 10;
    }
    whole = (nb / 1);
    nb = nb - whole;
    prec = (nb * virg);
    upper = prec % 10;
    prec = prec / 10;
    show_float_modified(upper, prec, defaut);
}

void compute_after_dec(int exp, int whole)
{
    for (int count = 1; count < exp; count++) {
        whole %= 100;
        my_put_nbr(whole);
    }
}

void print_e(double nb)
{
    int whole = (nb / 1);
    int exp = my_count_int(whole);
    int new = whole;
    int digits = 0;

    for (int count = exp; count > 0; count--) {
        new /= 10;
        digits++;
    }
    my_put_nbr(new);
    my_putchar('.');
    compute_after_dec(exp, whole);
    print_float_modified(nb, digits);
    my_putstr("e+");
    if (digits >= 0 && digits <= 9) {
        my_put_nbr(0);
    }
    my_put_nbr(digits);
}
