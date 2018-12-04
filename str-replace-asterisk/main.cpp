//
// Created by pdzhambazov on 04.12.18.
//

#include<iostream>
#include <cstring>

using namespace std;

const int MAX = 100;

void replaceChar(char str1[], char str2[], size_t size1, size_t size2) {

    int count = 0;

    for (int i = 0; i < size1; i++) {
        if (str2[0] == str1[i]) {
            for (int j = 1; j < size2; j++) {
                if (str2[j] == str1[i + j]) {
                    count++;
                }
            }

            if (count == size2 - 1) {
                for (int j = 0; j < size2; j++) {
                    if (str2[j] == str1[i + j]) {
                        str1[i + j] = '*';
                    }
                }
                count = 0;
            }
        }
    }
    cout << str1 << '\n';
    // cout << "The small string is not substring of the bigger string. Replacing symbols is impossible!";
}


int main() {

    char str1[MAX];
    char str2[MAX];
    cin.getline(str1, MAX);
    cin.getline(str2, MAX);

    size_t length1 = strlen(str1);
    size_t length2 = strlen(str2);

    if (length1 > length2) {
        replaceChar(str1, str2, length1, length2);
    } else {
        replaceChar(str2, str1, length2, length1);
    }
    return 0;
}