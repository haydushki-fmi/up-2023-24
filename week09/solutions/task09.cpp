#include <iostream>

void initialiseBoard(char board[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = 0;
}

bool checkWinner(char board[3][3]) {
    // Проверка за победител по редове
    for (int row = 0; row < 3; row++) {
        char move = board[row][0];
        if (move == 0) {
            continue;
        }

        bool allEqual = true;
        for (int col = 0; col < 3; col++) {
            if (board[row][col] != move) {
                allEqual = false;
                break;
            }
        }
        if (allEqual)
            return true;
    }

    // Проверка за победител по колони
    for (int col = 0; col < 3; col++) {
        char move = board[0][col];
        if (move == 0) {
            continue;
        }

        bool allEqual = true;
        for (int row = 0; row < 3; row++) {
            if (board[row][col] != move) {
                allEqual = false;
                break;
            }
        }

        if (allEqual)
            return true;
    }

    // Проверка за победител по главния диагонал
    bool mainDiagonalAllEqual = true;
    char mainDiagonalMove = board[0][0];
    for (int i = 0; i < 3; i++) {
        if (board[i][i] != mainDiagonalMove) {
            mainDiagonalAllEqual = false;
            break;
        }
    }
    if (mainDiagonalAllEqual && mainDiagonalMove != 0) {
        return true;
    }

    // Проверка за победител по вторичния диагонал
    bool secondaryDiagonalAllEqual = true;
    char secondaryDiagonalMove = board[0][2];
    for (int i = 0; i < 3; i++) {
        if (board[i][3 - i - 1] != secondaryDiagonalMove) {
            secondaryDiagonalAllEqual = false;
            break;
        }
    }
    if (secondaryDiagonalAllEqual && secondaryDiagonalMove != 0) {
        return true;
    }

    return false;
}

bool boardFull(char board[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == 0)
                return false;
    return true;
}

void applyMove(char board[3][3], int player, char playerMove) {
    int i, j;
    std::cout << "Player " << player << " move(row & col): ";
    std::cin >> i >> j;

    while (i < 0 || i > 2 || j < 0 || j > 2 || board[i][j]) {
        std::cout << "Invalid move! Try again!" << std::endl;
        std::cout << "Player " << player << " move: ";
        std::cin >> i >> j;
    }

    board[i][j] = playerMove;
}

int nextPlayer(int player) {
    return player % 2 + 1;
}

void printBoard(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            if (board[i][j])
                std::cout << board[i][j] << " ";
            else
                std::cout << "_"
                          << " ";
        std::cout << std::endl;
    }
}

int main() {
    char playerChars[2] = {'x', 'o'};

    char board[3][3];
    initialiseBoard(board);

    int player = 1;
    bool hasWinner = false;

    printBoard(board);

    // Всеки играч играе ход докато не намерим победител или дъската не се запълни
    while (!hasWinner && !boardFull(board)) {
        applyMove(board, player, playerChars[player - 1]);
        player = nextPlayer(player);
        printBoard(board);
        hasWinner = checkWinner(board);
    }

    if (hasWinner) {
        std::cout << "The winner is player " << nextPlayer(player) << "!" << std::endl;
    } else {
        std::cout << "It's a tie!" << std::endl;
    }

    return 0;
}
