/*
** EPITECH PROJECT, 2024
** B-PSU-200-LYN-2-1-minishell1-lorenzo.la-rocca
** File description:
** env
*/

#include "../include/my.h"
#include "../include/minishell1.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

static int my_lentab(char **tab)
{
    int len = 0;

    while (tab[len] != NULL)
        len++;
    return len;
}

static int is_alpha(char letter)
{
    if (letter >= 'a' && letter <= 'z')
        return 1;
    if (letter >= 'A' && letter <= 'Z')
        return 1;
    return 0;
}

static int is_alpha_num(char letter)
{
    if (letter == '*')
        return 0;
    if (letter == '_')
        return 1;
    if (letter >= 'a' && letter <= 'z')
        return 1;
    if (letter >= 'A' && letter <= 'Z')
        return 1;
    if (letter >= '0' && letter <= '9')
        return 1;
    return 0;
}

void my_putenv(char **args, char **env)
{
    int index = 0;
    char *temp = search_env(env[index]);

    while (env[index] != NULL && my_strcmp(args[1], temp) != 0) {
        temp = search_env(env[index]);
        if (my_strcmp(args[1], temp) == 0)
            break;
        index++;
    }
    env[index] = args[1];
    env[index][my_strlen(args[1])] = '=';
    if (args[2] != NULL)
        my_strcat(env[index], args[2]);
    env[index + 1] = NULL;
}

char *search_env(char *env)
{
    int index = 0;
    char *temp;

    while (env[index] != '=' && env[index] != '\0') {
        index++;
    }
    temp = (char *)malloc(sizeof(char) * (index + 1));
    temp[index] = '\0';
    for (int cur = 0; cur < index; cur++) {
        temp[cur] = env[cur];
    }
    return temp;
}

static void my_rmenv(char **args, char **env, int nb)
{
    int index = 0;
    char *temp = search_env(env[0]);

    while (my_strcmp(args[nb], temp) != 0 && env[index] != NULL) {
        temp = search_env(env[index]);
        if (my_strcmp(args[nb], temp) == 0)
            break;
        index++;
    }
    if (env[index] == NULL) {
        return;
    }
    env[index] = "";
}

static int check_value(char **args)
{
    if (my_lentab(args) > 3) {
        my_printf("setenv: Too many arguments.\n");
        return 1;
    }
    if (args[2] == NULL)
        return 0;
    return 0;
}

int set_env(char **args, char **env)
{
    if (args[1] == NULL)
        return disp_env(env, args);
    if (is_alpha(args[1][0]) == 0 && args[1][0] != '_') {
        my_printf("setenv: Variable name must begin with a letter.\n");
        return 1;
    }
    for (int index = 0; args[1][index] != '\0'; index++) {
        if (is_alpha_num(args[1][index]) == 0) {
            my_printf("setenv: Variable name must contain ");
            my_printf("alphanumeric characters.\n");
            return 1;
        }
    }
    if (check_value(args) == 1)
        return 1;
    my_putenv(args, env);
    return 0;
}

int disp_env(char **env, char **args)
{
    if (args[1] != NULL) {
        my_printf("%s: '%s': No such file or directory\n", args[0], args[1]);
        return 127;
    }
    for (int index = 0; env[index] != NULL; index++) {
        if (my_strcmp(env[index], "") == 0)
            continue;
        my_printf("%s\n", env[index]);
    }
    return 0;
}

int unset_env(char **args, char **env)
{
    if (my_lentab(args) < 2) {
        my_printf("unsetenv: Too few arguments.\n");
        return 1;
    }
    for (int nb = 1; (my_lentab(args) - 1) >= nb; nb++)
        my_rmenv(args, env, nb);
    return 0;
}
