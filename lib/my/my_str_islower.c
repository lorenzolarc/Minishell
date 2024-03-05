/*
** EPITECH PROJECT, 2023
** cpool day06
** File description:
** my_str_islower.c
*/

int my_str_islower(const char *str)
{
    if (*str == '\0') {
        return 1;
    }
    while (*str != '\0') {
        if ((*str >= 'A' && *str <= 'Z')) {
            return 0;
        }
        str++;
    }
    return 1;
}
