#ifndef _GCP_H
#define _GCP_H
#define cd getcwd(cwd, sizeof(cwd))
#include <unistd.h>
#include <limits.h>
#include <iostream>
using namespace std;
char *gcp()
{
    char cwd[PATH_MAX];
    if (cd != NULL)
        return cd;
    return (char *)"ERROR";
}   

#endif