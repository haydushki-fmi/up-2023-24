#include <iostream>

void printSquares(const int x) {
    // По условие е строго неравенство, но ако искаме да се включи и квадрат равен на n, го правим нестрого.
    for(int i = 1; i * i <= x; ++i){
        std::cout << (i * i) << " ";
    }
}
int main() {
    int n;
    std::cin >> n;

    printSquares(n);

    return 0;
}
