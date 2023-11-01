#include <iostream>
using std::cout, std::cin, std::endl;

int main() {
  cout << "Enter month and year:\t";
  int month, year;
  cin >> month >> year;

  bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
  switch (month) {
  case 1:
  case 3:
  case 5:
  case 7:
  case 8:
  case 10:
  case 12:
    cout << 31 << endl;
    break;
  case 4:
  case 6:
  case 9:
  case 11:
    cout << 30 << endl;
    break;
  case 2:
    cout << (isLeap ? 29 : 28) << endl;
    break;
  default:
    cout << "Invalid data!\n";
  }

  return 0;
}
