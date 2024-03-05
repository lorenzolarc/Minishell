/*
** EPITECH PROJECT, 2023
** cpool day05
** File description:
** my_is_prime.c
*/

int my_is_prime(int nb)
{
    if (nb <= 1) {
        return 0;
    }
    for (int number = 2; number <= nb / 2; number++) {
        if (nb % number == 0) {
            return 0;
        }
    }
    return 1;
}
