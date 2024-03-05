/*
** EPITECH PROJECT, 2023
** cpool day06
** File description:
** my_strlowcase.c
*/

char *my_strlowcase(char *str)
{
    for (int index = 0; index < my_strlen(str); index++) {
        if (str[index] >= 65 && str[index] <= 90) {
            str[index] -= 32;
        }
    }
    return str;
}
