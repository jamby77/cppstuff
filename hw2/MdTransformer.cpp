//
// Created by Petar Dzhambazov on 9.04.18.
//

#include <cstring>
#include <iostream>
#include "MdTransformer.h"
char *MdTransformer::applyMd(const char *text, const char *pad, unsigned fromWord, unsigned toWord)
{
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
        // при всеки спейс сме на следваща дума (може да се подобри да проверява дали text[i+1] е различен от спейс)
        if (text[i]==' ')
        {
            startPos++;
            endPos++;
        }
        // ако все още не сме приложили падинг преди първата дума, и сме стигнали до нея
        if (beforeFirstWord && startPos==fromWord)
        {
            // началната позиция за трансформирането е намерена

            // ако моментния знак е спейс, го добавяме преди да сложим падинга
            if (text[i]==' ')
            {
                resText[st] = text[i];
                // мърдаме с една позиция напред
                st++;
            }
            // добавяме падинга
            for (int j = 0; j < padLen; j++)
            {
                resText[st] = pad[j];
                // при всеки знак от падинга, мърдаме вътрешния брояч напред
                st++;
            }
            // ако случайно моментния знак НЕ Е спейс, например в началото на реда (1-ва дума), го добавяме след падинга
            if (text[i]!=' ')
            {
                resText[st] = text[i];
                // мърдаме с един стринг напред
                st++;
            }
            // слагаме флага на фолс, за да не процесваме този иф отново
            beforeFirstWord = false;
            continue;
        }
        else if (endPos==(toWord + 1))
        {
            // стигнали сме до последната дума, плюс едно т.е. след нея
            for (int j = 0; j < padLen; j++)
            {
                resText[st] = pad[j];
                st++;
            }
            resText[st] = text[i];
            endPos++;
        }
        else
        {
            // ако не сме нито преди първата или веднага след последната дума, просто копираме знака в резултата
            resText[st] = text[i];
        }
        st++;
    }
    return resText;
}

void MdTransformer::makeBold(unsigned line, unsigned fromWord, unsigned toWord)
{
    // използвай line за да вземеш точния ред, за пример:
    const char *text = "The quick brown fox jumps over the lazy dog";
    char *resText = applyMd(text, BOLD, fromWord, toWord);

    std::cout << resText << std::endl;
}
void MdTransformer::makeItalic(int line, unsigned fromWord, unsigned toWord)
{
    // използвай line за да вземеш точния ред, за пример:
    const char *text = "The quick brown fox jumps over the lazy dog";
    char *resText = applyMd(text, ITALIC, fromWord, toWord);

    std::cout << resText << std::endl;
}
void MdTransformer::makeCombine(int line, unsigned fromWord, unsigned toWord)
{
    // използвай line за да вземеш точния ред, за пример:
    const char *text = "The quick brown fox jumps over the lazy dog";
    char *resText = applyMd(text, COMBINED, fromWord, toWord);

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
