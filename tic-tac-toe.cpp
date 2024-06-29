#include <iostream>

const int SIZE = 3;
char board[SIZE][SIZE];

// Initialize the board with empty spaces
void initializeBoard() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            board[i][j] = ' ';
        }
    }
}

// Display the board
void displayBoard() {
    std::cout << "-------------\n";
    for (int i = 0; i < SIZE; ++i) {
        std::cout << "| ";
        for (int j = 0; j < SIZE; ++j) {
            std::cout << board[i][j] << " | ";
        }
        std::cout << "\n-------------\n";
    }
}

// Check if the board is full
bool isBoardFull() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

// Check for a win
bool checkWin(char player) {
    // Check rows
    for (int i = 0; i < SIZE; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }
    // Check columns
    for (int j = 0; j < SIZE; ++j) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
            return true;
        }
    }
    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }
    return false;
}

// Get player move
void getPlayerMove(char player) {
    int row, col;
    while (true) {
        std::cout << "Player " << player << ", enter your move (row and column): ";
        std::cin >> row >> col;
        if (row >= 1 && row <= SIZE && col >= 1 && col <= SIZE && board[row-1][col-1] == ' ') {
            board[row-1][col-1] = player;
            break;
        } else {
            std::cout << "Invalid move. Try again.\n";
        }
    }
}

// Main game loop
void playGame() {
    char currentPlayer = 'X';
    initializeBoard();
    displayBoard();
    
    while (true) {
        getPlayerMove(currentPlayer);
        displayBoard();
        
        if (checkWin(currentPlayer)) {
            std::cout << "Player " << currentPlayer << " wins!\n";
            break;
        } else if (isBoardFull()) {
            std::cout << "It's a draw!\n";
            break;
        }
        
        // Switch player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
}

int main() {
    char playAgain;
    do {
        playGame();
        std::cout << "Do you want to play again? (y/n): ";
        std::cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');
    
    return 0;
}

