#include <cmath>
#include <iostream>

int main()
{
  double x1, y1, x2, y2;
  std::cin >> x1 >> y1 >> x2 >> y2;

  double dx = x1 - x2;
  double dy = y1 - y2;

  double distance = std::sqrt(dx * dx + dy * dy);
  std::cout << "The distance is: " << distance << std::endl;

  return 0;
}
