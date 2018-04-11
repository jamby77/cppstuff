//
// Created by pdzhambazov on 4/11/18.
//
#include <fstream>
#include <cstring>
#include "File.h"

File::File(const char *fileName) : fileName(fileName)
{
    fileRead.open(fileName);
}

File::~File()
{
    fileRead.close();
}

const char *File::getLine(unsigned line)
{
    if (!isRead)
    {
        readFile();
    }
    return data.getAt(line);
}

size_t File::addLine(const char *lineOfText)
{
    data.pushBack(lineOfText);
    return data.getSize();
}

void File::removeLine(unsigned line)
{
    data.removeAt(line, true);
}

bool File::readFile()
{
    while (fileRead.good())
    {
        char *row[MAXL];
        fileRead.getline(row, MAXL);
        data.pushBack(row);
    }
    isRead = true;
    return isRead;
}
const char *File::getFileName() const
{
    return fileName;
}
const char *File::getBaseFileName() const
{
    const char *name = getFileName();
    char *dot = strrchr(name, '.');
    if (dot==nullptr)
    {
        return name;
    }

    unsigned long pos = dot - name;
    char *baseName = new char[pos + 1];
    strncpy(baseName, name, pos);
    baseName[pos] = '\0';
    return baseName;
}
