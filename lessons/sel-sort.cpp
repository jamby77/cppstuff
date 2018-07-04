#include <iostream>
#include <algorithm>

void printA(int *a, int l) {
    for (int i = 0; i < l; i++) {
        std::cout << a[i] << ' ';
    }
    std::cout << '\n';
}

void selectionSort() {
    const int l = 5;
    int arr[l]{30, 50, 20, 10, 40};
    std::cout << "Initial array:\n";
    printA(arr, l);

    for (int startIdx = 0; startIdx < l - 1; ++startIdx) {
        int smallestIdx = startIdx;

        for (int currentIdx = startIdx + 1; currentIdx < l; ++currentIdx) {
            if (arr[currentIdx] < arr[smallestIdx])
                smallestIdx = currentIdx;
        }

        std::swap(arr[startIdx], arr[smallestIdx]);
//        printA(arr, l);
    }
    std::cout << "\nResult array:\n";
    printA(arr, l);
    std::cout << "\n";

    int arr2[l]{30, 50, 20, 10, 40};
    std::cout << "Initial array:\n";
    printA(arr2, l);

    for (int startIdx = 0; startIdx < l - 1; ++startIdx) {
        int biggestIdx = startIdx;

        for (int currentIdx = startIdx + 1; currentIdx < l; ++currentIdx) {
            if (arr2[currentIdx] > arr2[biggestIdx])
                biggestIdx = currentIdx;
        }

        std::swap(arr2[biggestIdx], arr2[startIdx]);
//        printA(arr2, l);
    }
    std::cout << "\nResult array:\n";
    printA(arr2, l);
}

void bubbleSort() {
    int arr[]{6, 3, 2, 9, 7, 1, 5, 4, 8};
    constexpr int l = sizeof(arr) / sizeof(arr[0]);

    for (int iter = 0; iter < l - 1; ++iter) {
        bool swapped{false};
        for (int i = 0; i < l - 1; ++i) {
            if (arr[i] > arr[i + 1]) {
                swapped = true;
                std::swap(arr[i], arr[i + 1]);
            }
        }
        if (!swapped) {
            std::cout << "Early termination at iteration: " << iter + 1 << '\n';
            break;
        }
    }
    printA(arr, l);
}

int main() {
    selectionSort();
    std::cout << "\n";
    bubbleSort();
    return 0;
}
