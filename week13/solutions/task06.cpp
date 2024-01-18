#include <iostream>

typedef int (*OneParamFunction)(int);

void mapTD(int arr[], std::size_t size, OneParamFunction f) {
    for (size_t i = 0; i < size; i++) {
        arr[i] = f(arr[i]);
    }
}

void map(int arr[], std::size_t size, int (*f)(int)) {
    for (size_t i = 0; i < size; i++) {
        arr[i] = f(arr[i]);
    }
}

int addOne(int value) { return value + 1; }

void someOtherFunction(int value) { return; }

int main(int argc, char **argv) {
    int a[] = {1, 2, 3, 4};
    map(a, 4, addOne);
    // map(a, 4, someOtherFunction); // Compile error

    for (size_t i = 0; i < 4; i++) {
        std::cout << a[i] << std::endl;
    }

    return 0;
}
