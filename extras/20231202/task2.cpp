#include <iostream>

/*
 * 0,0 0,1 0,2
 * 1,0 1,1 1,2
 * 2,0 2,1 2,2
 */

const std::size_t MAX_SIZE = 10;

void inputMatrix(int matr[][MAX_SIZE], std::size_t size) {
    for (std::size_t i = 0; i < size; ++i) {
        for (std::size_t j = 0; j < size; ++j) {
            std::cin >> matr[i][j];
        }
    }
}

void printMatrix(const int matr[][MAX_SIZE], std::size_t size) {
    for (std::size_t i = 0; i < size; ++i) {
        for (std::size_t j = 0; j < size; ++j) {
            std::cout << matr[i][j] << '\t';
        }
    }
    std::cout << std::endl;
}

int sumMainDiagonal(const int matr[][MAX_SIZE], std::size_t size) {
    int sum = 0;
    for (std::size_t i = 0; i < size; ++i) {
        for (std::size_t j = 0; j < size; ++j) {
            if (i == j) {
                sum += matr[i][j];
            }
        }
    }
    return sum;
}

int sumSecondaryDiagonal(const int matr[][MAX_SIZE], std::size_t size) {
    int sum = 0;
    for (std::size_t i = 0; i < size; ++i) {
        for (std::size_t j = 0; j < size; ++j) {
            if (i + j == size - 1) {
                sum += matr[i][j];
            }
        }
    }

    return sum;
}

int main() {
    int matrix[MAX_SIZE][MAX_SIZE];
    std::size_t size;
    std::cin >> size;

    inputMatrix(matrix, size);
    std::cout << sumSecondaryDiagonal(matrix, size);
    std::cout << std::boolalpha << (sumMainDiagonal(matrix, size) == sumSecondaryDiagonal(matrix, size)) << std::endl;

    return 0;
}
