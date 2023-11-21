#include <cmath>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

constexpr size_t MAX_ARRAY_SIZE = 1000;
constexpr double EPSILON = 0.001;


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

void printInReverse(int numbers[], size_t count) {
  for (int i = count - 1; i >= 0; --i) {
    cout << numbers[i] << " ";
  }
  cout << endl;
}

void printEven(int numbers[], size_t count) {
  for (size_t i = 0; i < count; ++i) {
    if (numbers[i] % 2 == 0) {
      cout << numbers[i] << " ";
    }
  }
  cout << endl;
}

constexpr size_t NOT_FOUND = -1;
// Returns the index of the smallest of the first `count` elements of `numbers`.
// Returns `NOT_FOUND` if `count == 0`.
size_t findSmallest(int numbers[], size_t count) {
  if (count == 0) {
    return NOT_FOUND;
  }

  size_t indexOfSmallest = 0;
  for (size_t i = 1; i < count; ++i) {
    if (numbers[i] < numbers[indexOfSmallest]) {
      indexOfSmallest = i;
    }
  }
  return indexOfSmallest;
}

void task1() {
  size_t n = readNUpTo(MAX_ARRAY_SIZE);

  cout << "Now enter " << n << " integers:\n";
  int numbers[MAX_ARRAY_SIZE] = {0};
  for (size_t i = 0; i < n; ++i) {
    cin >> numbers[i];
  }

  cout << "The numbers in reverse order are:\n";
  printInReverse(numbers, n);

  cout << "The even numbers are:\n";
  printEven(numbers, n);

  size_t indexOfSmallest = findSmallest(numbers, n);
  if (indexOfSmallest != NOT_FOUND) {
    cout << "The smallest of them is " << numbers[indexOfSmallest] << ". ";
    cout << "Its index is " << indexOfSmallest << ".\n";
  }
}

/*----------------------------------------------------------------------------*/

unsigned countIn(double what, double where[], size_t size,
                 double precision = EPSILON) {
  unsigned result = 0;
  for (size_t i = 0; i < size; ++i) {
    if (std::abs(where[i] - what) < precision) {
      ++result;
    }
  }
  return result;
}

void task3() {
  size_t n = readNUpTo(MAX_ARRAY_SIZE);

  cout << "Now enter " << n << " real numbers:\n";
  double numbers[MAX_ARRAY_SIZE] = {0.0};
  for (size_t i = 0; i < n; ++i) {
    cin >> numbers[i];
  }

  cout << "Enter the number you're looking for:\t";
  double r = 0.0;
  cin >> r;

  cout << r << " can be found " << countIn(r, numbers, n);
  cout << " times in the array." << endl;
}

/*----------------------------------------------------------------------------*/

// Returns 0 if `sequence` is zigzag-growing.
// Otherwise, returns the index of the first member of `sequence`
// that breaks its "zigzag-growing" property.
size_t checkZigzagGrowing(unsigned sequence[], size_t size) {
  for (size_t i = 0; i < size; ++i) {
    if (i % 2 == 1) {
      if (sequence[i] <= sequence[i - 1] ||
          i > 1 && sequence[i] <= sequence[i - 2]) {
        return i;
      }
    } else { // (i % 2 == 0)
      if (i > 0 && sequence[i] >= sequence[i - 1]) {
        return i;
      }
    }
  }
  return 0;
}

void task6() {
  size_t n = readNUpTo(MAX_ARRAY_SIZE);

  cout << "Now enter " << n << " natural numbers:\n";
  unsigned numbers[MAX_ARRAY_SIZE] = {0};
  for (size_t i = 0; i < n; ++i) {
    cin >> numbers[i];
  }

  size_t potentiallyBreakingIndex = checkZigzagGrowing(numbers, n);
  if (potentiallyBreakingIndex == 0) {
    cout << "The sequence is zigzag-growing.\n";
  } else {
    cout << "The sequence is not zigzag-growing; the first index that breaks ";
    cout << "the property is " << potentiallyBreakingIndex << ".\n";
  }
}

/*----------------------------------------------------------------------------*/

void constructPrimesTable(bool primesTable[], size_t size) {
  primesTable[0] = primesTable[1] = false;
  for (size_t i = 2; i < size; ++i) {
    // Assume every other number is prime until proven otherwise.
    primesTable[i] = true;
  }

  for (size_t i = 2; i < std::sqrt(size); ++i) {
    if (primesTable[i]) {
      // Mark all multiples of i as not prime.
      for (size_t j = i * i; j < size; j += i) {
        primesTable[j] = false;
      }
    }
  }
}

void task8() {
  constexpr size_t PRIMES_TABLE_SIZE = 10001;
  size_t n = readNUpTo(PRIMES_TABLE_SIZE - 1);
  size_t m = readNUpTo(PRIMES_TABLE_SIZE - 1);

  bool primesTable[PRIMES_TABLE_SIZE] = {false};
  constructPrimesTable(primesTable, PRIMES_TABLE_SIZE);

  cout << n << " is " << (primesTable[n] ? "" : "not ") << "prime.\n";
  cout << m << " is " << (primesTable[m] ? "" : "not ") << "prime.\n";
}

/*----------------------------------------------------------------------------*/

void task9() {
  constexpr size_t PRIMES_TABLE_SIZE = 100001;
  size_t n = readNUpTo(MAX_ARRAY_SIZE);

  cout << "Now enter " << n << " natural numbers < " << PRIMES_TABLE_SIZE;
  cout << ":\n";
  unsigned numbers[MAX_ARRAY_SIZE] = {0};
  for (size_t i = 0; i < n; ++i) {
    cin >> numbers[i];
  }

  bool primesTable[PRIMES_TABLE_SIZE] = {false};
  constructPrimesTable(primesTable, PRIMES_TABLE_SIZE);

  for (size_t i = 0; i < n; ++i) {
    unsigned element = numbers[i];
    cout << element << " is " << (primesTable[element] ? "" : "not ");
    cout << "prime.\n";
  }
}

/*----------------------------------------------------------------------------*/

int main() {
  cout << "Task 1\n";
  task1();

  cout << "Task 3\n";
  task3();

  cout << "Task 6\n";
  task6();

  cout << "Task 8\n";
  task8();

  cout << "Task 9\n";
  task9();

  return 0;
}
