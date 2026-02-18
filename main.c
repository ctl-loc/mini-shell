#include <stdio.h>
#include <stdlib.h>

#include "io.h"
#include "process.h"

int main(void)
{
    // load configuration
    // TODO
    char buffer[BUFFER_SIZE];
    char **args;
    int status = 1; // TODO remove init when status set in loop

    do
    {
        printf("msh> ");

        if (read_input(buffer))
            break;

        args = split_line(buffer);
        // status = execute(args);

        free(args);
    } while (status);

    printf("\n");
    return 0;
}