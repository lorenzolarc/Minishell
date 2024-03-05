/*
** EPITECH PROJECT, 2023
** cpool day06
** File description:
** my_strncmp.c
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int lens1 = my_strlen(s1);
    int lens2 = my_strlen(s2);

    if (n <= 0) {
        return 0;
    }
    for (int index = 0; index < n; index++) {
        if (lens1 > lens2) {
            return 1;
        }
        if (lens1 == lens2) {
            return 0;
        }
        if (lens1 < lens2) {
            return -1;
        }
    }
}
