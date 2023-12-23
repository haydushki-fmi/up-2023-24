#include <iostream>
#include <cstring>
#include <cstddef>

using std::cin;
using std::cout;
using std::endl;
using std::size_t;


constexpr char upperToLower = 'a' - 'A';

bool isLowerCase(char c) {
	return c >= 'a' && c <= 'z';
}

bool isUpperCase(char c) {
	return c >= 'A' && c <= 'Z';
}

void reverseCase(char* str) {
	size_t strLen = strlen(str);

	for (size_t i = 0; i < strLen; ++i) {
		if (isUpperCase(str[i])) {
			str[i] += upperToLower;
		}
		else if (isLowerCase(str[i])) {
			str[i] -= upperToLower;
		}
	}
}


int main() {
	char str[1024];
	cin >> str;

	reverseCase(str);
	cout << str << endl;

	return 0;
}
