/*
** EPITECH PROJECT, 2023
** cpool day04
** File description:
** my_strlen.c
*/

int my_strlen(char const *str)
{
    int index = 0;

    while (str[index] != '\0') {
        index++;
    }
    return index;
}
