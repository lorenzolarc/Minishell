/*
** EPITECH PROJECT, 2023
** cpool day07
** File description:
** my_getnbr.c
*/

int my_getnbr(char const *str)
{
    int res = 0;
    int sign = 1;

    if (str[0] == '-' || str[0] == '+') {
        sign = (str[0] == '-') ? -1 : 1;
        str++;
    }
    for (int index = 0; str[index] != '\0'; index++) {
        res = res * 10 + str[index] - '0';
    }
    return res * sign;
}
