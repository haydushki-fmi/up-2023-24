#include <iostream>

typedef bool (*IntPredicate)(int);

int *findFirst(int arr[], std::size_t size, IntPredicate p) {
    for (size_t i = 0; i < size; i++) {
        if (p(arr[i])) {
            return (arr + i);
        }
    }
    return nullptr;
}

bool isEven(int n) {
    return n % 2 == 0;
}

bool isNegative(int n) {
    return n < 0;
}

int main(int argc, char **argv) {
    int a[] = {1, 2, 3, 4};
    std::cout << *findFirst(a, 4, isEven) << std::endl;
    std::cout << std::boolalpha << (findFirst(a, 4, isNegative) == nullptr) << std::endl;

    return 0;
}
