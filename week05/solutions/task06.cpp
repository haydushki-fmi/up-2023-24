#include <iostream>

int getCount(){
    int sum = 0;
    int count = 0;
    int x;
    int k;

    std::cin >> k;

    do {
        std::cin >> x;
        sum += x;
        count++;
    } while (sum < k);

    return count;
}

int main() {
    std::cout << getCount() << std::endl;

    return 0;
}
