#include <iostream>

void inputArray(unsigned arr[], std::size_t size) {
    for (std::size_t i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }
}

bool isInteresting(unsigned number) {
    // Докато имаме цифри в числото проверяваме условието.
    // Ако за някои две цифри то е нарушено, директно излизаме от фунцията с false,
    // защото няма смисъл да проверяваме повече.
    // Ако сме преминали през всички цифри, то значи условието е изпълнено.
    while (number > 0) {
        if (number % 10 < number / 10 % 10) {
            return false;
        }
        number /= 10;
    }

    return true;
}

int main() {
    const std::size_t MAX_SIZE = 1000;
    unsigned arr[MAX_SIZE];

    std::size_t n;
    std::cin >> n;

    inputArray(arr, n);
    for (std::size_t i = 0; i < n; ++i) {
        std::cout << (isInteresting(arr[i]) ? "YES" : "NO") << std::endl;
    }

    return 0;
}
