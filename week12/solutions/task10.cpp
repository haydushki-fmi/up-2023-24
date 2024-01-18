#include <iostream>
#include <cstddef>

using std::cin;
using std::cout;
using std::endl;

using std::size_t;


unsigned** ReadMatrix(size_t& rows, size_t& cols) {
    cout << "Enter the matrix's size (rows, then columns):\t";
    cin >> rows >> cols;

    cout << "Now enter its elements:\n";
    unsigned** matrix = new unsigned* [rows];

    for (size_t i = 0; i < rows; ++i) {
        matrix[i] = new unsigned[cols];

        for (size_t j = 0; j < cols; ++j) {
            cin >> matrix[i][j];
        }
    }

    return matrix;
}

void FreeMatrix(unsigned** matrix, size_t rows) {
    for (size_t i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void FreeMatrix(bool** matrix, size_t rows) {
    for (size_t i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int neighbors[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

size_t endRow = 0, endCol = 0;

bool FindPathInternal(
    const unsigned* const* matrix, bool** visited,
    size_t rows, size_t cols,
    size_t startRow, size_t startCol
) {
    if (startRow == endRow && startCol == endCol) {
        cout << '(' << endRow << ", " << endCol << ") ";
        return true;
    }

    for (size_t i = 0; i < 4; ++i) {
        long long int nextRow = startRow + neighbors[i][0];
        long long int nextCol = startCol + neighbors[i][1];

        if (nextRow >= 0 && nextRow < rows &&
            nextCol >= 0 && nextCol < cols &&
            matrix[nextRow][nextCol] > 0 &&
            !visited[nextRow][nextCol])
        {
            visited[nextRow][nextCol] = true;
            if (FindPathInternal(matrix, visited, rows, cols, nextRow, nextCol)) {
                cout << '(' << startRow << ", " << startCol << ") ";
                return true;
            }
            visited[nextRow][nextCol] = false;
        }
    }
    return false;
}

void FindPath(
    const unsigned* const* matrix,
    size_t rows, size_t cols,
    size_t startRow, size_t startCol
) {
    bool** visited = new bool* [rows];
    for (size_t i = 0; i < rows; ++i) {
        visited[i] = new bool[cols] {false, };
    }

    // Reverse start and end in order to print in the correct order when unwinding the
    // recursion stack.
    size_t buffer = startRow;
    startRow = endRow;
    endRow = buffer;
    buffer = startCol;
    startCol = endCol;
    endCol = buffer;

    visited[startRow][startCol] = true;
    if (!FindPathInternal(matrix, visited, rows, cols, startRow, startCol)) {
        cout << "No path exists.\n";
    }

    FreeMatrix(visited, rows);
}

int main()
{
    size_t n = 0, m = 0;
    unsigned** matrix = ReadMatrix(n, m);

    cout << "Enter the initial field's coordinates, Row then Col:\t";
    size_t startRow = 0, startCol = 0;
    cin >> startRow >> startCol;

    cout << "Enter the target field's coordinates, Row then Col:\t";
    cin >> endRow >> endCol;

    FindPath(matrix, n, m, startRow, startCol);

    FreeMatrix(matrix, n);
    return 0;
}
