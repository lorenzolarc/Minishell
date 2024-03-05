/*
** EPITECH PROJECT, 2023
** cpool day06
** File description:
** my_str_isnum.c
*/

int my_str_isnum(const char *str)
{
    if (*str == '\0') {
        return 1;
    }
    while (*str != '\0') {
        if (!(*str >= '0' && *str <= '9')) {
            return 0;
        }
        str++;
    }
    return 1;
}
