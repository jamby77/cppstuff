//
// Created by Petar Dzhambazov on 9.04.18.
//

#ifndef IVA_MDTRANSFORMER_H
#define IVA_MDTRANSFORMER_H

class MdTransformer
{
    const char *BOLD = "**";
    const char *ITALIC = "*";
    const char *COMBINED = "***";
    const char *HEADING = "# ";
    void clean();
    void copyFrom(const MdTransformer &transformer);
    char *applyMd(const char *text, const char *pad, unsigned fromWord, unsigned toWord);
public:
    MdTransformer();
    MdTransformer(const MdTransformer &);
    ~MdTransformer();
//    explicit MdTransformer(size_t size);
    MdTransformer &operator=(const MdTransformer &);
    void makeBold(unsigned line, unsigned fromWord, unsigned toWord);
    void makeItalic(int line, unsigned fromWord, unsigned toWord);
    void makeCombine(int line, unsigned fromWord, unsigned toWord);
};

#endif //IVA_MDTRANSFORMER_H
