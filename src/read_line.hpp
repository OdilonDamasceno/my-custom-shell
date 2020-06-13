#ifndef _READ_LINE_H
#define _READ_LINE_H
#define RL_BUFSIZE 1024
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

char *read_line(void)
{
    char *line = NULL;
    size_t bufsize = 0;

    if (getline(&line, &bufsize, stdin) == -1)
    {
        if (feof(stdin))
        {
            exit(EXIT_SUCCESS);
        }
        else
        {
            perror("readline");
            exit(EXIT_FAILURE);
        }
    }

    return line;
}
// char *read_line(void)
// {
//     int bufsize = RL_BUFSIZE;
//     int position = 0;
//     char *buffer =(char*)malloc(sizeof(char) * bufsize);
//     int c;

//     if (buffer)
//     {
//         fprintf(stderr, "lsh: allocation error\n");
//         exit(EXIT_FAILURE);
//     }
//     while (1)
//     {
//         c = getchar();
//         if (c == EOF || c == '\n')
//         {
//             buffer[position] = '\0';
//             return buffer;
//         }
//         else
//         {
//             buffer[position] = c;
//         }
//         position++;
//     }

//     if (position >= bufsize)
//     {
//         bufsize += RL_BUFSIZE;
//         buffer =(char*)realloc(buffer, bufsize);
//         if (!buffer)
//         {
//             fprintf(stderr, "lsh: allocation error\n");
//             exit(EXIT_FAILURE);
//         }
//     }
// }

#endif