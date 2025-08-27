#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int shell_cd(char **args);
int shell_help(char **args);
int shell_exit(char **args);

char *builtin_str[] = {
    "cd",
    "help",
    "exit"};

int (*builtin_function[])(char **) = {
    &shell_cd,
    &shell_help,
    &shell_exit
};

int shell_cmd_num(){
    return sizeof(builtin_str) / sizeof(char *);
};