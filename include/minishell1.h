/*
** EPITECH PROJECT, 2024
** B-PSU-200-LYN-2-1-minishell1-lorenzo.la-rocca
** File description:
** minishell1
*/

#ifndef MINISHELL1_H_
    #define MINISHELL1_H_

int parsing(char **args, char **env, char *pwd);
int exec_binary(char **args, char **env);
int parsing_tty(char **args, char **env, char *pwd);
int check_access(char **args, char *dest);
int cd_handling(char **args, char **env, char *pwd);
int commands_tty(char **args, char **env);
int commands(char **args, char **env);
int set_env(char **args, char **env);
int unset_env(char **args, char **env);
int execve_on_error(char **args);
void my_putenv(char **args, char **env);
char *search_env(char *env);
int disp_env(char **env, char **args);
char *gethome(char **env);
int is_core_dump(int actual, int code);
char *getpath(char **env, char **args);

#endif /* !MINISHELL1_H_ */
