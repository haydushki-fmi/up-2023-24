#include <iostream>

std::size_t strlen_safe(const char str[], std::size_t sizeInBytes) {
    std::size_t i = 0;
    while (str[i] != '\0' && i < sizeInBytes) {
        i++;
    }

    if (i == sizeInBytes) {
        std::cout << "No NULL terminated string!" << std::endl;
    }

    return i;
}

void strcpy_safe(const char src[], std::size_t srcSize, char dest[], std::size_t destSize) {
    if (strlen_safe(src, srcSize) > destSize - 1) {
        std::cout << "Destination isn't big enough\n";
        return;
    }
    std::size_t i = 0;
    for (; src[i] != '\0' && i < srcSize; ++i) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
}

int main() {
    char str[3] = "ab";
    str[2] = '!';
    std::cout << strlen_safe(str, sizeof(str)) << "\n";

    char strA[6] = "Hello";
    char strB[8];

    strcpy_safe(strA, sizeof(strA), strB, sizeof(strB));
    std::cout << strB << std::endl;

    return 0;
}
