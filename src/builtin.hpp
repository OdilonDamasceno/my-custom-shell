#ifndef _BUILTIN_H
#define _BUILTIN_H
#define CPP char **

#include <stdio.h>
#include <unistd.h>

int cd(CPP args);
int help(CPP args);
int osh_exit(CPP args);

char *builtin_str[] = {
    (char *)"cd",
    (char *)"help",
    (char *)"exit",
};

int (*builtin_func[])(CPP) = {
    &cd,
    &help,
    &osh_exit
};

int num_builtins()
{
    return sizeof(builtin_str) / sizeof(char *);
}

int cd(CPP args)
{
    if(args[1]==NULL)
    {
        fprintf(stderr,"expected argument to \"cd\"\n");
    }else{
        if (chdir(args[1]) != 0) {
            perror("lsh");
        }
    }
    return 1;
}
int help(char **args)
{
  int i;
  printf("Odilon OSH\n");
  printf("The following are built in:\n");

  for (i = 0; i < num_builtins(); i++) {
    printf("  %s\n", builtin_str[i]);
  }

  printf("Use the man command for information on other programs.\n");
  return 1;
}

int osh_exit(char **args)
{
  return 0;
}

#endif