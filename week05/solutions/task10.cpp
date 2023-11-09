#include <iostream>

void printSpaces(int count) {
    for(int i = 0; i < count; ++i) {
        std::cout << ' ';
    }
}

void printHorizontal(int spaces, int stars) {
    printSpaces(spaces);

    for(int i = 0; i < stars; ++i) {
        std::cout << "* ";
    }
    std::cout << std::endl;
}

void printMidRow(int i, int n){
    printSpaces(n - i - 2);
    std::cout << '*';
    printSpaces(i);
    std::cout << '*';

    printSpaces(3 * n - 2);

    std::cout << '*';
    printSpaces(n - i - 3);
    std::cout << "*\n";
}

void printParallelogram(int n){
    // Първия ред
    printHorizontal(n - 1, 2 * n);

    // Междинни редове
    for(int i = 0; i < n - 2; ++i)
    {
        printMidRow( i, n);
    }

    // Последен ред
    printHorizontal(0, 2 * n);
}

int main() {
    int n;
    std::cin >> n;

    printParallelogram(n);

    return 0;
}
