#include <iostream>
#include "tictactoe.h"
#include "guessthenumber.h"
#include "guessthecrontab.h"
#include "mentalmath.h" // Include the header file for the new game

// Function prototypes
void showMenu();

int main() {
    int choice;

    do {
        showMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            playTicTacToe();
            break;
        case 2:
            playGuessTheNumber();
            break;
        case 3:
            playGuessTheCrontab();
            break;
        case 4:
            playMentalMath();
            break;
        case 5:
            std::cout << "Goodbye!" << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 5);

    return 0;
}

void showMenu() {
    std::cout << "=== Main Menu ===" << std::endl;
    std::cout << "1. Play Tic Tac Toe" << std::endl;
    std::cout << "2. Play 'Guess the Number'" << std::endl;
    std::cout << "3. Play 'Guess the Crontab'" << std::endl;
    std::cout << "4. Play 'Mental Math'" << std::endl;
    std::cout << "5. Quit" << std::endl;
}
