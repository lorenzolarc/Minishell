/*
** EPITECH PROJECT, 2024
** B-PSU-200-LYN-2-1-minishell1-lorenzo.la-rocca
** File description:
** tty_com
*/

#include "../include/my.h"
#include "../include/minishell1.h"
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

static int check_sig_tty(int actual)
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

static int child_status_tty(char **args, pid_t child)
{
    int actual;

    wait(&actual);
    if (WIFEXITED(actual))
        return WEXITSTATUS(actual);
    if (WIFSIGNALED(actual)) {
        return check_sig_tty(actual);
    }
    return WEXITSTATUS(actual);
}

static int child_tty(char **args, char **env, char *dest)
{
    pid_t child = fork();

    if (child == 0) {
        if (check_access(args, dest) == 1)
            return 1;
        if (execve(dest, args, env) == -1) {
            return execve_on_error(args);
        }
    }
    return child_status_tty(args, child);
}

static int exec_binary_tty(char **args, char **env)
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
    return child_tty(args, env, dest);
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

int execve_on_error(char **args)
{
    my_printf("%s: %s.%s\n", args[0], strerror(errno),
    (errno == ENOEXEC) ? " Wrong Architecture." : "");
    return 1;
}

int commands_tty(char **args, char **env)
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
    return exec_binary_tty(args, env);
}

int parsing_tty(char **args, char **env, char *pwd)
{
    if (my_strcmp(args[0], "cd") == 0) {
        if (cd_handling(args, env, pwd) == 1)
            return 1;
        return 0;
    }
    if (args[0][0] == '.' || args[0][0] == '/') {
        return child_tty(args, env, args[0]);
    }
    if (my_strcmp(args[0], "exit") == 0) {
        if (args[1] == NULL)
            exit(0);
        exit_command(args);
    }
    return commands_tty(args, env);
}
