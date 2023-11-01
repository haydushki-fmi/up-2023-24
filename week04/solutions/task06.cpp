#include <iostream>
using std::cout, std::cin;

int main() {
  const int MIN_DEPTH = 4;
  const int MAX_AGE = 6;

  int n;
  double depth;
  int age;

  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cout << "Enter depth and age for tyre " << i << ":\n";
    cin >> depth >> age;
    cout << ((depth < MIN_DEPTH || age > MAX_AGE) ? "Change this tyre!\n"
                                                  : "This tyre is OK!\n");
  }

  return 0;
}
