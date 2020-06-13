#ifndef _GCP_H
#define _GCP_H
#include <unistd.h>
#include <limits.h>

char *gcp()
{
    char cwd[PATH_MAX];
    if (getcwd(cwd, sizeof(cwd)) != NULL)
        return getcwd(cwd, sizeof(cwd));
    return "ERROR";
}

#endif