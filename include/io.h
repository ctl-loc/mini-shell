#ifndef IO_H
#define IO_H

#define BUFFER_SIZE 1024

#define C_RESET "\033[1;0m"
#define C_RED "\033[1;31m"
#define C_GREEN "\033[1;32m"
#define C_YELLOW "\033[1;33m"
#define C_BLUE "\033[1;34m"
#define C_WHITE "\033[1;37m"

int read_input(char *b);
void msh_printf(char *text, char *c_tag, ...);
void msh_printfln(char *text, char *c_tag, ...);

#endif
