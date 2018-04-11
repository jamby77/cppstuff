//
// Created by pdzhambazov on 3/28/18.
//

#include <iostream>
#include "MdTransformer.h"

using namespace std;

int main() {
    MdTransformer md;
    cout << "Make bold" << endl;
    md.makeBold(1, 1, 3);
    md.makeBold(1, 2, 3);
    md.makeBold(1, 3, 3);
    md.makeBold(1, 4, 6);
    cout << "\nMake italic" << endl;
    md.makeItalic(1, 1, 3);
    md.makeItalic(1, 2, 3);
    md.makeItalic(1, 3, 3);
    md.makeItalic(1, 4, 6);
    cout << "\nMake combine" << endl;
    md.makeCombine(1, 1, 3);
    md.makeCombine(1, 2, 3);
    md.makeCombine(1, 3, 3);
    md.makeCombine(1, 4, 6);
    md.makeHeading(1);
}
