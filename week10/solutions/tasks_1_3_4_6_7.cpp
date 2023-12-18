#include <cmath>
#include <cstddef>
#include <iostream>

using std::abs;

using std::cin;
using std::cout;
using std::endl;

using std::size_t;


// Don't forget to `delete[]` the result when you're done with it!
double* inputDoubleArray(/*out*/ size_t& size) {
  cout << "Enter a natural number N, the array's size:\t";
  cin >> size;

  cout << "Now enter " << size << " real numbers:\n";
  double* numbers = new double[size];
  for (size_t i = 0; i < size; ++i) {
    cin >> numbers[i];
  }

  return numbers;
}

// Don't forget to clean up the result when you're done with it by calling
// `freeMatrix`!
double** inputDoubleMatrix(/*out*/ size_t& rows, /*out*/ size_t& cols) {
  cout << "Enter the numbers of rows and columns:\t";
  cin >> rows >> cols;

  cout << "Now enter " << rows << " rows of " << cols << " real numbers:\n";
  double** matrix = new double*[rows];

  for (size_t i = 0; i < rows; ++i) {
    matrix[i] = new double[cols];
    
    for (size_t j = 0; j < cols; ++j) {
      cin >> matrix[i][j];
    }
  }

  return matrix;
}

double calculateSum(const double* const arr, size_t size) {
  double sum = 0.0;
  for (size_t i = 0; i < size; ++i) {
    sum += arr[i];
  }
  return sum;
}

void freeMatrix(double** matrix, size_t rows) {
  for (size_t i = 0; i < rows; ++i) {
    delete[] matrix[i];
  }
  delete[] matrix;
}

/*----------------------------------------------------------------------------*/

void task1() {
  size_t size = 0;
  double* numbers = inputDoubleArray(size);

  cout << "Here's every second number in reverse order:\n";
  for (size_t i = 0; i < size; i += 2) {
    cout << numbers[size - 1 - i] << ' ';
  }
  cout << endl;

  delete[] numbers;
}

/*----------------------------------------------------------------------------*/

double calculateAverage(const double* arr, size_t size) {
  return calculateSum(arr, size) / size;
}

void printClosestToAndFarthestFromValue(
  const double* arr, size_t size, double value
) {
  if (size < 1) {
     cout << "The array is empty." << endl;
     return;
  }

  size_t closestIndex = 0;
  size_t farthestIndex = 0;
  double distanceToClosest = abs(arr[closestIndex] - value);
  double distanceToFarthest = distanceToClosest;

   for (size_t i = 1; i < size; ++i) {
     double currentDifference = abs(arr[i] - value);
     if (currentDifference > distanceToFarthest) {
       distanceToFarthest = currentDifference;
       farthestIndex = i;
     }
     else if (currentDifference < distanceToClosest) {
       distanceToClosest = currentDifference;
       closestIndex = i;
     }
   }

  cout << "The farthest value is " << arr[farthestIndex];
  cout << "; the closest is " << arr[closestIndex] << endl;
}

void task3() {
  size_t size = 0;
  double* numbers = inputDoubleArray(size);

  double average = calculateAverage(numbers, size);
  cout << "The average of the numbers is " << average << endl;

  printClosestToAndFarthestFromValue(numbers, size, average); 

  delete[] numbers;
}

/*----------------------------------------------------------------------------*/

void task4() {
  size_t size = 0;
  double* numbers = inputDoubleArray(size);

  size_t fibonacciPrevious = 1;
  size_t fibonacciCurrent = 1;
  double sum = 0.0;

  while (fibonacciCurrent < size) {
    sum += numbers[fibonacciCurrent];

    size_t fibonacciNext = fibonacciCurrent + fibonacciPrevious;
    fibonacciPrevious = fibonacciCurrent;
    fibonacciCurrent = fibonacciNext;
  }
  cout << "The sum of the elements whose indices are Fibonacci numbers is ";
  cout << sum << endl;

  delete[] numbers;
}

/*----------------------------------------------------------------------------*/

void swap(size_t& left, size_t& right) {
  size_t buffer = left;
  left = right;
  right = buffer;
}

// Returns the row numbers (i.e., their indices) sorted according to the sums
// of their corresponding rows in `matrix`, in ascending order.
// The resulting array has size `rows`.
// Don't forget to `delete[]` it when you're done with it!
size_t* sortedRowNumbers(
  const double* const* const matrix, size_t rows, size_t cols
) {
  size_t* rowNumbers = new size_t[rows];
  double* rowSums = new double[rows];
  
  for (size_t i = 0; i < rows; ++i) {
    rowNumbers[i] = i;
    rowSums[i] = calculateSum(matrix[i], cols);
  }

  for (size_t i = 0; i < rows - 1; ++i) {
    size_t minIndex = i;
    double minSum = rowSums[rowNumbers[i]];

    for (size_t j = i+1; j < rows; ++j) {
      if (rowSums[rowNumbers[j]] < minSum) {
        minIndex = j;
        minSum = rowSums[rowNumbers[j]];
      }
    }
    swap(rowNumbers[i], rowNumbers[minIndex]);
  }

  delete[] rowSums;
  return rowNumbers;
}

void task6() {
  size_t rows = 0, cols = 0;
  double** matrix = inputDoubleMatrix(rows, cols);

  size_t* sortedRows = sortedRowNumbers(matrix, rows, cols);
  cout << "The matrix with rows sorted in ascending order of their sums is:\n";
  for (size_t i = 0; i < rows; ++i) {
    for (size_t j = 0; j < cols; ++j) {
      cout << matrix[sortedRows[i]][j] << ' ';
    }
    cout << endl;
  }

  delete[] sortedRows;
  freeMatrix(matrix, rows);
}

/*----------------------------------------------------------------------------*/

// Returns pointers to the rows in `matrix` sorted according to their sums,
// in ascending order.
// The resulting array has size `rows`.
// Don't forget to `delete[]` it when you're done with it!
const double** sorted(
  const double* const* const matrix, size_t rows, size_t cols
) {
  const double** result = new const double*[rows];
  size_t* sortedRows = sortedRowNumbers(matrix, rows, cols);

  for (size_t i = 0; i < rows; ++i) {
    result[i] = matrix[sortedRows[i]];
  }

  delete[] sortedRows;
  return result;
}

void task7() {
  size_t rows = 0, cols = 0;
  double** matrix = inputDoubleMatrix(rows, cols);

  const double** sortedMatrix = sorted(matrix, rows, cols);
  cout << "The matrix with rows sorted in ascending order of their sums is:\n";
  for (size_t i = 0; i < rows; ++i) {
    for (size_t j = 0; j < cols; ++j) {
      cout << sortedMatrix[i][j] << ' ';
    }
    cout << endl;
  }

  delete[] sortedMatrix;
  freeMatrix(matrix, rows);
}

/*----------------------------------------------------------------------------*/

int main() {
  cout << "Task 1\n";
  task1();

  std::cout << "Task 3\n";
  task3();

  std::cout << "Task 4\n";
  task4();

  std::cout << "Task 6\n";
  task6();

  std::cout << "Task 7\n";
  task7();

  return 0;
}
