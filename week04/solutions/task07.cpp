#include <iostream>
using std::cout, std::cin, std::endl;

int main() {
  cout << "Enter number of days for the holiday:\n";
  unsigned int n;
  cin >> n;

  const int START_DATE = 22;
  int month = 1;
  int dateBackToSchool = START_DATE + n;

  if (n >= 2 && n <= 22) {
    if (dateBackToSchool > 31) {
      dateBackToSchool = dateBackToSchool - 31;
      month++;
    }

    cout << "The students must be back at school on " << dateBackToSchool
         << ".0" << month << ".2024" << endl;
  } else {
    cout << "Invalid data! No holiday." << endl;
  }

  return 0;
}
