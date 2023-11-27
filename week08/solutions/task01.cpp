#include <iostream>

const std::size_t MAX_SIZE = 100;
const double EPS = 0.00001;

void inputArray(int arr[], std::size_t size) {
    for (std::size_t i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }
}

void inputArray(double arr[], std::size_t size) {
    for (std::size_t i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }
}

void printArray(const int arr[], std::size_t size) {
    for (std::size_t i = 0; i < size; ++i) {
        std::cout << arr[i] << '\t';
    }
}

void printArray(const double arr[], std::size_t size) {
    for (std::size_t i = 0; i < size; ++i) {
        std::cout << arr[i] << '\t';
    }
}

bool areEqual(double a, double b) {
    return std::abs(a - b) < EPS;
}

void replace(int arr[], std::size_t size, int value, int replacement) {
    for (std::size_t i = 0; i < size; ++i) {
        if (arr[i] == value) {
            arr[i] = replacement;
        }
    }
}


void replace(double arr[], std::size_t size, double value, double replacement) {
    for (std::size_t i = 0; i < size; ++i) {
        if (areEqual(arr[i], value)) {
            arr[i] = replacement;
        }
    }
}

int main() {
    std::size_t n;
    int arr[MAX_SIZE];
    int p, r;

    std::cin >> n;
    inputArray(arr, n);

    std::cin >> p >> r;

    replace(arr, n, p, r);
    printArray(arr, n);

    return 0;
}

