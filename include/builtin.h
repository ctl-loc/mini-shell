#ifndef BUILTIN_H
#define BUILTIN_H

int msh_num_builtins();

int msh_cd(char **args);
int msh_help(char **args);
int msh_exit(char **args);

extern char *builtin_str[];
extern int (*builtin_func[])(char **);

#endif
