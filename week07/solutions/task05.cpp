#include <iostream>

void inputArray(int arr[], std::size_t size) {
    for (std::size_t i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }
}

int main() {
    const std::size_t MAX_SIZE = 1000;
    int arr[MAX_SIZE];

    std::size_t n;
    std::cin >> n;

    if (n == 0) {
        std::cout << "Invalid input.\n";
        return 1;
    }

    inputArray(arr, n);

    if (n == 1) {
        // Когато числото е само едно, то съседи няма и условието е автоматично изпълнено.
        std::cout << 1 << std::endl;
        return 0;
    }

    if (n == 2) {
        // Ако двете числа са равни, то няма число, което да е по-голямо от съсед.
        // Ако не са, то едното със сигурност е по-голямо.
        std::cout << (arr[0] == arr[1] ? 0 : 1) << std::endl;
        return 0;
    }

    int count = 0;
    // Ако сме стигнали до тук, то със сигурност имаме поне 3 числа.
    // Проверяваме крайните две числа:
    if (arr[0] > arr[1]) {
        count += 1;
    }
    if (arr[n - 1] > arr[n - 2]) {
        count += 1;
    }

    // Проверяваме числлата с двама съседи:
    for (std::size_t i = 1; i < n - 1; ++i) {
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
            count += 1;
        }
    }

    std::cout << count << std::endl;

    return 0;
}
