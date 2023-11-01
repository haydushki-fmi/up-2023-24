#include <iostream>

using namespace std;

int main()
{
    char op;
    cout << "Enter operation: ";
    cin >> op;

    int a, b = 0;
    cout << "Enter arguments: ";
    cin >> a >> b;

    switch (op) {
    case '+':
        cout << (a + b) << endl;
        break;
    case '-':
        cout << (a - b) << endl;
        break;
    case '*':
        cout << (a * b) << endl;
        break;
    case '/':
        if (b == 0) {
            cout << "Division by zero!" << endl;
            break;
        }
        cout << (a * 1.0 / b) << endl;
        break;
    case '%':
        if (b == 0) {
            cout << "Division by zero!" << endl;
            break;
        }
        cout << (a % b) << endl;
        break;
    default:
        cout << "Invalid operation!\n";
        break;
    }
    return 0;
}
