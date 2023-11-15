
#include <iostream>

void printNumberDigitOcurrences(int n) {
    unsigned count1, count2, count3, count4, count5, count6, count7, count8, count9;
    count1 = count2 = count3 = count4 = count5 = count6 = count7 = count8 = count9 = 0;
    while(n > 0) {
        int dig = n % 10;
        switch (dig) {
            case 1:
                count1++;
                break;
            case 2:
                count2++;
                break;
            case 3:
                count3++;
                break;
            case 4:
                count4++;
                break;
            case 5:
                count5++;
                break;
            case 6:
                count6++;
                break;
            case 7:
                count7++;
                break;
            case 8:
                count8++;
                break;
            case 9:
                count9++;
                break;
        }
        n /= 10;
    }

    std::cout << "Number of 1s: " << count1 << std::endl;
    std::cout << "Number of 2s: " << count2 << std::endl;
    std::cout << "Number of 3s: " << count3 << std::endl;
    std::cout << "Number of 4s: " << count4 << std::endl;
    std::cout << "Number of 5s: " << count5 << std::endl;
    std::cout << "Number of 6s: " << count6 << std::endl;
    std::cout << "Number of 7s: " << count7 << std::endl;
    std::cout << "Number of 8s: " << count8 << std::endl;
    std::cout << "Number of 9s: " << count9 << std::endl;
}

int main() {
    printNumberDigitOcurrences(123454);
    
    return 0;
}

