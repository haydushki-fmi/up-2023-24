#include <iostream>

int square(int a) {
    return a * a;
}

int main() {
    const std::size_t MAX_SIZE = 100;

    int routersCount;
    int routerX[MAX_SIZE], routerY[MAX_SIZE], routerR[MAX_SIZE];
    int pointsCount;
    int pointX[MAX_SIZE], pointY[MAX_SIZE];

    std::cin >> routersCount;

    for (int i = 0; i < routersCount; i++) {
        std::cin >> routerX[i] >> routerY[i] >> routerR[i];
    }

    std::cin >> pointsCount;
    for (int i = 0; i < pointsCount; i++) {
        std::cin >> pointX[i] >> pointY[i];
    }

    // Искаме да проверим дали за всяка точка, в която ще е Мишо, има покритие от някой рутер.
    for (int i = 0; i < pointsCount; i++) {
        bool found = false;
        for (int j = 0; j < routersCount && !found; j++) {
            if (square(pointX[i] - routerX[i]) + square(pointY[i] - routerY[i]) <= square(routerR[i])) {
                found = true;
            }
        }

        // Ако за някоя точка не сме намерили рутер, спираме да проверяваме останалите.
        if (!found) {
            std::cout << "Sad Misho\n";
            return 0;
        }
    }

    std::cout << "Happy Misho\n";

    return 0;
}
