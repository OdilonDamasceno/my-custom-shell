#ifndef _LOOP_H
#define _LOOP_H
#include <stdio.h>
#include "read_line.h"
#include "split_line.h"
#include "execute.h"
#include "gcp.h"

void loop(void)
{
    char *line;
    char **args;
    int status;
    do
    {
        printf("%s\n",gcp());
        printf("> ");
        line = read_line();
        args = split_line(line);
        status = execute(args);

        free(line);
        free(args);
    }while (status);
}

#endif