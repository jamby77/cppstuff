//
// Created by pdzhambazov on 4/11/18.
//
#include <fstream>
#include "LinesArray.h"

#ifndef IVA_FILE_H
#define IVA_FILE_H

static const int MAXL = 1024;

class File {
public:
    File(const char *fileName);
    File();
    ~File();
    const char * getLine(unsigned line);
    size_t addLine(const char * lineOfText);
    void removeLine(unsigned line);
    const char *getFileName() const;
    const char *getBaseFileName() const;

private:
    std::ifstream fileRead;
    std::ofstream fileWrite;
    const char * fileName;
    LinesArray data;
    bool isRead = false;
    bool readFile();
};


#endif //IVA_FILE_H
