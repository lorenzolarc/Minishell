/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** check_flags.c
*/

#include <stdarg.h>
#include "../../include/my.h"

int check_dspo(const char *format, int index, int len, va_list list)
{
    switch (format[index]) {
    case 'd':
        print_d(format, len, index, list);
        return index;
    case 's':
        print_s(format, len, index, list);
        return index;
    case '%':
        print_p(format, len, index, list);
        return index;
    case 'o':
        octal_type(format, len, index, list);
        return index;
    default:
        return index;
    }
}

int check_ciux(const char *format, int index, int len, va_list list)
{
    switch (format[index]) {
    case 'c':
        print_c(format, len, index, list);
        return index;
    case 'i':
        print_i(format, len, index, list);
        return index;
    case 'u':
        unsigned_type(va_arg(list, int));
        return index;
    case 'x':
        hexadecimal(va_arg(list, unsigned int), 1);
        return index;
    case 'X':
        hexadecimal(va_arg(list, unsigned int), 0);
        return index;
    default:
        return index;
    }
}

int check_fgp(const char *format, int index, int len, va_list list)
{
    switch (format[index]) {
    case 'f':
        print_float(va_arg(list, double));
        return index;
    case 'g':
        print_e(va_arg(list, double));
        return index;
    case 'G':
        print_e(va_arg(list, double));
        return index;
    case 'p':
        print_pointer(va_arg(list, void *));
        return index;
    default:
        return index;
    }
}

int check_en(const char *format, int index, int len, va_list list)
{
    int *PointerOnN = NULL;

    switch (format[index]) {
    case 'e':
        print_e(va_arg(list, double));
        return index;
    case 'E':
        print_e(va_arg(list, double));
        return index;
    case 'n':
        PointerOnN = va_arg(list, void *);
        *PointerOnN = 4;
        return index;
    case 'F':
        print_float(va_arg(list, double));
        return index;
    default:
        return index;
    }
}
