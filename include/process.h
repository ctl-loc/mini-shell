#ifndef PROCESS_H
#define PROCESS_H

char **split_line(char *line, int *argc);
int execute(int argc, char **args);

#endif
