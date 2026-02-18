#include <stdio.h>
#include <string.h>
#include "input.h"

int read_input(char *buffer)
{
    if (!fgets(buffer, BUFFER_SIZE, stdin))
        return 1;

    buffer[strcspn(buffer, "\n")] = '\0';
    return 0;
}
