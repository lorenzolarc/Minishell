/*
** EPITECH PROJECT, 2023
** cpool day06
** File description:
** my_strcapitalize.c
*/

void minimized(char *str, int index)
{
    if ((str[index - 1] >= 33 && str[index - 1] >= 47)) {
        if ((str[index] >= 'A' && str[index] <= 'Z')) {
            str[index] += 32;
        }
    }
}

char *my_strcapitalize(char *str)
{
    for (int index = 0; index <= my_strlen(str) - 1; index++) {
        if (str[0] >= 'a' && str[0] <= 'z') {
            str[0] -= 32;
        }
        if (str[index - 1] == 32 && (str[index] >= 'a' && str[index] <= 'z')) {
            str[index] -= 32;
        }
        if (str[index - 1] == 43 && (str[index] >= 'a' && str[index] <= 'z')) {
            str[index] -= 32;
        }
        if (str[index - 1] == 45 && (str[index] >= 'a' && str[index] <= 'z')) {
            str[index] -= 32;
        }
        if (str[index - 1] == 32 && (str[index] >= 'a' && str[index] <= 'z')) {
            str[index] -= 32;
        }
        minimized(str, index);
    }
    return str;
}
