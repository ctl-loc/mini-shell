#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "builtin.h"
#include "io.h"

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
        msh_printfln(C_RED, "msh: Command \"cd\" expect argument\n please use: cd [PATH]");
        return 0;
    }

    if (chdir(args[1]) != 0)
        perror("msh");

    return 0;
}

int msh_help(char **args)
{
    if (args[1] != NULL)
    {
        msh_printfln(C_RED, "msh: Please use the help command alone");
        msh_printfln(C_RED, "For non-builtin commands use the man page");
        return 0;
    }

    int i;
    msh_printfln(C_WHITE, "Mini-shell");
    msh_printfln(C_WHITE, "Type program names and arguments, and hit enter.");
    msh_printfln(C_WHITE, "The following are built in:");

    for (i = 0; i < msh_num_builtins(); i++)
    {
        msh_printfln(C_WHITE, "  %s", builtin_str[i]);
    }

    msh_printfln(C_WHITE, "Use the man command for information on other programs.");
    return 0;
}

int msh_exit(char **args)
{
    if (args[1] != NULL)
    {
        msh_printfln(C_RED, "msh: Please use the exit command alone");
        msh_printfln(C_RED, "I'll let it go this time...");
    }
    return 1;
}
