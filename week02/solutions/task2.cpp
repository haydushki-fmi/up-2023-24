#include <iostream>

int main()
{
  double a, b, c;
  std::cin >> a >> b >> c;
  double perimeter = a + b + c;

  std::cout << perimeter << std::endl;
  // или:
  // std::cout << (a + b + c) << std::endl;

  return 0;
}
