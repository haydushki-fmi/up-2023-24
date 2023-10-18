#include <cmath>
#include <iostream>

int main()
{
  int n;
  std::cin >> n;

  std::cout << (char)(n + 96) << std::endl;
  // За да не помним ASCII таблицата и да няма такива магически числа:
  std::cout << (char)(n - 1 + 'a') << std::endl;

  char ch;
  std::cin >> ch;

  char toUpper = ch - 'a' + 'A';
  std::cout << toUpper << std::endl;

  return 0;
}
