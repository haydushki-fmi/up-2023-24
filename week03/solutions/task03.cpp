#include <cmath>
#include <iostream>

int main()
{
  int number;
  std::cin >> number;

  int dig1 = number % 10;
  int dig2 = (number / 10) % 10;
  int dig3 = (number / 100) % 10;
  int dig4 = (number / 1000) % 10;
  int dig5 = (number / 10000) % 10;

  // Ако първият израз се оцени до лъжа, то вторият израз
  // няма да бъде проверяван изобщо, тъй като конюнкцията
  // ще се оцени до неистина независимо от резултата.
  bool isPalindrome = (dig1 == dig5 ) && (dig2 == dig4);

  return 0;
}
