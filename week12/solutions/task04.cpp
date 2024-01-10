#include <iostream>

unsigned findDigitCount(unsigned number, unsigned digit) {
    if (number == 0) {
        return 0;
    }

    if (number % 10 == digit) {
        return 1 + findDigitCount(number / 10, digit);
    }
    return 0 + findDigitCount(number / 10, digit);
}

// With counter:
unsigned findDigitCount2(int number, unsigned digit, unsigned count) {
    if (number == 0) {
        return count;
    }
    if (number % 10 == digit) {
        count++;
    }
    return findDigitCount2(number / 10, digit, count);
}

unsigned findDigitCount2(int number, unsigned digit) {
    return findDigitCount2(number, digit, 0);
}


int main(int argc, char **argv) {
    std::cout << findDigitCount(20240105, 0) << std::endl;
    std::cout << findDigitCount2(20240105, 0) << std::endl;
    return 0;
}
