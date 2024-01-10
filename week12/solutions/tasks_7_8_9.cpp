#include <cstddef>
#include <iostream>


using std::cin;
using std::cout;
using std::endl;

using std::size_t;


// Don't forget to `delete[]` the result when you're done with it!
unsigned* inputUnsignedArray(/*out*/ size_t& size) {
  cout << "Enter a natural number N, the array's size:\t";
  cin >> size;

  cout << "Now enter " << size << " natural numbers:\n";
  unsigned* arr = new unsigned[size];
  for (size_t i = 0; i < size; ++i) {
    cin >> arr[i];
  }

  return arr;
}

void printArray(const unsigned* arr, size_t size) {
  for (size_t i = 0; i < size; ++i) {
    cout << arr[i] << ' ';
  }
  cout << endl;
}

/*----------------------------------------------------------------------------*/

void variationsInternal(
  const unsigned* arr, size_t size, unsigned* variation, size_t i, size_t k
) {
  if (i == k) {
    printArray(variation, k);
  }
  else for (size_t j = 0; j < size; ++j) {
    variation[i] = arr[j];
    variationsInternal(arr, size, variation, i + 1, k);
  }
}

void variationsWithRepetition(const unsigned* arr, size_t size, size_t k) {
  unsigned* variation = new unsigned[k];
  variationsInternal(arr, size, variation, 0, k);
  delete[] variation;
}

void task7() {
  size_t n = 0;
  unsigned* arr = inputUnsignedArray(n);

  cout << "Now enter k < N:\t";
  size_t k = 0;
  cin >> k;

  cout << "Here are all the variations (with repetition) of the " << k;
  cout << "-th class of these numbers:\n";
  variationsWithRepetition(arr, n, k);
  delete[] arr;
}

/*----------------------------------------------------------------------------*/

void permuteInternal(
  const unsigned* arr, bool* used, size_t size, unsigned* permuted, size_t i
){
  if (i == size) {
    printArray(permuted, size);
  }
  else for (size_t j = 0; j < size; ++j) {
    if (!used[j]) {
      permuted[i] = arr[j];
      used[j] = true;
      permuteInternal(arr, used, size, permuted, i + 1);
      used[j] = false;
    }
  }
}

void permute(const unsigned* arr, size_t size) {
  bool* used = new bool[size]{false};
  unsigned* permuted = new unsigned[size];

  permuteInternal(arr, used, size, permuted, 0);

  delete[] permuted;
  delete[] used;
}

void task8() {
  size_t n = 0;
  unsigned* arr = inputUnsignedArray(n);

  cout << "Here are all the permutations of these numbers:\n";
  permute(arr, n);
  delete[] arr;
}

/*----------------------------------------------------------------------------*/

static void swap(unsigned* arr, size_t i, size_t j) {
  unsigned buffer = arr[i];
  arr[i] = arr[j];
  arr[j] = buffer;
}

static void selectionSort(unsigned* arr, size_t size) {
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

void printBreakdown(
  const unsigned* numbers, const unsigned* counts, size_t size
) {
  bool alreadyPrinted = false;
  for (size_t j = 0; j < size; ++j) {
    if (counts[j] > 0) {
      if (alreadyPrinted) {
        cout << " + ";
      }
      alreadyPrinted = true;
      cout << counts[j] << 'x' << numbers[j];
    }
  }
  cout << endl;
}

void breakSumInternal(
  const unsigned* numbers, size_t i, size_t size,
  unsigned* counts, unsigned remainingSum
) {
  if (i == size) {
    return;
  }

  while (remainingSum >= numbers[i]) {
    breakSumInternal(numbers, i + 1, size, counts, remainingSum);
    ++counts[i];
    remainingSum -= numbers[i];
  }

  if (remainingSum == 0) {
    printBreakdown(numbers, counts, size);
  }
  counts[i] = 0;
}

// `numbers` must have been pre-sorted in increasing order!
void breakSum(const unsigned* numbers, size_t size, unsigned sum) {
  unsigned* counts = new unsigned[size]{0,};
  breakSumInternal(numbers, 0, size, counts, sum);
  delete[] counts;
}

void task9() {
  size_t n = 0;
  unsigned* arr = inputUnsignedArray(n);
  selectionSort(arr, n);

  cout << "Now enter S:\t";
  size_t s = 0;
  cin >> s;

  cout << "Here are all the unique ways in which " << s << " can be a sum ";
  cout << "of these numbers (with repetitions):\n";
  breakSum(arr, n, s);
  delete[] arr;
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
