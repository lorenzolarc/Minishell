/*
** EPITECH PROJECT, 2023
** cpool day07
** File description:
** my_strncat.c
*/

char *my_strncat(char *dest, char const *src, int nb)
{
    int lendest = my_strlen(dest);
    int index = 0;

    while (src[index] != '\0' && index < nb) {
        dest[lendest + index] = src[index];
        index++;
    }
    dest[lendest + index] = '\0';
    return dest;
}
