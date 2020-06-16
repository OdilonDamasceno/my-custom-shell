#ifndef _SPLIT_LINE_H
#define _SPLIT_LINE_H
#define TOK_BUFSIZE 64
#define TOK_DELIM " \t\r\n\a"
#include <stdio.h>
#include <string.h>
#include <iostream>
#include "write_history.hpp"

char **split_line(char *line)
{
    write_history(line);
    int bufsize = TOK_BUFSIZE, position = 0;
    char **tokens = (char **)malloc(bufsize * sizeof(char *));
    char *token;
    if (!tokens)
    {
        fprintf(stderr, "lsh: allocation error\n");
        exit(EXIT_FAILURE);
    }
    token = strtok(line, TOK_DELIM);
    while (token != NULL)
    {
        tokens[position] = token;
        position++;
        if (position >= bufsize)
        {
            bufsize += TOK_BUFSIZE;
            tokens = (char **)realloc(tokens, bufsize * sizeof(char *));
            if (!tokens)
            {
                fprintf(stderr, "lsh: allocation error\n");
                exit(EXIT_FAILURE);
            }
        }
        token = strtok(NULL, TOK_DELIM);
    }
    tokens[position]=NULL;
    return tokens;
}

#endif