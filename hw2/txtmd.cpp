//
// Created by pdzhambazov on 3/28/18.
//

#include <iostream>
#include "MdTransformer.h"

using namespace std;

int main() {
    MdTransformer md;
    md.makeBold(1, 1, 3);
    md.makeBold(1, 2, 3);
    md.makeBold(1, 3, 3);
    md.makeBold(1, 4, 6);
    cout << "Hello world!" << endl;
}
