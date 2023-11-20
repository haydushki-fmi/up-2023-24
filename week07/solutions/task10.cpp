#include <iostream>

const std::size_t MAX_SIZE = 100;

void inputArray(int array[], std::size_t size) {
    for (std::size_t i = 0; i < size; ++i) {
        std::cin >> array[i];
    }
}

int main() {
    std::size_t n;
    int arr[MAX_SIZE];
    int k;

    std::cin >> n;
    std::cin >> k;
    inputArray(arr, n);

    for (std::size_t i = 0; i < n - 1; ++i) {
        for (std::size_t j = i + 1; j < n; ++j) {
            if (arr[i] + arr[j] == k) {
                std::cout << arr[i] << " " << arr[j] << std::endl;
            }
        }
    }

    return 0;
}

