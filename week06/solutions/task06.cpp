#include <iostream>

// Използваме задача 7 от предния път.
unsigned findGCD(unsigned a, unsigned b)
{
    int gcd = (a < b) ? a : b;

    while(gcd > 0){
        if(a % gcd == 0 && b % gcd == 0) {
            return gcd;
        }
        gcd--;
    }

    return 1;
}

unsigned findLCM(unsigned a, unsigned b) {
    return a * b / findGCD(a, b);
}

int main() {
    unsigned a, b;
    std::cin >> a >> b;

    std::cout << findLCM(a, b) << std::endl;

    return 0;
}
