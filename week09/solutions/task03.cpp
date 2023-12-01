#include <iostream>

const std::size_t MAX_ROWS = 100;
const std::size_t MAX_COLS = 100;

void multiplyMatrices(const int matr1[][MAX_COLS], std::size_t rows1, std::size_t cols1, int matr2[][MAX_ROWS],
                      std::size_t rows2, std::size_t cols2, int result[][MAX_ROWS]) {
    if (cols1 != rows2) {
        std::cout << "Invalid arguments!\n";
        return;
    }

    for (std::size_t i = 0; i < rows1; ++i) {
        for (std::size_t j = 0; j < cols2; ++j) {
            for (std::size_t k = 0; k < cols1; ++k) {
                result[i][j] += matr1[i][k] * matr2[k][j];
            }
        }
    }
}

int main() {
    int matr1[][MAX_COLS] = {{1, 2},
                             {3, 4},
                             {5, 6}};
    int matr2[][MAX_ROWS] = {{1, 2, 3, 4},
                             {5, 6, 7, 8}};

    int res[MAX_ROWS][MAX_COLS] = {{0}};

    multiplyMatrices(matr1, 3, 2, matr2, 2, 4, res);

    // Очакван резултат:
    // 11 14 17 20
    // 23 30 37 44
    // 35 46 57 68
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            std::cout << res[i][j] << ' ';
        }
        std::cout << std::endl;
    }

    return 0;
}
