#include <iostream>

const std::size_t MAX_ROWS = 256;
const std::size_t MAX_COLS = 256;

void inputMatrix(int matr[][MAX_COLS], std::size_t rows, std::size_t cols) {
    for (std::size_t row = 0; row < rows; ++row) {
        for (std::size_t col = 0; col < cols; ++col) {
            std::cin >> matr[row][col];
        }
    }
}

void printMatrix(int matr[][MAX_COLS], std::size_t rows, std::size_t cols) {
    for (std::size_t row = 0; row < rows; ++row) {
        for (std::size_t col = 0; col < cols; ++col) {
            std::cout << matr[row][col] << '\t';
        }
        std::cout << std::endl;
    }
}

int productRow(int matr[][MAX_COLS], std::size_t rowIndex, std::size_t cols) {
    int product = 1;
    for (std::size_t col = 0; col < cols; ++col) {
        product *= matr[rowIndex][col];
    }

    return product;
}

void swapRows(int matr[][MAX_COLS], std::size_t rowIndex1, std::size_t rowIndex2, std::size_t cols) {
    int temp[MAX_COLS];
    for (std::size_t i = 0; i < cols; ++i) {
        temp[i] = matr[rowIndex1][i];
    }
    for (std::size_t i = 0; i < cols; ++i) {
        matr[rowIndex1][i] = matr[rowIndex2][i];
    }
    for (std::size_t i = 0; i < cols; ++i) {
        matr[rowIndex2][i] = temp[i];
    }
}

void sort(int matr[][MAX_COLS], std::size_t rows, std::size_t cols) {
    for (std::size_t i = 0; i < rows; ++i) {
        for (std::size_t j = 0; j < rows - 1; ++j) {
            if (productRow(matr, j, cols) > productRow(matr, j + 1, cols)) {
                swapRows(matr, j, j + 1, cols);
            }
        }
    }
}

int main() {
    int matrix[MAX_ROWS][MAX_COLS];
    std::size_t rows;
    std::size_t cols;
    std::cin >> rows >> cols;

    inputMatrix(matrix, rows, cols);
    sort(matrix, rows, cols);
    printMatrix(matrix, rows, cols);

    return 0;
}
