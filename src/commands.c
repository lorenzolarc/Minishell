/*
** EPITECH PROJECT, 2024
** B-PSU-200-LYN-2-1-minishell1-lorenzo.la-rocca
** File description:
** commands
*/

#include "../include/my.h"
#include "../include/minishell1.h"
#include <signal.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

static void child(char **args, char **env, char *dest)
{
    int child = fork();

    if (child == 0) {
        if (check_access(args, dest) == 1) {
            return;
        }
        if (execve(dest, args, env) == -1) {
            execve_on_error(args);
            return;
        }
    }
}

int is_core_dump(int actual, int code)
{
    if (WCOREDUMP(actual))
        return code;
    return code;
}

static int check_sig(int actual)
{
    int signal = WTERMSIG(actual);

    if (WIFSIGNALED(actual)) {
        my_printf("%s\n", strsignal(signal));
        if (WCOREDUMP(actual))
            return 128 + signal;
        else
            return 1;
    }
    return 1;
}

static int child_status(char **args)
{
    int actual;

    wait(&actual);
    if (WIFEXITED(actual))
        return WEXITSTATUS(actual);
    if (WIFSIGNALED(actual))
        return check_sig(actual);
    return WEXITSTATUS(actual);
}

int exec_binary(char **args, char **env)
{
    char *dest;

    if (access(args[0], X_OK) != 0) {
        dest = getpath(env, args);
        if (dest == NULL) {
            my_printf("%s: Command not found.\n", args[0]);
            return 1;
        }
    } else
        dest = args[0];
    child(args, env, dest);
    free(dest);
    return child_status(args);
}

static int exit_command(char **args)
{
    if (args[1][0] <= '0' || args[1][0] >= '9') {
        my_printf("%s: Expression Syntax.\n", args[0]);
        exit(1);
    }
    for (int index = 0; args[1][index] != '\0'; index++) {
        if (args[1][index] <= '0' || args[1][index] >= '9') {
            my_printf("%s: Badly formed number.\n", args[0]);
            exit(1);
        }
    }
    exit(my_getnbr(args[1]));
}

int commands(char **args, char **env)
{
    if (my_strcmp(args[0], "setenv") == 0) {
        return set_env(args, env);
    }
    if (my_strcmp(args[0], "unsetenv") == 0) {
        return unset_env(args, env);
    }
    if (my_strcmp(args[0], "env") == 0) {
        return disp_env(env, args);
    }
    return exec_binary(args, env);
}

int parsing(char **args, char **env, char *pwd)
{
    if (my_strcmp(args[0], "cd") == 0) {
        if (cd_handling(args, env, pwd) == 1)
            return 1;
        return 0;
    }
    if (args[0][0] == '.' || args[0][0] == '/') {
        child(args, env, args[0]);
        return child_status(args);
    }
    if (my_strcmp(args[0], "exit") == 0) {
        if (args[1] == NULL)
            exit(0);
        exit_command(args);
    }
    return commands(args, env);
}
