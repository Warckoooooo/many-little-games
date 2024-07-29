#include <iostream>

const int SIZE = 3;
char board[SIZE][SIZE];
char currentPlayer;

// Function to initialize the Tic Tac Toe board
void initializeBoard();
// Function to display the Tic Tac Toe board
void displayBoard();
// Function to check if a player has won
bool checkWin();
// Function to check if the game is a draw
bool checkDraw();
// Function to switch the current player
void switchPlayer();

void playTicTacToe() {
    initializeBoard();
    currentPlayer = 'X';
    bool gameWon = false;
    bool gameDraw = false;
    
    while (!gameWon && !gameDraw) {
        displayBoard();
        int row, col;
        std::cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        std::cin >> row >> col;
        
        if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ') {
            board[row][col] = currentPlayer;
            gameWon = checkWin();
            gameDraw = checkDraw();
            if (!gameWon) {
                switchPlayer();
            }
        } else {
            std::cout << "Invalid move. Please try again." << std::endl;
        }
    }
    
    displayBoard();
    if (gameWon) {
        std::cout << "Player " << currentPlayer << " wins!" << std::endl;
    } else {
        std::cout << "It's a draw!" << std::endl;
    }
}

// Function to initialize the Tic Tac Toe board with empty spaces
void initializeBoard() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            board[i][j] = ' ';
        }
    }
}

// Function to display the Tic Tac Toe board
void displayBoard() {
    std::cout << "  0 1 2" << std::endl;
    for (int i = 0; i < SIZE; ++i) {
        std::cout << i << " ";
        for (int j = 0; j < SIZE; ++j) {
            std::cout << board[i][j];
            if (j < SIZE - 1) std::cout << "|";
        }
        std::cout << std::endl;
        if (i < SIZE - 1) std::cout << "  -----" << std::endl;
    }
}

// Function to check if the current player has won
bool checkWin() {
    // Check rows and columns
    for (int i = 0; i < SIZE; ++i) {
        if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) ||
            (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
        (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)) {
        return true;
    }
    return false;
}

// Function to check if the game is a draw
bool checkDraw() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

// Function to switch the current player
void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}
