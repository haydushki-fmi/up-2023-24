#include <iostream>

void printTable(int n){
    for(int i = 1; i <= n; ++i){
        // Отместването отляво
        for(int j = 0; j < i - 1; ++j)
        {
            std::cout << '\t';
        }

        // Забелязваме, че има две табулации между числата.
        for(int j = i; j <= n; ++j){
            std::cout << (i * j) << "\t\t";
        }
        std::cout << std::endl;
    }
}

int main() {
    int n;
    std::cin >> n;

    printTable(n);

    return 0;
}
