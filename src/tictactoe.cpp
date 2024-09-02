#include <iostream>
#include <cstdlib> // for std::rand()

const int SIZE = 3;
char board[SIZE][SIZE];
char currentPlayer;
bool isSinglePlayer; // Flag to determine if it's single player or two players

// Function to initialize the Tic Tac Toe board with empty spaces
void initializeBoard();
// Function to display the Tic Tac Toe board
void displayBoard();
// Function to check if the current player has won
bool checkWin();
// Function to check if the game is a draw
bool checkDraw();
// Function to switch the current player
void switchPlayer();
// Function for the human player to make a move
void playerMove();
// Function for the AI to make a move
void aiMove();

void playTicTacToe() {
    // Ask for the number of players
    int numPlayers;
    std::cout << "Enter number of players (1 or 2): ";
    std::cin >> numPlayers;

    if (numPlayers == 1) {
        isSinglePlayer = true; // Single player mode
    } else if (numPlayers == 2) {
        isSinglePlayer = false; // Two players mode
    } else {
        std::cout << "Invalid number of players. Defaulting to 2 players." << std::endl;
        isSinglePlayer = false; // Default to two players if invalid input
    }

    initializeBoard(); // Initialize the board
    currentPlayer = 'X'; // Set the current player to X
    bool gameWon = false;
    bool gameDraw = false;

    while (!gameWon && !gameDraw) {
        displayBoard(); // Display the board

        if (isSinglePlayer && currentPlayer == 'O') {
            // Single player mode: AI makes a move
            aiMove();
        } else {
            // Two players mode or human player makes a move
            playerMove();
        }

        gameWon = checkWin(); // Check if a player has won
        gameDraw = checkDraw(); // Check if the game is a draw
        if (!gameWon && !gameDraw) {
            switchPlayer(); // Switch player if the game is still ongoing
        }
    }

    displayBoard(); // Display the final board
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
            board[i][j] = ' '; // Fill each cell with a space
        }
    }
}

// Function to display the Tic Tac Toe board
void displayBoard() {
    std::cout << "  0 1 2" << std::endl;
    for (int i = 0; i < SIZE; ++i) {
        std::cout << i << " ";
        for (int j = 0; j < SIZE; ++j) {
            std::cout << board[i][j]; // Print the content of each cell
            if (j < SIZE - 1) std::cout << "|"; // Add column separators
        }
        std::cout << std::endl;
        if (i < SIZE - 1) std::cout << "  -----" << std::endl; // Add row separators
    }
}

// Function to check if the current player has won
bool checkWin() {
    // Check rows and columns
    for (int i = 0; i < SIZE; ++i) {
        if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) ||
            (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)) {
            return true; // Current player has won
        }
    }
    // Check diagonals
    if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
        (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)) {
        return true; // Current player has won
    }
    return false; // No win condition met
}

// Function to check if the game is a draw
bool checkDraw() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] == ' ') {
                return false; // Empty cell found, so it's not a draw yet
            }
        }
    }
    return true; // All cells are filled, and no winner, so it's a draw
}

// Function to switch the current player
void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X'; // Toggle between 'X' and 'O'
}

// Function for the human player to make a move
void playerMove() {
    int row, col;
    std::cout << "Player " << currentPlayer << ", enter your move (row and column): ";
    std::cin >> row >> col;

    if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ') {
        board[row][col] = currentPlayer; // Make the move
    } else {
        std::cout << "Invalid move. Please try again." << std::endl;
        playerMove(); // Retry until a valid move is made
    }
}

// Function for the AI to make a move
void aiMove() {
    // Simple AI: choose a random move from empty cells
    int row, col;
    do {
        row = std::rand() % SIZE;
        col = std::rand() % SIZE;
    } while (board[row][col] != ' ');

    board[row][col] = currentPlayer; // Make the move
    std::cout << "AI (Player " << currentPlayer << ") chooses (" << row << ", " << col << ")" << std::endl;
}
