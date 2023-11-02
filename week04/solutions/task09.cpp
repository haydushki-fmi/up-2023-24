#include <cmath>
#include <iostream>

using namespace std;

int main()
{
    const double EPSILON = 0.0001;

    double a, b, c;
    cin >> a >> b >> c;

    if (a < 0 || b < 0 || c < 0 || a >= b + c || b >= a + c || c >= a + b) {
        cout << "Invalid data!\n";
    } else {
        // Пример за сравнения за равенство при определена точност:
        if (abs(a - b) < EPSILON && abs(a - c) < EPSILON && abs(b - c) < EPSILON) {
            cout << "Triangle is equilateral\n";
        } else if (abs(a - b) < EPSILON || abs(a - c) < EPSILON || abs(b - c) < EPSILON) {
            cout << "Triangle is isosceles\n";
        } else {
            cout << "Triangle is scalene\n";
        }
    }

    return 0;
}
