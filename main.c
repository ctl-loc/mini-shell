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
        msh_printf(C_BLUE, "msh> ");

        if (read_input(input))
        {
            break;
        }

        args = split_line(input, &argc);
        status = execute(args);

        free(args);
    } while (!status);

    msh_printfln(C_GREEN, "See you next time :)");
    return 0;
}