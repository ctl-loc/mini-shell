#include <stdio.h>
#include <stdlib.h>

#include "io.h"
#include "process.h"

int main(void)
{
    // load configuration
    // TODO
    char input[BUFFER_SIZE];
    int argc;
    char **args;
    int status;

    do
    {
        printf("msh> ");

        if (read_input(input))
        {
            break;
        }

        args = split_line(input, &argc);
        status = execute(argc, args);

        free(args);
    } while (!status);

    printf("\n");
    return 0;
}