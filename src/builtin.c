#include <stdio.h>
#include <unistd.h>

#include "builtin.h"

char *builtin_str[] = {
    "cd",
    "help",
    "exit"};

int (*builtin_func[])(char **) = {
    &msh_cd,
    &msh_help,
    &msh_exit};

int msh_num_builtins()
{
    return sizeof(builtin_str) / sizeof(char *);
}

int msh_cd(char **args)
{
    if (args[1] == NULL)
    {
        fprintf(stderr, "msh: Command \"cd\" expect argument\n please use: cd [PATH]\n");
    }
    else
    {
        if (chdir(args[1]) != 0)
            perror("msh");
    }
    return 0;
}

int msh_help(char **args)
{
    if (args[1] != NULL)
    {
        printf("msh: Please use the help command alone\n");
        printf("For non-builtin commands use the man page");
        return 0;
    }

    int i;
    printf("Mini-shell\n");
    printf("Type program names and arguments, and hit enter.\n");
    printf("The following are built in:\n");

    for (i = 0; i < msh_num_builtins(); i++)
    {
        printf("  %s\n", builtin_str[i]);
    }

    printf("Use the man command for information on other programs.\n");
    return 1;
}

int msh_exit(char **args)
{

    printf("%s\n", args[0]);
    return 0;
}
