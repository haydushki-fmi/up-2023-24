#include <iostream>

void printArray(int *arr, std::size_t size) {
    if (size == 0) {
        return;
    }
    std::cout << *arr << std::endl;
    printArray(arr + 1, size - 1);
}

void printArrayReverse(int *arr, std::size_t size) {
    if (size == 0) {
        return;
    }
    printArrayReverse(arr + 1, size - 1);
    std::cout << *arr << std::endl;
}

int main() {
    int a[] = {1, 2, 3, 4, 5, 6, 7};
    printArray(a, sizeof(a) / sizeof(int));
    std::cout << std::endl;
    printArrayReverse(a, sizeof(a) / sizeof(int));
    return 0;
}
