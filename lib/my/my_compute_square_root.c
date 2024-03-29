/*
** EPITECH PROJECT, 2023
** cpool day05
** File description:
** my_compute_square_root.c
*/

int my_compute_square_root(int nb)
{
    if (nb <= 0) {
        return 0;
    }
    for (int res = 1; res * res <= nb; res++) {
        if (res * res == nb) {
            return res;
        }
    }
    return 0;
}
