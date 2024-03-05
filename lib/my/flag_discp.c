/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** flag_discp.c
*/

#include <stdarg.h>
#include "../../include/my.h"

void print_d(const char *format, int len, int index, va_list list)
{
    int temp;

    temp = va_arg(list, int);
    my_put_nbr(temp);
}

void print_i(const char *format, int len, int index, va_list list)
{
    int temp;

    temp = va_arg(list, int);
    my_put_nbr(temp);
}

void print_c(const char *format, int len, int index, va_list list)
{
    char *str;

    str = va_arg(list, char *);
    my_putchar(str);
}

void print_s(const char *format, int len, int index, va_list list)
{
    char *str;

    str = va_arg(list, char *);
    my_putstr(str);
}

void print_p(const char *format, int len, int index, va_list list)
{
    my_putchar('%');
}
