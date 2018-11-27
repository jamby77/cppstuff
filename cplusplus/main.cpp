#include <iostream>
using namespace std;

const int maxN = 10;

void magicalSquare(int matrix[][maxN], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cin >> matrix[i][j];
        }
    }
}

int sumMatrix(int matrix[][maxN], int size) {
    int firstSum = 0;

    for (int i = 0; i < size; i++) {
        int sumRows = 0;
        for (int j = 0; j <= size; j++) {
            sumRows += matrix[i][j];
        }

        if (firstSum == 0) {
            firstSum = sumRows;
            continue;
        }

        if (firstSum != sumRows) {
            cout << "It's not a magical square rows" << endl;
            return sumRows;
        }

    }


    for (int j = 0; j < size; j++) {
        int sumColons = 0;
        for (int i = 0; i < size; i++) {
            sumColons += matrix[j][i];
        }

        if (firstSum != sumColons) {
            cout << "It's not a magical square cols" << endl;
            return sumColons;
        }

    }

    int sumD1 = 0, sumD2 = 0;
    for (int i = 0; i < size; i++) {
        sumD1 += matrix[i][i];
        int j = size - 1 - i;
        sumD2 += matrix[i][j];
    }

    if (sumD1 != firstSum || sumD2 != firstSum) {
        cout << "false" << endl;
    }

    cout << "It's a megical square! ura"<< endl;;
    return firstSum;
}




int main() {
    int N, matrix[maxN][maxN];

    cout << "Enter your number. It must be in interval (0;10]" << endl << "N=";
    cin >> N;


    while ((N > 10) || (N <= 0)) {
        cout << "Your number is not correct. Please try again" << endl << "N=";
        cin >> N;
        continue;

    }

    magicalSquare(matrix, N);
    sumMatrix(matrix, N);
    return 0;
}