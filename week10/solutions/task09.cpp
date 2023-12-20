#include <iostream>

int *createArray(std::size_t size) {
    int *arr = new int[size];

    std::cout << "Enter elements of array:\n";
    for (std::size_t i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }

    return arr;
}

bool containsElements(int arr1[], std::size_t size1, int arr2[], std::size_t size2) {
    // За улеснение приемаме, че винаги първият масив ще е с по-малко елементи от втория
    if (size1 > size2) {
        return false;
    }

    for (std::size_t i = 0; i < size1; ++i) {
        std::size_t j = 0;
        for (; j < size2; ++j) {
            // Ако намерим елемента във втория масив, няма нужда да търсим повече
            if (arr1[i] == arr2[j]) {
                break;
            }
        }
        // За дадения елемент от първия масив сме преминали през целия втори масив и сме стигнали края, без да го открием
        if (j == size2) {
            return false;
        }
    }

    return true;
}

int main(int argc, char **argv) {
    int *arr1;
    int *arr2;
    std::size_t size1, size2;

    std::cin >> size1 >> size2;

    arr1 = createArray(size1);
    arr2 = createArray(size2);

    std::cout << containsElements(arr1, size1, arr2, size2) << std::endl;

    delete[] arr1;
    delete[] arr2;

    return 0;
}
