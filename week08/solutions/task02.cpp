#include <iostream>

void inputArray(int array[], std::size_t size) {
    for (int i = 0; i < size; ++i) {
        std::cin >> array[i];
    }
}

void printArray(int array[], std::size_t size) {
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << '\t';
    }
    std::cout << std::endl;
}

void removeAt(int array[], std::size_t size, std::size_t pos) {
    for (std::size_t i = pos; i < size - 1; ++i) {
        array[i] = array[i + 1];
    }

    array[size - 1] = -1;
}

int main() {
    const int MAX_ARRAY_SIZE = 100;
    int numbers[MAX_ARRAY_SIZE];
    std::size_t size, k;

    std::cin >> size;
    inputArray(numbers, size);
    std::cin >> k;

    removeAt(numbers, size, k);

    printArray(numbers, size);

    return 0;
}
