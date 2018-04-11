//
// Created by Petar Dzhambazov on 9.04.18.
//

#ifndef IVA_MDTRANSFORMER_H
#define IVA_MDTRANSFORMER_H

#include "File.h"
class MdTransformer
{
    const char *BOLD = "**";
    const char *ITALIC = "*";
    const char *COMBINED = "***";
    const char *HEADING = "# ";
    File fileRead;
    void clean();
    void copyFrom(const MdTransformer &transformer);
    char *applyMd(const char *text, const char *pad, unsigned fromWord, unsigned toWord);
public:
    MdTransformer();
    MdTransformer(const MdTransformer &);
    ~MdTransformer();
    explicit MdTransformer(File fileRead);
    explicit MdTransformer(const char * fileName);
    MdTransformer &operator=(const MdTransformer &);
    void makeBold(unsigned line, unsigned fromWord, unsigned toWord);
    void makeItalic(unsigned line, unsigned fromWord, unsigned toWord);
    void makeCombine(unsigned line, unsigned fromWord, unsigned toWord);
    void makeHeading(unsigned line);
};

#endif //IVA_MDTRANSFORMER_H
