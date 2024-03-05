/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** my_printf.c
*/

#include <stdarg.h>
#include "../../include/my.h"
#include <stdio.h>

int my_count_int(double nb)
{
    int count = 0;

    while (1) {
        if (nb < 0) {
            nb = -nb;
            count++;
        }
        if (nb >= 0 && nb <= 9) {
            return count + 1;
        }
        count++;
        nb = nb / 10;
    }
}

static int check_space(const char *format, int index, int len, va_list list)
{
    while (format[index] == ' ') {
        index++;
    }
    return index;
}

int call_flags(const char *format, int index, int len, va_list list)
{
    if (format[index] == '%') {
        index++;
        index = check_space(format, index, len, list);
        index = check_ciux(format, index, len, list);
        index = check_dspo(format, index, len, list);
        index = check_fgp(format, index, len, list);
        index = check_en(format, index, len, list);
    } else {
        my_putchar(format[index]);
    }
    return index;
}

int my_printf(const char *format, ...)
{
    int lenfrmt = my_strlen(format);
    int len = 0;
    va_list list;

    if (lenfrmt <= 0) {
        return;
    }
    va_start(list, format);
    for (int index = 0; index <= lenfrmt - 1; index++) {
        index = call_flags(format, index, len, list);
    }
    va_end(list);
    return len;
}
