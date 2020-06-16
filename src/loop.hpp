#ifndef _LOOP_H
#define _LOOP_H
#include <stdio.h>
#include "read_line.hpp"
#include "split_line.hpp"
#include "execute.hpp"
#include "gcp.hpp"
#include <unistd.h>
#include <limits.h>
#include <fstream>
#include <iostream>
#include "write_history.hpp"

void loop(void)
{
    char *line;
    char **args;
    int status;
    char hostbuffer[HOST_NAME_MAX];
    int MAX = 80;
    char buff[MAX];
    char cwd[PATH_MAX];

    do
    {
        std::ifstream fin(".git/HEAD");
        fin.getline(buff, MAX);
        for (size_t i = 0; i < 16; i++)
        {
            buff[i] = '\b';
        }

        gethostname(hostbuffer, sizeof(hostbuffer));

        printf("$\033[1;36m %s@%s \033[0m", getlogin(), hostbuffer);

        printf("\033[1;31mat\033[0m \033[1;33m%s\033[0m\n%s> ", gcp(), (char *)&buff);

        line = read_line();
        args = split_line(line);
        status = execute(args);

        free(line);
        free(args);
        for (size_t i = 0; i < sizeof(buff); i++)
        {
            buff[i] = '\0';
        }

    } while (status);
}

#endif