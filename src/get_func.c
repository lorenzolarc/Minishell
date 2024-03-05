/*
** EPITECH PROJECT, 2024
** B-PSU-200-LYN-2-1-minishell1-lorenzo.la-rocca
** File description:
** get_func
*/

#include "../include/my.h"
#include "../include/minishell1.h"
#include <asm-generic/errno-base.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

static void fill_tab(char **env, int index, int start, char *path)
{
    if (env[index][start] != '/') {
        my_printf(": No such file or directory.\n");
        path[0] = '\0';
        if (!(isatty(STDIN_FILENO)))
            exit(1);
        return;
    }
    for (int fill = 0; env[index][start] != '\0'; fill++) {
        path[fill] = env[index][start];
        start++;
    }
}

static int parsing_home(char **env, int index)
{
    char *temp = search_env(env[index]);

    while (my_strcmp("HOME", temp) != 0 && env[index] != NULL) {
        temp = search_env(env[index]);
        if (my_strcmp("HOME", temp) == 0)
            break;
        index++;
    }
    if (env[index] == NULL) {
        my_printf(": No such file or directory.\n");
        return -1;
    }
    return index;
}

static int parsing_path(char **env, int index)
{
    char *temp = search_env(env[index]);

    while (my_strcmp("PATH", temp) != 0 && env[index] != NULL) {
        temp = search_env(env[index]);
        if (my_strcmp("PATH", temp) == 0)
            break;
        index++;
    }
    if (env[index] == NULL) {
        return -1;
    }
    return index;
}

static int check_file(char *path)
{
    if (access(path, F_OK) == -1) {
        return 1;
    } else if (access(path, X_OK) == -1) {
        return 1;
    }
    return 0;
}

static char *path_alloc(char *env, int *cur, char **args)
{
    int len = 0;
    int start = *cur;
    int current = *cur;
    char *path;

    for (; env[current] != ':' && env[current] != '\0'; current++)
        len++;
    path = (char *)malloc(sizeof(char) * (len + 2 + my_strlen(args[0])));
    path[len + my_strlen(args[0])] = '\0';
    for (int fill = 0; fill < len; fill++) {
        path[fill] = env[start];
        start++;
    }
    path[len] = '/';
    my_strcat(path, args[0]);
    *cur = current;
    if (check_file(path) == 1)
        path = NULL;
    return path;
}

char *getpath(char **env, char **args)
{
    int index = 0;
    char *path;
    int cur = 5;

    index = parsing_path(env, index);
    if (index == -1) {
        my_printf("%s: Command not found.\n", args[0]);
        return "1";
    }
    for (; env[index][cur] != '\0'; cur++) {
        if (env[index][cur] != ':' && env[index][cur + 1] != '\0') {
            path = path_alloc(env[index], &cur, args);
        }
        if (path != NULL)
            return path;
    }
    return NULL;
}

char *gethome(char **env)
{
    int index = 0;
    int cur = 0;
    int len;
    int start;
    char *path;

    index = parsing_home(env, index);
    if (index == -1) {
        path = NULL;
        return path;
    }
    for (cur = 0; env[index][cur - 1] != '='; cur++);
    start = cur;
    for (len = 1; env[index][cur] != '\0'; len++)
        cur++;
    path = (char *)malloc(sizeof(char) * len);
    path[len - 1] = '\0';
    fill_tab(env, index, start, path);
    return path;
}
