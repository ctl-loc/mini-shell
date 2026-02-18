#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "process.h"
#include "io.h"

#define ARGS_BUFSIZE 64
#define MSH_DELIM " \t\r\n\a"

char **split_line(char *line)
{
    int pos = 0;

    int curr_bufsize = ARGS_BUFSIZE;
    char **tokens = (char **)malloc(ARGS_BUFSIZE * sizeof(char));
    char *token;

    if (!tokens)
    {
        fprintf(stderr, "msh: allocation error\n");
        // TODO return error
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
            }
        }

        token = strtok(NULL, MSH_DELIM);
    }
    tokens[pos] = NULL;
    return tokens;
}

int execute(char **args)
{
    return 0;
}