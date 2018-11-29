#include <iostream>

using namespace std;

const int MAX = 100;

void printMatrix(int *m, int N) {
    int i = 1;
    for (int *ptr1 = m; ptr1 < m + N * N; ++ptr1, ++i) {
        std::cout << *ptr1 << ' ';
        if (i > 0 && i % N == 0) {
            cout << '\n';
        }
    }
}

int main() {

    int N;
    int buffer;
    cout << "N=";
    cin >> N;

    int matrix1[MAX * MAX];
    int matrix2[MAX * MAX];
    int matrix3[MAX * MAX];
    int *ptr1, *ptr2, *ptr3;
    // int ik, kj;

    for (ptr1 = matrix1; ptr1 < matrix1 + N * N; ptr1++) {
        cin >> *ptr1;
    }
    // printMatrix(matrix1, N);

    for (ptr2 = matrix2; ptr2 < matrix2 + N * N; ptr2++) {
        cin >> *ptr2;
    }
    // printMatrix(matrix2, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            ptr3 = matrix3;
            buffer = 0;
            for (int k = 0; k < N; k++) {
                ptr1 = matrix1 + ((i * N) + k);
                ptr2 = matrix2 + ((k * N) + j);
                // std::cout << "ptr1: " << *ptr1 << '\n';
                // std::cout << "ptr2: " << *ptr2 << '\n';

                buffer += (*(ptr1) * *(ptr2));
            }
            *(ptr3 + ((i * N) + j)) = buffer;
        }
    }

    printMatrix(matrix3, N);

    return 0;
}