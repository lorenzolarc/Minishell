/*
** EPITECH PROJECT, 2023
** cpool dya06
** File description:
** my_str_isprintable.c
*/

int my_str_isprintable(const char *str)
{
    if (*str == '\0') {
        return 1;
    }
    while (*str != '\0') {
        if ((*str < 32 && *str > 126)) {
            return 0;
        }
        str++;
    }
    return 1;
}
