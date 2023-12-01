#include <iostream>

const std::size_t MAX_SIZE = 30;

void swapPointer(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void swapReference(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void sort(int array[], std::size_t size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < (size - 1); j++) {
            if (array[j] > array[j + 1]) {
//                swapPointer(&array[j + 1], &array[j]);
                swapReference(array[j + 1], array[j]);
            }
        }
    }
}

int main() {
    int sampleArr[] = {1, -3, 0, 123, 3};

    sort(sampleArr, 5);

    for (int i = 0; i < 5; ++i) {
        std::cout << sampleArr[i] << ' ';
    }
    std::cout << std::endl;

    return 0;
}
