#include <iostream>
#include "LinesArray.h"

LinesArray::LinesArray() : pData(nullptr), curSize(0), capacity(0)
{

}

LinesArray::LinesArray(size_t size) : curSize(size), capacity(2*size)
{
    pData = new char *[capacity];
    memset(pData, 0, capacity);
}

LinesArray::~LinesArray()
{
    clean();
}

void LinesArray::clean()
{
    delete[] pData;

    pData = nullptr;
    curSize = 0;
    capacity = 0;
}

void LinesArray::copyFrom(const LinesArray &other)
{
    pData = new char *[other.capacity];

    memcpy(pData, other.pData, other.curSize);

    curSize = other.curSize;
    capacity = other.capacity;
}

LinesArray::LinesArray(const LinesArray &other) : pData(nullptr), curSize(0), capacity(0)
{

    copyFrom(other);
}

LinesArray &LinesArray::operator=(const LinesArray &other)
{

    if (this!=&other)
    {

        clean();
        copyFrom(other);
    }

    return *this;
}

void LinesArray::resize(size_t newCap)
{
    char **temp = pData;

    pData = new char *[newCap];

    memcpy(pData, temp, curSize*sizeof(char));

    capacity = newCap;

    delete[] temp;
}

void LinesArray::pushBack(char *text)
{
    if (curSize >= capacity)
    {

        size_t newCap = (capacity==0) ? 2 : capacity*2;
        resize(newCap);
    }

    pData[curSize++] = text;
}

void LinesArray::setAt(size_t pos, char *text)
{
    if (pos >= curSize)
        return;

    pData[pos] = text;
}

char *LinesArray::getAt(size_t pos) const
{
    if (pos >= curSize)
        return nullptr;
    return pData[pos];
}

size_t LinesArray::getSize() const
{
    return curSize;
}

size_t LinesArray::getCapacity() const
{
    return capacity;
}

void LinesArray::printInfo() const
{
    std::cout << "obj at: Ox" << this
              << " buffer starts at: Ox" << pData
              << " length:" << curSize
              << " capacity:" << capacity << std::endl;
}

void LinesArray::popBack()
{
    if (curSize)
        curSize--;
    else
        return;

    if (curSize*2 <= capacity)
    {

        size_t newCap = ((curSize==0) ? 0 : capacity/2);
        resize(newCap);
    }
}

void LinesArray::removeAt(size_t pos, bool isSorted)
{
    if (pos >= curSize || curSize==1)
    { //just removes the last elem

        popBack();
        return;
    }

    //faster version O(1), but can be unexpected
    //from the class' client
    if (!isSorted)
    {

        pData[pos] = pData[curSize - 1];
        popBack();
        return;
    }

    //else ..rolling back all elements
    for (size_t i = pos; i < curSize - 1; i++)
    {
        char *temp1 = pData[i];
        char *temp2 = pData[i + 1];
        pData[i] = temp2;
        pData[i + 1] = temp1;
    }

    popBack();
}

