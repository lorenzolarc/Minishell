/*
** EPITECH PROJECT, 2024
** B-PSU-200-LYN-2-1-minishell1-lorenzo.la-rocca
** File description:
** error_handling
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
#include <string.h>

int check_access(char **args, char *dest)
{
    if (access(dest, F_OK) == -1) {
        my_printf("%s: Command not found.\n", args[0]);
        return 1;
    } else if (access(dest, X_OK) == -1) {
        my_printf("%s: Permission denied.\n", args[0]);
        return 1;
    }
    return 0;
}

static void old_pwd(char *pwd)
{
    if (getcwd(pwd, 4096) == NULL) {
        return;
    }
}

void update_pwd(char **env, int index)
{
    char *new;
    char *temppwd = (char *)malloc(sizeof(char) * 4096);

    getcwd(temppwd, 4096);
    new = (char *)malloc(sizeof(char) * (my_strlen(temppwd) + 6));
    my_strcat(new, "PWD=");
    my_strcat(new, temppwd);
    env[index] = new;
}

void update_oldpwd(char **env, char *oldpwd)
{
    char *new;
    int index = 0;
    char *temp = search_env(env[index]);

    while (my_strcmp("OLDPWD", temp) != 0 && env[index] != NULL) {
        temp = search_env(env[index]);
        if (my_strcmp("OLDPWD", temp) == 0) {
            break;
        }
        index++;
    }
    if (env[index] == NULL)
        env[index + 1] = NULL;
    new = (char *)malloc(sizeof(char) * (my_strlen(oldpwd) + 8));
    my_strcat(new, "OLDPWD=");
    my_strcat(new, oldpwd);
    env[index] = new;
}

static void change_pwd_env(char **env, char *oldpwd)
{
    int index = 0;
    char *temp = search_env(env[index]);

    while (my_strcmp("PWD", temp) != 0 && env[index] != NULL) {
        temp = search_env(env[index]);
        if (my_strcmp("PWD", temp) == 0) {
            update_pwd(env, index);
            break;
        }
        index++;
    }
    update_oldpwd(env, oldpwd);
}

static int on_error_cd(char **args, char **env, char *pwd)
{
    if (chdir(args[1]) != 0) {
        if (errno == ENOENT) {
            my_printf("%s: No such file or directory.\n", args[1]);
            return 1;
        }
        if (errno == EACCES) {
            my_printf("%s: Permission denied.\n", args[1]);
            return 1;
        }
        if (errno == ENOTDIR) {
            my_printf("%s: Not a directory.\n", args[1]);
            return 1;
        }
    }
    change_pwd_env(env, pwd);
    return 0;
}

int cd_handling(char **args, char **env, char *pwd)
{
    char *home = gethome(env);

    if (args[1] != NULL && args[1][0] == '-') {
        if (chdir(pwd) != 0) {
            my_printf(": No such file or directory.\n");
            return 1;
        }
        change_pwd_env(env, pwd);
        return 0;
    }
    old_pwd(pwd);
    if (args[1] == NULL || args[1][0] == '~') {
        if (home[0] == '\0')
            return 1;
        chdir(home);
        change_pwd_env(env, pwd);
        return 0;
    }
    return on_error_cd(args, env, pwd);
}
