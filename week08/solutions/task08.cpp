#include <iostream>

const std::size_t MAX_COLS = 100;
const std::size_t MAX_ROWS = 100;

void inputMatrix(int matr[][MAX_COLS], std::size_t rows, std::size_t columns) {
    for (std::size_t i = 0; i < rows; ++i) {
        for (std::size_t j = 0; j < columns; ++j) {
            std::cin >> matr[i][j];
        }
    }
}

void printMatrix(const int matr[][MAX_COLS], std::size_t rows, std::size_t columns) {
    for (std::size_t i = 0; i < rows; ++i) {
        for (std::size_t j = 0; j < columns; ++j) {
            std::cout << matr[i][j] << '\t';
        }
        std::cout << std::endl;
    }
}

void transposeMatrix(const int matrix[][MAX_COLS], std::size_t rows, std::size_t columns, int result[][MAX_ROWS]) {
    for (std::size_t i = 0; i < rows; ++i) {
        for (std::size_t j = 0; j < columns; ++j) {
            result[j][i] = matrix[i][j];
        }
    }
}

int main() {
    int matrix[MAX_ROWS][MAX_COLS];
    int result[MAX_COLS][MAX_ROWS];
    std::size_t rows, cols;

    std::cin >> rows >> cols;
    inputMatrix(matrix, rows, cols);
    printMatrix(matrix, rows, cols);

    transposeMatrix(matrix, rows, cols, result);
    printMatrix(result, cols, rows);

    return 0;
}
