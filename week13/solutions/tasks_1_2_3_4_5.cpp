#include <cmath>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

typedef unsigned (*OneParamFunction) (unsigned);
typedef unsigned (*TwoParamFunction) (unsigned, unsigned);

static unsigned factorial(unsigned n) {
  unsigned result = 1;
  for (unsigned i = 2; i <= n; ++i) {
    result *= i;
  }
  return result;
}

/*----------------------------------------------------------------------------*/

unsigned g(OneParamFunction f, unsigned n) {
  unsigned result = 0;
  for (unsigned i = 1; i <= n; ++i) {
    result += f(i);
  }
  return result;
}

unsigned square(unsigned n) {
  return n * n;
}

void task1() {
  cout << "S = 1 + 2^2 + 3^2 + ... + 10^2 = " << g(square, 10) << endl;
  cout << "S = 1 + 2! + ... + 6! = " << g(factorial, 6) << endl;
}

/*----------------------------------------------------------------------------*/

double g2(TwoParamFunction f1, OneParamFunction f2, unsigned x, unsigned n) {
  double result = 0;
  double multiplier = -1;

  for (unsigned i = 1; i <= n; ++i) {
    multiplier *= -1;
    unsigned param = 2 * i - 1;
    result += f1(x, param) * multiplier / f2(param);
  }

  return result;
}

unsigned power(unsigned x, unsigned n) {
  unsigned result = 1;
  for (unsigned i = 1; i <= n; ++i) {
    result *= x;
  }
  return result;
}

void task2() {
  cout << "Enter x, then n:\t";
  unsigned x = 0, n = 0;
  cin >> x >> n;
  cout << "S(x, n) = " << g2(power, factorial, x, n) << endl;
}

/*----------------------------------------------------------------------------*/

void g3(OneParamFunction f, unsigned n, unsigned x) {
  for (unsigned i = 1; i <= n; ++i) {
    x = f(x);
  }
}

unsigned printLastDigitAndReturnTheRest(unsigned n) {
  cout << n % 10;
  return n / 10;
}

void task3() {
  cout << "Enter a natural number:\t";
  unsigned n = 0;
  cin >> n;
  g3(printLastDigitAndReturnTheRest, 5, n);
}

/*----------------------------------------------------------------------------*/

typedef double (*MathFunction) (double);

MathFunction chooseFunction(char choice) {
  switch(choice) {
    case 's':
      return sin;
    case 'c':
      return cos;
    case 'e':
      return exp;
    case 'l':
      return log;
    default:
      cout << "Invalid choice!";
      return nullptr;
  }
}

void task4() {
  cout << "Enter your choice of a function - 's' for sine, 'c' for cosine, ";
  cout << "'e' for exponential, 'l' for logarithm:\t";
  char choice = 0;
  cin >> choice;
  
  MathFunction f = chooseFunction(choice);
  if (f != nullptr) {
    cout << "Enter a real number:\t";
    double x = 0.0;
    cin >> x;

    cout << "f(" << x << ") = " << f(x) << endl;
  }
}

/*----------------------------------------------------------------------------*/

unsigned variations(unsigned n, unsigned k) {
  if (k == 0 || k > n) {
    return 0;
  }
  return factorial(n) / factorial(n - k);
}

unsigned combinations(unsigned n, unsigned k) {
  return variations(n, k) / factorial(k);
}

TwoParamFunction chooseCombinatorialFunction(char choice) {
  switch(choice) {
    case 'v':
      return variations;
    case 'c':
      return combinations;
    default:
      cout << "Invalid choice!";
      return nullptr;
    }
}

void task5() {
  cout << "Enter your choice of a function - 'v' for Vk(n), 'c' for Ck(n):\t";
  char choice = 0;
  cin >> choice;
  TwoParamFunction f = chooseCombinatorialFunction(choice);

  if (f != nullptr) {
    cout << "Enter n and k:\t";
    unsigned n = 0, k = 0;
    cin >> n >> k;

    cout << "f(" << n << ", " << k << ") = " << f(n, k) << endl;
  }
}

/*----------------------------------------------------------------------------*/

int main() {
  cout << "Task 1\n";
  task1();

  cout << "Task 2\n";
  task2();

  cout << "Task 3\n";
  task3();

  cout << "Task 4\n";
  task4();

  cout << "Task 5\n";
  task5();

  return 0;
}
