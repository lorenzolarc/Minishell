/*
** EPITECH PROJECT, 2023
** cpool day06
** File description:
** my_strupcase.c
*/

char *my_strupcase(char *str)
{
    for (int index = 0; index < my_strlen(str); index++) {
        if (str[index] >= 97 && str[index] <= 122) {
            str[index] -= 32;
        }
    }
    return str;
}
