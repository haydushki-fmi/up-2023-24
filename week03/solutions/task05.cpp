#include <cmath>
#include <iostream>

int main()
{
  double a, b, c;
  std::cin >> a >> b >> c;

  bool isValidTriangle = a > 0 && b > 0 && c > 0;
  isValidTriangle = isValidTriangle && a < b + c && b < a + c && c < a + b;

  std::cout << (isValidTriangle ? "YES" : "NO" ) << std::endl;

  return 0;
}
