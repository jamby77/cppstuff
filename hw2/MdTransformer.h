//
// Created by Petar Dzhambazov on 9.04.18.
//

#ifndef IVA_MDTRANSFORMER_H
#define IVA_MDTRANSFORMER_H

class MdTransformer
{
    void clean();
    void copyFrom(const MdTransformer &transformer);
public:
    MdTransformer();
    MdTransformer(const MdTransformer &);
    ~MdTransformer();
//    explicit MdTransformer(size_t size);
    MdTransformer &operator=(const MdTransformer &);
    void makeBold(unsigned line, unsigned fromWord, unsigned toWord);
};

#endif //IVA_MDTRANSFORMER_H
