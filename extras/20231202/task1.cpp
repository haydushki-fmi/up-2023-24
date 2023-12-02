#include <iostream>

const std::size_t MAX_SIZE = 3000;

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

int sumOfPositiveNumbersArr(const int arr[], std::size_t size) {
    int sum = 0;
    for (std::size_t i = 0; i < size; ++i) {
        if (arr[i] > 0) {
            sum += arr[i];
        }
    }

    return sum;
}

void compressMoreThan3(int arr[], std::size_t size, std::size_t from, unsigned count) {
    for (std::size_t i = from; i < size - count; ++i) {
        arr[i] = arr[i + count];
    }
}

void findDuplicates(int arr[], std::size_t &size) {
    int sum = sumOfPositiveNumbersArr(arr, size);
    int current = arr[0];
    int count = 0;
    for (std::size_t i = 1; i < size; ++i) {
        if (arr[i] == current) {
            count++;
            if (i == size - 1 && count >= 2) {
                compressMoreThan3(arr, size, i - count, count);
                size -= count;
                arr[i - count] = sum;
            }
        } else {
            if (count >= 2) {
                compressMoreThan3(arr, size, i - count, count);
                size -= count;
                i -= count + 1;
                arr[i] = sum;
            }
            current = arr[i];
            count = 0;
        }
    }
}

int main() {
    int array[MAX_SIZE];
    std::size_t size;
    std::cin >> size;

    inputArray(array, size);
    findDuplicates(array, size);
    printArray(array, size);


    return 0;
}
