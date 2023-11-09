#include <iostream>

int findGCD(const int a, const int b)
{
    int gcd = (a < b) ? a : b; // Може да се използва и std::min()

    // Започваме от по-малкото от двете числа. Когато намерим делител на двете, спираме, като директно го връщаме.
    while(gcd > 0){
        if(a % gcd == 0 && b % gcd == 0) {
            return gcd;
        }
        gcd--;
    }

    return 1;
}

int main() {
    int x, y;
    std::cin >> x >> y;

    std::cout << findGCD(x, y) << std::endl;

    return 0;
}
