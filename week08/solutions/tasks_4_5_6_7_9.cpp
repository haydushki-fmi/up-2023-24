#include <cstddef>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

using std::size_t;


static size_t readNUpTo(size_t limit) {
  cout << "Enter a natural number <= " << limit << ":\t";
  size_t n = 0;
  cin >> n;
  while (n > limit) {
    std::cerr << n << " > " << limit << "; try again:\t";
    cin >> n;
  }
  return n;
}

/*----------------------------------------------------------------------------*/

constexpr size_t MAX_ARRAY_SIZE = 1000;

void printLoop(size_t arr[], size_t startingIndex) {
  bool visited[MAX_ARRAY_SIZE] = {false};
  size_t currentIndex = startingIndex;

  while (!visited[currentIndex]) {
    visited[currentIndex] = true;

    size_t currentValue = arr[currentIndex];
    cout << currentValue << ' ';
    currentIndex = currentValue;
  }

  cout << endl;
}

void task4() {
  size_t n = readNUpTo(MAX_ARRAY_SIZE);

  cout << "Now enter " << n << " natural numbers <= " << n << ":\n";
  size_t indices[MAX_ARRAY_SIZE] = {0};
  for (size_t i = 0; i < n; ++i) {
    cin >> indices[i];
  }

  size_t firstStartIndex = readNUpTo(MAX_ARRAY_SIZE);
  size_t secondStartIndex = readNUpTo(MAX_ARRAY_SIZE);

  cout << "The loop starting at index " << firstStartIndex << " is:\n";
  printLoop(indices, firstStartIndex);

  cout << "The loop starting at index " << secondStartIndex << " is:\n";
  printLoop(indices, secondStartIndex);
}

/*----------------------------------------------------------------------------*/

void swap(unsigned arr[], size_t i, size_t j) {
  unsigned buffer = arr[i];
  arr[i] = arr[j];
  arr[j] = buffer;
}

void selectionSort(unsigned arr[], size_t size) {
  for (size_t i = 0; i < size - 1; ++i) {
    size_t minIndex = i;
    for (size_t j = i + 1; j < size; ++j) {
      if (arr[j] < arr[minIndex]) {
        minIndex = j;
      }
    }
    swap(arr, i, minIndex);
  }
}

void printArray(unsigned arr[], size_t size) {
  for (size_t i = 0; i < size - 1; ++i) {
    cout << arr[i] << ' ';
  }
  cout << arr[size - 1] << endl;
}

void task5() {
  constexpr size_t MAX_ARRAY_SIZE = 255;
  size_t n = readNUpTo(MAX_ARRAY_SIZE);

  cout << "Now enter " << n << " natural numbers <= 4 000 000 000:\n";
  unsigned numbers[MAX_ARRAY_SIZE] = {0};
  for (size_t i = 0; i < n; ++i) {
    cin >> numbers[i];
  }

  selectionSort(numbers, n);
  cout << "The numbers sorted in ascending order are:\n";
  printArray(numbers, n);
}

/*----------------------------------------------------------------------------*/

void task6() {
  size_t n = readNUpTo(4000000000);

  cout << "Now enter " << n << " natural numbers <= 255:\n";
  unsigned counts[256] = {0};
  for (size_t i = 0; i < n; ++i) {
    unsigned currentNumber = 0;
    cin >> currentNumber;
    ++counts[currentNumber];
  }

  cout << "The numbers sorted in ascending order are:\n";
  for (size_t number = 0 ; number < 256; ++number) {
    for (size_t j = 0; j < counts[number]; ++j) {
      cout << number << ' ';
    }
  }
  cout << endl;
}

/*----------------------------------------------------------------------------*/

void task7() {
  constexpr size_t MAX_MATRIX_SIZE = 30;
  size_t n = readNUpTo(MAX_MATRIX_SIZE);

  cout << "Now enter " << n << " lines with ";
  cout << n << " natural numbers each:\n";
  unsigned matrix[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE] = {0};
  for (size_t i = 0; i < n; ++i) {
    for (size_t j = 0; j < n; ++j) {
      cin >> matrix[i][j];
    }
  }

  for (size_t i = 0; i < n; ++i) {
    for (size_t j = 0; j < n; ++j) {
      const unsigned oldValue = matrix[i][j];
      matrix[i][j] = oldValue * i + j;
    }
  }

  cout << "The modified matrix is:\n";
  for (size_t i = 0; i < n; ++i) {
    printArray(matrix[i], n);
  }
}

/*----------------------------------------------------------------------------*/

void task9() {
  constexpr size_t MAX_MATRIX_SIZE = 30;
  size_t n = readNUpTo(MAX_MATRIX_SIZE);

  cout << "Now enter " << n << " lines with ";
  cout << n << " real numbers each:\n";
  double matrix[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE] = {0.0};
  for (size_t i = 0; i < n; ++i) {
    for (size_t j = 0; j < n; ++j) {
      cin >> matrix[i][j];
    }
  }

  double squaredMatrix[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE] = {0.0};
  for (size_t i = 0; i < n; ++i) {
    for (size_t j = 0; j < n; ++j) {
      for (size_t k = 0; k < n; ++k) {
        squaredMatrix[i][j] += matrix[i][k] * matrix[k][j];
      }
    }
  }

  cout << "The squared matrix is:\n";
  for (size_t i = 0; i < n; ++i) {
    for (size_t j = 0; j < n; ++j) {
      cout << squaredMatrix[i][j] << ' ';
    }
    cout << endl;
  }
}

/*----------------------------------------------------------------------------*/

int main() {
  cout << "Task 4\n";
  task4();

  cout << "Task 5\n";
  task5();

  cout << "Task 6\n";
  task6();

  cout << "Task 7\n";
  task7();

  cout << "Task 9\n";
  task9();

  return 0;
}
