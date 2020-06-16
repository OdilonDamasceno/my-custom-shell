#ifndef _WRITE_HISTORY_H
#define _WRITE_HISTORY_H
#include <iostream>
#include <fstream>

void write_history(char *line)
{
    std::ofstream file;
    file.open(".osh_history",std::ios::app);
    if (!file.is_open())
    {
        std::ofstream hist(".osh_history",std::ios::app);
        hist<<line;
        hist.close();
    }
    file<<line;
    file.close();
}

#endif