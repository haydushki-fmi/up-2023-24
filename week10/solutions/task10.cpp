#include <iostream>

void
findElement(int *matrix[], std::size_t rows, std::size_t columns, int element, std::size_t &row, std::size_t &column) {
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < columns; j++) {
            if (matrix[i][j] == element) {
                row = i;
                column = j;
                return; // Stop at first occurrence
            }
        }
    }
}

int **createMatrix(std::size_t rows, std::size_t columns) {
    int **matrix = new int *[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[columns];
    }

    std::cout << "Enter matrix elements:\n";
    for (std::size_t i = 0; i < rows; ++i) {
        for (std::size_t j = 0; j < columns; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    return matrix;
}

void freeMatrix(int **matrix, std::size_t rows) {
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }

    delete[] matrix;
}

int main(int argc, char **argv) {
    std::cout << "Enter matrix dimensions:\t";
    std::size_t rows, cols;
    std::cin >> rows >> cols;

    int **matr = createMatrix(rows, cols);

    std::size_t resultRow, resultColumn;

    std::cout << "Enter element to find:\t";
    int elem;
    std::cin >> elem;
    findElement(matr, rows, cols, elem, resultRow, resultColumn);

    std::cout << resultRow << std::endl;
    std::cout << resultColumn << std::endl;

    freeMatrix(matr, rows);

    return 0;
}
