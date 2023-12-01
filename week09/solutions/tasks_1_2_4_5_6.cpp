#include <cmath>
#include <cstddef>
#include <iostream>

using std::abs;

using std::cin;
using std::cout;
using std::endl;

using std::size_t;

constexpr size_t MAX_SIZE = 30;


static void inputMatrix(
  unsigned matrix[][MAX_SIZE], size_t rows, size_t columns
) {
  for (size_t i = 0; i < rows; ++i) {
    for (size_t j = 0; j < columns; ++j) {
      cin >> matrix[i][j];
    }
  }
}

void inputDoubleArray(double arr[], size_t size) {
  for (size_t i = 0; i < size; ++i) {
    cin >> arr[i];
  }
}

void printUnsignedArray(const unsigned arr[], size_t size) {
  if (size > 1) {
    for (size_t i = 0; i < size - 1; ++i) {
      cout << arr[i] << ' ';
    }
  }
  if (size > 0) {
    cout << arr[size - 1];
  }
  cout << endl;
}

void printDoubleArray(const double arr[], size_t size) {
  if (size > 1) {
    for (size_t i = 0; i < size - 1; ++i) {
      cout << arr[i] << ' ';
    }
  }
  if (size > 0) {
    cout << arr[size - 1];
  }
  cout << endl;
}

bool areEqual(double a, double b, double precision) {
  return abs(a - b) < precision;
}

/*----------------------------------------------------------------------------*/

size_t countZeroes(unsigned arr[], size_t size) {
  size_t result = 0;
  for (size_t i = 0; i < size; ++i) {
    if (arr[i] == 0) {
      ++result;
    }
  }
  return result;
}

void task1() {
  cout << "Enter the number of rows M:\t";
  size_t m = 0;
  cin >> m;

  cout << "Enter the number of seats per row N:\t";
  size_t n = 0;
  cin >> n;

  if (m == 0 || n == 0) {
    m = 0;
    n = 0;
  }

  cout << "Enter the heights of the students in centimeters:\n";
  unsigned heights[MAX_SIZE][MAX_SIZE] = {0};
  inputMatrix(heights, m, n);

  unsigned tallestPerRow[MAX_SIZE] = {0};
  unsigned tallestPerColumn[MAX_SIZE] = {0};
  for (size_t i = 0; i < m; ++i) {
    for (size_t j = 0; j < n; ++j) {
      const unsigned currentHeight = heights[i][j];
      
      if (currentHeight > tallestPerRow[i]) {
        tallestPerRow[i] = currentHeight;
      }
      if (currentHeight > tallestPerColumn[j]) {
        tallestPerColumn[j] = currentHeight;
      }
    }
  }

  size_t emptyRows = countZeroes(tallestPerRow, m);
  size_t emptyColumns = countZeroes(tallestPerColumn, n);

  if (emptyRows <= emptyColumns) {
    cout << "The heights (in cm) of the tallest students in each row are:\n";
    printUnsignedArray(tallestPerRow, m);
  }
  if (emptyColumns <= emptyRows) {
    cout << "The heights (in cm) of the tallest students in each column are:\n";
    printUnsignedArray(tallestPerColumn, n);
  }
}

/*----------------------------------------------------------------------------*/

double sumArray(const double arr[], size_t size) {
  double result = 0.0;
  for (size_t i = 0; i < size; ++i) {
    result += arr[i];
  }
  return result;
}

void task2() {
  cout << "Enter the matrix's number of rows M and columns N:\t";
  size_t m = 0, n = 0;
  cin >> m >> n;

  cout << "Enter the matrix itself:\n";
  double matrix[MAX_SIZE][MAX_SIZE] = {0.0};
  for (size_t i = 0; i < m; ++i) {
    for (size_t j = 0; j < n; ++j) {
      cin >> matrix[i][j];
    }
  }

  cout << "The rows with positive sums are:\n";
  for (size_t i = 0; i < m; ++i) {
    if (sumArray(matrix[i], n) > 0.0) {
      printDoubleArray(matrix[i], n);
    }
  }
}

/*----------------------------------------------------------------------------*/

void task4() {
  cout << "Enter the array's size M:\t";
  size_t size = 0;
  cin >> size;

  cout << "Now enter the array itself:\n";
  double arr[MAX_SIZE] = {0.0};
  inputDoubleArray(arr, size);

  cout << "Enter the indices s and d and the number of elements n:\n";
  size_t source = 0, destination = 0, n = 0;
  cin >> source >> destination >> n;

  if (source > destination) {
    size_t buffer = source;
    source = destination;
    destination = buffer;
  }

  if (destination + n > size || source + n > destination) {
    cout << "Impossible." << endl;
    return;
  }

  for (size_t i = 0; i < n; ++i) {
    double buffer = arr[source + i];
    arr[source + i] = arr[destination + i];
    arr[destination + i] = buffer;
  }

  cout << "The resulting array is:\n";
  printDoubleArray(arr, size);
}

/*----------------------------------------------------------------------------*/

bool hasRepeatingValues(const double arr[], size_t size, double precision) {
  for (size_t i = 0; i < size - 1; ++i) {
    for (size_t j = i + 1; j < size; ++j) {
      if (areEqual(arr[i], arr[j], precision)) {
        return true;
      }
    }
  }
  return false;
}

void task5() {
  cout << "Enter the array's size:\t";
  size_t size = 0;
  cin >> size;

  cout << "Now enter the array itself:\n";
  double arr[MAX_SIZE] = {0.0};
  inputDoubleArray(arr, size);

  cout << "Enter the precision:\t";
  double precision = 0.0;
  cin >> precision;

  if (hasRepeatingValues(arr, size, precision)) {
    cout << "There are repeating numbers!" << endl;
  }
  else {
    cout << "No repeating numbers." << endl;
  }
}

/*----------------------------------------------------------------------------*/

void outputOnlyUniques(const double arr[], size_t size, double precision) {
  bool uniques[MAX_SIZE];
  for (size_t i = 0; i < size; ++i) {
    uniques[i] = true;
  }

  for (size_t i = 0; i < size - 1; ++i) {
    for (size_t j = i + 1; j < size; ++j) {
      if (areEqual(arr[i], arr[j], precision)) {
        uniques[i] = uniques[j] = false;
      }
    }
  }

  for (size_t i = 0; i < size; ++i) {
    if (uniques[i]) {
      cout << arr[i] << ' ';
    }
  }
  cout << endl;
}

void task6() {
  cout << "Enter the array's size:\t";
  size_t size = 0;
  cin >> size;

  cout << "Now enter the array itself:\n";
  double arr[MAX_SIZE] = {0.0};
  inputDoubleArray(arr, size);

  cout << "Enter the precision:\t";
  double precision = 0.0;
  cin >> precision;

  cout << "The unique numbers are:\n";
  outputOnlyUniques(arr, size, precision);
}

/*----------------------------------------------------------------------------*/

int main() {
  cout << "Task 1\n";
  task1();

  cout << "Task 2\n";
  task2();

  cout << "Task 4\n";
  task4();

  cout << "Task 5\n";
  task5();

  cout << "Task 6\n";
  task6();

  return 0;
}
