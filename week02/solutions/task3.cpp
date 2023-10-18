#include <cmath>
#include <iostream>

int main()
{
  double a, b, c;
  std::cin >> a >> b >> c;

  double p = (a + b + c) / 2;

  std::cout << std::sqrt(p * (p - a) * (p - b) * (p - c));

  return 0;
}
