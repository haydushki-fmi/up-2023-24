#include <cmath>
#include <iostream>

int main()
{
  double radius;
  const double PI = 3.141592;
  std::cin >> radius;

  double volume = std::pow(radius, 3) * PI * 4/3;

  std::cout << volume << std::endl;
  return 0;
}
