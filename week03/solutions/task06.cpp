#include <cmath>
#include <iostream>

int main()
{
  double x, y;
  std::cin >> x >> y;

  bool circleA = (x * x + y * y) <= 1;
  bool circleB = (x * x + y * y) == 2;

  std::cout << circleA << std::endl;
  std::cout << circleB << std::endl;

  return 0;
}
