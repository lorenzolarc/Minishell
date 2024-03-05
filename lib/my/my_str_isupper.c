/*
** EPITECH PROJECT, 2023
** cpool day06
** File description:
** my_str_isupper.c
*/

int my_str_isupper(const char *str)
{
    if (*str == '\0') {
        return 1;
    }
    while (*str != '\0') {
        if ((*str >= 'a' && *str <= 'z')) {
            return 0;
        }
        str++;
    }
    return 1;
}
