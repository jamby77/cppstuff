//
// Created by Petar Dzhambazov on 9.04.18.
//

#include <cstring>
#include <iostream>
#include "MdTransformer.h"
void MdTransformer::makeBold(unsigned line, unsigned fromWord, unsigned toWord)
{
    // използвай line за да вземеш точния ред, за пример:
    char text[] = "The quick brown fox jumps over the lazy dog";
    // паддинга който се ползва
    const char *pad = "**";
    // големината на падинга
    size_t padLen = strlen(pad);

    // крайния текст трябва да е по-дълъг от оригинала с два пъти повече букви
    size_t textLen = strlen(text);
    char *resText = new char[textLen + padLen*2];

    // стартовата и крайната позиция за трансформиране, започват от едно за да съвпаднат с дума № 1
    unsigned startPos = 1;
    unsigned endPos = 1;
    // допълнителен брояч, който отчита къде е пойнтъра на новия стринг
    int st = 0;
    // флаг дали сме приложили трансформацията преди първата дума
    bool beforeFirstWord = true;
    for (int i = 0; i < textLen; ++i)
    {
        if (text[i]==' ')
        {
            startPos++;
            endPos++;
        }
        if (beforeFirstWord && startPos==fromWord)
        {
            // началната позиция за трансформирането е намерена
            if (text[i]==' ')
            {
                *(resText + st) = text[i];
                // мърдаме с един стринг напред
                st++;
            }
            for (int j = 0; j < padLen; j++)
            {
                *(resText + st) = pad[j];
                st++;
            }
            if (text[i]!=' ')
            {
                *(resText + st) = text[i];
                // мърдаме с един стринг напред
                st++;
            }
            // ресетваме началната позиция
            beforeFirstWord = false;
            continue;
        }
        else if (endPos==(toWord + 1))
        {
            // stignali sme poslednata duma
            for (int j = 0; j < padLen; j++)
            {
                *(resText + st) = pad[j];
                st++;
            }
            *(resText + st) = text[i];
            endPos++;
        }
        else
        {
            *(resText + st) = text[i];
        }
        st++;
    }

    std::cout << resText << std::endl;
}
MdTransformer::MdTransformer() {}
MdTransformer &MdTransformer::operator=(const MdTransformer &other)
{

    if (this!=&other)
    {

        clean();
        copyFrom(other);
    }

    return *this;
}
void MdTransformer::clean()
{

}
void MdTransformer::copyFrom(const MdTransformer &transformer)
{

}
MdTransformer::MdTransformer(const MdTransformer &other)
{
    copyFrom(other);
}
MdTransformer::~MdTransformer()
{

}
