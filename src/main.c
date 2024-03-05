/*
** EPITECH PROJECT, 2024
** B-PSU-200-LYN-2-1-minishell1-lorenzo.la-rocca
** File description:
** main
*/

#include "../include/my.h"
#include "../include/minishell1.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void check_backslash(char *str)
{
    for (int index = 0; str[index] != '\0'; index++) {
        if (str[index] == '\\') {
            str[index] = ' ';
            str[index + 1] = ' ';
        }
        if (str[index] == '	') {
            str[index] = ' ';
        }
    }
}

int show_sh(int ac, char **av, char **env)
{
    size_t bufsize = 131073;
    char *buffer = (char *)malloc(bufsize * sizeof(char));
    char *pwd = (char *)malloc(sizeof(char) * 4096);
    char **args;
    size_t size;

    while (1) {
        my_printf("$> ");
        size = getline(&buffer, &bufsize, stdin);
        if (size == -1) {
            my_putchar('\n');
            exit(0);
        }
        buffer[size] = '\0';
        check_backslash(buffer);
        args = my_str_to_word_array(buffer);
        if (size >= 2)
            parsing(args, env, pwd);
    }
    free(buffer);
}

static int for_no_tty(char **env)
{
    char **args;
    char *buffer;
    size_t buffer_size;
    char *pwd = (char *)malloc(sizeof(char) * 4096);
    size_t size;
    int ret = 0;

    for (size = getline(&buffer, &buffer_size, stdin);
    size != -1; size = getline(&buffer, &buffer_size, stdin)) {
        if (size <= 1)
            return 0;
        buffer[size] = '\0';
        check_backslash(buffer);
        args = my_str_to_word_array(buffer);
        ret = parsing_tty(args, env, pwd);
    }
    return ret;
}

int main(int ac, char **av, char **env)
{
    if (ac != 1)
        return 84;
    if (!isatty(STDIN_FILENO)) {
        return for_no_tty(env);
    }
    show_sh(ac, av, env);
}
