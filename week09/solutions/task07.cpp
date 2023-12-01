#include <iostream>

const std::size_t MAX_SIZE = 30;

bool zeroesUnderMainDiagonal(const int matr[][MAX_SIZE], std::size_t size) {
    for (std::size_t i = 0; i < size; ++i) {
        for (std::size_t j = 0; j < i; ++j) {
            if (matr[i][j] != 0) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    const int valid[][MAX_SIZE] = {{1, 2, 3},
                                   {0, 4, 5},
                                   {0, 0, 6}};

    const int invalid[][MAX_SIZE] = {{1, 2, 3},
                                     {0, 4, 5},
                                     {1, 0, 6}};

    const int one[][MAX_SIZE] = {{0}};

    std::cout << std::boolalpha;
    std::cout << zeroesUnderMainDiagonal(valid, 3) << std::endl;
    std::cout << zeroesUnderMainDiagonal(invalid, 3) << std::endl;
    std::cout << zeroesUnderMainDiagonal(one, 1) << std::endl;

    return 0;
}
