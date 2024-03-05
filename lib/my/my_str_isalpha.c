/*
** EPITECH PROJECT, 2023
** cpool day06
** File description:
** my_str_isalpha.c
*/

int my_str_isalpha(char const *str)
{
    if (*str == '\0') {
        return 1;
    }
    while (*str != '\0') {
        if (!(*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z')) {
            return 0;
        }
        str++;
    }
    return 1;
}
