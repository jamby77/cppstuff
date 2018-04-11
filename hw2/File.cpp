//
// Created by pdzhambazov on 4/11/18.
//
#include <fstream>
#include "File.h"

File::File(const char *fileName) : fileName(fileName) {
    fileRead.open(fileName);
}

File::~File() {
    fileRead.close();
}

const char *File::getLine(unsigned line) {
    if (!isRead) {
        readFile();
    }
    return data.getAt(line);
}

size_t File::addLine(const char *lineOfText) {
    data.pushBack(lineOfText);
    return data.getSize();
}

void File::removeLine(unsigned line) {
    data.removeAt(line, true);
}

bool File::readFile() {
    while (fileRead.good()) {
        char *row[MAXL];
        fileRead.getline(row, MAXL);
        data.pushBack(row);
    }
    isRead = true;
    return isRead;
}
