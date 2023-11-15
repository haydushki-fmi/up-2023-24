#include <iostream>

bool isMagical(unsigned n) {
    unsigned sum = 0;
    for (unsigned i = 1; i < n; ++i) {
        if (n % i == 0) {
            sum += i;
        }
    }
    return sum == n;
}

int main() {
    unsigned a;
    std::cin >> a;
    std::cout << isMagical(a) << std::endl;

    return 0;
}
