#include <iostream>

const std::size_t MAX_SIZE = 100;

void inputArray(int array[], std::size_t size) {
    for (std::size_t i = 0; i < size; ++i) {
        std::cin >> array[i];
    }
}

void shiftRight(int array[], std::size_t size) {
    int lastElement = array[size - 1];

    for (std::size_t i = size - 1; i > 0; --i) {
        array[i] = array[i - 1];
    }

    array[0] = lastElement;
}

void shiftRightBy(int array[], std::size_t size, std::size_t positions) {
    for (std::size_t i = 0; i < positions; ++i) {
        shiftRight(array, size);
    }
}

void printArray(const int array[], std::size_t size) {
    for (std::size_t i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::size_t n, positions;
    int array[MAX_SIZE];

    std::cin >> n;
    inputArray(array, n);

    std::cin >> positions;

    // Когато преместваме с n на брой позици, получаваме същото.
    positions %= n;

    shiftRightBy(array, n, positions);

    printArray(array, n);

    return 0;
}

