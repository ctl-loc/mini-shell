#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include "process.h"
#include "builtin.h"
#include "io.h"

#define ARGS_BUFSIZE 64
#define MSH_DELIM " \t\r\n\a"

char **split_line(char *line, int *argc)
{
    int pos = 0;

    int curr_bufsize = ARGS_BUFSIZE;
    char **tokens = (char **)malloc(ARGS_BUFSIZE * sizeof(char));
    char *token;

    if (!tokens)
    {
        fprintf(stderr, "msh: allocation error\n");
        // TODO return error
        exit(1);
    }

    token = strtok(line, MSH_DELIM);
    while (token != NULL)
    {
        tokens[pos] = token;
        pos++;

        if (pos >= curr_bufsize)
        {
            curr_bufsize += ARGS_BUFSIZE;
            tokens = realloc(tokens, curr_bufsize * sizeof(char *));
            if (!tokens)
            {
                fprintf(stderr, "msh: allocation error\n");
                // TODO return error
                exit(1);
            }
        }

        token = strtok(NULL, MSH_DELIM);
    }
    tokens[pos] = NULL;
    *argc = pos;
    return tokens;
}

int launch_proc(char **args)
{
    pid_t pid, wpid;
    int status;

    pid = fork();
    if (pid == 0)
    {
        // Child process
        if (execvp(args[0], args) == -1) // execute command
        {
            perror("msh");
        }

        exit(EXIT_FAILURE);
    }
    else if (pid > 0)
    {
        // Parent process
        do
        {
            // wait for the child to finish
            wpid = waitpid(pid, &status, WUNTRACED);
            printf("Process complete: %d\n", wpid);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status)); // child exited normally or was killed by a signal
    }
    else
    {
        // Error forking
        perror("msh");
    }

    return 0;
}

int execute(char **args)
{
    // check if command is builtin
    for (int i = 0; i < msh_num_builtins(); i++)
    {
        if (!strcmp(args[0], builtin_str[i]))
        {
            return builtin_func[i](args);
        }
    }

    // otherwise launch process
    return launch_proc(args);
}