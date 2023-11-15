#include <iostream>

// В задачата се иска да се пресметне биномният коефициент n над k.
// Вместо да използваме формулата с факториел (която е лесна
// за хора, но бавна за компютри), ще използваме друга:
// https://en.wikipedia.org/wiki/Binomial_coefficient#Multiplicative_formula
unsigned choose(unsigned n, unsigned k) {
    unsigned result = 1;

    for(int i = 1; i <= k; ++i) {
        result *= (n + 1 - i);
        result /= i; // Това е отделно, защото иначе в някои случаи губим точност
    }

    return result;
}

int main() {
    unsigned n, k;
    std::cin >> n >> k;

    std::cout << choose(n, k) << std::endl;
    return 0;
}
