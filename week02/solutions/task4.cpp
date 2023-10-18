#include <iostream>

int main()
{
  int a, b;
  std::cin >> a >> b;

  // С помощна променлива:
  int c;
  c = a;
  a = b;
  b = c;
  
  std::cout << "a = " << a << " b = " << b << std::endl;

  // С аритметични операции:
  a = a + b;
  b = a - b;
  a = a - b;

  std::cout << "a = " << a << " b = " << b << std::endl;

  // С битови операции:
  // Пример:
  // a = 101 = 5
  // b = 111 = 7

  // a = 010
  // b = 101
  // a = 111
  a = a ^ b;
  b = a ^ b;
  a = a ^ b;

  std::cout << "a = " << a << " b = " << b << std::endl;

  return 0;
}
