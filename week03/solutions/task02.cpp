#include <cmath>
#include <iostream>

int main()
{
  double tempF;
  std::cin >> tempF;

  double tempC = (tempF - 32) * 5 / 9;
  std::cout << tempC << std::endl;

  return 0;
}
