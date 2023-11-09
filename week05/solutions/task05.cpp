#include <iostream>

int getSum(){
    int sum = 0;
    int x;

    do {
        std::cin >> x;
        sum += x;
    } while (x != 0);

    return sum;
}
int main() {
    std::cout << getSum() << std::endl;

    return 0;
}
