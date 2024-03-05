/*
** EPITECH PROJECT, 2023
** cpool day04
** File description:
** my_swap.c
*/

void my_swap(int *a, int *b)
{
    int temp1 = *a;
    int temp2 = *b;

    *a = temp2;
    *b = temp1;
}
