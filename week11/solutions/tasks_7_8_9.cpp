#include <cstddef>
#include <cstring>
#include <iostream>


using std::cout;
using std::endl;

using std::size_t;


/*----------------------------------------------------------------------------*/

// Don't forget to `delete[]` the result when you're done with it!
char* concatAll(const char** stringArray, size_t arraySize) {
  size_t resultSize = 1;
  for (size_t i = 0; i < arraySize; ++i) {
    resultSize += strlen(stringArray[i]);
  }

  char* result = new char[resultSize];
  result[0] = '\0';

  for (size_t i = 0; i < arraySize; ++i) {
    strcat(result, stringArray[i]);
  }
  return result;
}

void task7() {
  const char* stringArray[] = {"Hello", ",", " ", "World", "!"};
  size_t arraySize = sizeof(stringArray) / sizeof(stringArray[0]);

  char* allConcatenated = concatAll(stringArray, arraySize);
  cout << allConcatenated << endl;
  delete[] allConcatenated;
}

/*----------------------------------------------------------------------------*/

// Expects an array of pointers. Modifies it by reordering the pointers, but
// does not modify the strings they represent.
void sortLexicographically(const char** stringArray, size_t arraySize) {
  for (size_t i = 0; i < arraySize - 1; ++i) {
    for (size_t j = i + 1; j < arraySize; ++j) {
      if (strcmp(stringArray[j], stringArray[i]) < 0) {
        const char* buffer = stringArray[i];
        stringArray[i] = stringArray[j];
        stringArray[j] = buffer;
      }
    }
  }
}

void task8() {
  const char* stringArray[] = {"def", "z", "abc", "ab", "d", "ef"};
  size_t n = sizeof(stringArray) / sizeof(const char*);
  sortLexicographically(stringArray, n);

  for (size_t i = 0; i < n; ++i) {
    cout << stringArray[i] << ' ';
  }
  cout << endl;
}

/*----------------------------------------------------------------------------*/

bool isPalindrome(const char* string) {
  size_t i = 0, j = strlen(string) - 1;
  while (i < j) {
    if (string[i++] != string[j--]) {
      return false;
    }
  }
  return true;
}

size_t countPalindromesAboveMainDiagonal(
  const char*** squareStringMatrix, size_t matrixSize
) {
  size_t result = 0;
  for (size_t row = 0; row < matrixSize - 1; ++row) {
    for (size_t col = row + 1; col < matrixSize; ++col) {
      if (isPalindrome(squareStringMatrix[row][col])) {
        ++result;
      }
    }
  }
  return result;
}

void task9() {
  const char*** squareStringMatrix = new const char**[3];
  squareStringMatrix[0] = new const char*[]{"abc", "defed", "ghiihg"};
  squareStringMatrix[1] = new const char*[]{"jkl", "mno", "pqrpqp"};
  squareStringMatrix[2] = new const char*[]{"stu", "vwx", "yz"};

  size_t palindromesAboveMainDiagonal = countPalindromesAboveMainDiagonal(
    squareStringMatrix, 3
  );
  cout << palindromesAboveMainDiagonal;
  cout << " palindromes above the main diagonal" << endl;

  delete[] squareStringMatrix[0];
  delete[] squareStringMatrix[1];
  delete[] squareStringMatrix[2];
  delete[] squareStringMatrix;
}

/*----------------------------------------------------------------------------*/

int main() {
  cout << "Task 7\n";
  task7();

  cout << "Task 8\n";
  task8();

  cout << "Task 9\n";
  task9();

  return 0;
}
