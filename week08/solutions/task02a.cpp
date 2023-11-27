#include <iostream>

const int MAX_ARRAY_SIZE = 100;

int charToInt(char ch) {
    return ch - '0';
}

std::size_t inputArray(int array[]) {
    char ch;
    std::size_t i = 0;
    do {
        std::cin >> ch;
        array[i] = charToInt(ch);
        ++i;
    } while (ch != '#' && i < MAX_ARRAY_SIZE);

    return i - 1;
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
    int numbers[MAX_ARRAY_SIZE];
    std::size_t size, k;
    size = inputArray(numbers);

    std::cin >> k;

    removeAt(numbers, size, k);

    printArray(numbers, size);

    return 0;
}
