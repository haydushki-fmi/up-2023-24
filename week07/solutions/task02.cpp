#include <iostream>

void inputArray(int arr[], std::size_t size) {
    for (std::size_t i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }
}

void printArray(const int arr[], std::size_t size) {
    for (std::size_t i = 0; i < size; ++i) {
        std::cout << arr[i] << '\t';
    }
}

int main() {
    const std::size_t MAX_SIZE = 100;
    int arr[MAX_SIZE];

    std::size_t n;
    std::cin >> n;

    inputArray(arr, n);
    printArray(arr, n);

    return 0;
}
