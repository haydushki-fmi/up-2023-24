#include <iostream>

int main()
{
  int up, dis1, la, ag;
  std::cin >> up >> dis1 >> la >> ag;
  
  // Внимаваме за загуба на точност при преминаване от един тип в друг:
  double avg = (up + dis1 + la + ag) / 4.0; 

  std::cout << avg << std::endl;

  return 0;
}
