//
// Created by Petar Dzhambazov on 7.04.18.
//

#ifndef IVA_LINESARRAY_H
#define IVA_LINESARRAY_H

class LinesArray
{
private:

    char **pData;
    size_t curSize; //how many actual values are stored
    size_t capacity; //what is the maximum allocated memory in given moment

public:

    //THE BIG FOUR + constructor with parameter
    LinesArray();

    explicit LinesArray(size_t size);

    LinesArray &operator=(const LinesArray &);

    LinesArray(const LinesArray &);

    ~LinesArray();

    //help functions
private:

    void copyFrom(const LinesArray &);

    void clean();

    void resize(size_t);

    //interface
public:

    //adds new element at array's end
    void pushBack(char *text);

    //gets a value at wanted index
    char *getAt(size_t) const;

    //sets a value at wanted index
    void setAt(size_t, char *text);

    //removes element on given index,
    //the second parameter stands for
    //algorithm usage - by passing true
    //the array is sorted, so the client
    //wants it to remain sorted after
    //our remove operation
    void removeAt(size_t, bool);

    size_t getSize() const;

    size_t getCapacity() const;

    void printInfo() const;

    void popBack();
};

#endif //IVA_LINESARRAY_H
