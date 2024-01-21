#include "week14.h"

#include <cstdlib>
#include <iostream>

using std::atoi;

using std::cout;
using std::endl;


/*----------------------------------------------------------------------------*/

enum PrimaryColor {
  RED,
  GREEN,
  BLUE,
};

void printColor(PrimaryColor color) {
  switch(color) {
    case RED:
      cout << "red";
      break;
    case GREEN:
      cout << "green";
      break;
    case BLUE:
      cout << "blue";
      break;
    default:
      cout << "Unknown PrimaryColor:\t" << color;
  }
}

void task1() {
  printColor(PrimaryColor::GREEN);
  cout << endl;
}

/*----------------------------------------------------------------------------*/

void task2(int argc, const char *const argv[]) {
  int result = 0;

  for (int i = 0; i < argc; ++i) {
    result += atoi(argv[i]);
  }

  cout << result << endl;
}

/*----------------------------------------------------------------------------*/

#ifndef _MSC_VER
#include <cstddef>
using std::size_t;
#endif

void task3() {
  size_t sizeception = sizeof(size_t);
  cout << sizeception << endl;
}

/*----------------------------------------------------------------------------*/

#define DEBUG

#ifdef DEBUG
#define DEBUG_OUTPUT(x) std::cout << __FILE__ << ':' << __LINE__ << ':' << (x) << std::endl;
#else
#define DEBUG_OUTPUT(x)
#endif

void task4() {
  DEBUG_OUTPUT("Debug output!");
}
