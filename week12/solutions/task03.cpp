#include <iostream>

using namespace std;

unsigned sumHelper(unsigned i, unsigned n, unsigned k) {
    if (i > n) {
        return 0;
    }

    return i + sumHelper(i + k, n, k);
}

unsigned sumVariant1(unsigned n, unsigned k) {
    return sumHelper(1, n, k);
}

// With global variable
unsigned currentNum = 1;

unsigned sumVariant2(unsigned n, unsigned k) {
    if (currentNum > n) {
        return 0;
    }

    unsigned tempNum = currentNum;
    currentNum += k;
    return tempNum + sumVariant2(n, k);
}

int main(int argc, char **argv) {
    const unsigned n = 11;
    const unsigned k = 3;
    const unsigned i = 1;

    cout << sumHelper(i, n, k) << std::endl;
    cout << sumVariant1(n, k) << std::endl;
    cout << sumVariant2(n, k) << std::endl;
    return 0;
}
