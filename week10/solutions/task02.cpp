#include <iostream>

int swapAndReturnPointers(int *a, int b) {
    int tmp = *a;
    *a = b;
    return tmp;
}

int swapAndReturnReferences(int &a, int b) {
    int old = a;
    a = b;
    return old;
}

int main(int argc, char **argv) {
    int a = 5;
    int b = 42;

    std::cout << "Output: " << swapAndReturnPointers(&a, b) << std::endl;
    std::cout << "A: " << a << std::endl;
    std::cout << "B: " << b << std::endl;

    int c = 7;
    int d = 244;

    std::cout << "Output: " << swapAndReturnReferences(c, d) << std::endl;
    std::cout << "C: " << c << std::endl;
    std::cout << "D: " << d << std::endl;
    return 0;
}
