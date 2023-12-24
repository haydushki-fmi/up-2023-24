#include <iostream>
#include <cstring>

void substring(char source[], std::size_t beginIndex, std::size_t endIndex, char target[]) {
    std::size_t i = 0;
    while (beginIndex < endIndex) {
        target[i++] = source[beginIndex++];
    }
    target[i] = 0;
}

void trim(char original[], char trimmed[]) {
    // Ако не е позволено използването на cstring, може да си напишем наша функция за дължина
    std::size_t length = strlen(original);

    std::size_t firstNoSpaceIndex = 0;
    std::size_t lastNoSpaceIndex = length - 1;

    while (original[firstNoSpaceIndex] == ' ') {
        firstNoSpaceIndex++;
    }

    while (original[lastNoSpaceIndex] == ' ') {
        lastNoSpaceIndex--;
    }

    substring(original, firstNoSpaceIndex, lastNoSpaceIndex, trimmed);
}

int main() {
    char arr[100] = "   hello world!  ";
    char trimmedArr[100];

    trim(arr, trimmedArr);

    std::cout << trimmedArr << std::endl;

    return 0;
}
