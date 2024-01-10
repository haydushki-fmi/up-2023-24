#include <iostream>

unsigned fib(unsigned n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fib(n - 1) + fib(n - 2);
}

// Linear recursion

// With helper function
int fibLinearHelper(int first, int second, int next, int n, int i) {

    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    if (i == n)
        return second;

    return fibLinearHelper(second, next, second + next, n, i + 1);
}

int fibLinear1(int n) { return fibLinearHelper(0, 1, 1, n, 1); }

// Only one function
int fibLinear2(int n, int val = 1, int prev = 0) {
    if (n == 0)
        return prev;
    return fibLinear2(n - 1, val + prev, val);
}

int main(int argc, char **argv) {
    std::cout << fib(10) << std::endl;
    std::cout << fibLinear1(10) << std::endl;
    std::cout << fibLinear2(10) << std::endl;
    return 0;
}
