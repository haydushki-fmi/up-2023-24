#include <iostream>

int findMin1(int *begin, int *end) {
    if (begin == end) {
        return *begin;
    }

    int min = findMin1(begin + 1, end);
    if (*begin < min) {
        return *begin;
    }
    return min;
}

int findMin2(int *begin, int *end) {
    if (begin == end) {
        return *begin;
    }

    return std::min(*begin, findMin2(begin + 1, end));
}

int main(int argc, char **argv) {
    int a[] = {1, -2, 3, 0, 5, -6, 7};
    unsigned size = sizeof(a) / sizeof(int);
    std::cout << findMin1(a, a + size) << std::endl;
    std::cout << findMin2(a, a + size) << std::endl;
    return 0;
}
