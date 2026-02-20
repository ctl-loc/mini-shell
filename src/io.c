#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include "io.h"

int read_input(char *buffer)
{
    if (!fgets(buffer, BUFFER_SIZE, stdin))
        return 1;

    buffer[strcspn(buffer, "\n")] = '\0';
    return 0;
}

void msh_printf(char *c_tag, char *text, ...)
{

    va_list args;

    printf("%s", c_tag); // start color

    va_start(args, text);
    vprintf(text, args); // forward arguments
    va_end(args);

    printf("%s", C_RESET); // reset color
}

void msh_printfln(char *c_tag, char *text, ...)
{

    va_list args;

    printf("%s", c_tag);

    va_start(args, text);
    vprintf(text, args);
    va_end(args);

    printf("%s\n", C_RESET);
}
