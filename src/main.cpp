#include <iostream>
#include "crontab.h"
#include "tictactoe.h"
#include "guessthenumber.h"

// Prototypes of the game functions
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
            std::cout << "Goodbye!" << std::endl;
            break;
        case 4:
            playCrontab(); // Add the new case for the Crontab game
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 3);

    return 0;
}

// Function to display the main menu
void showMenu() {
    std::cout << "=== Main Menu ===" << std::endl;
    std::cout << "1. Play Tic Tac Toe" << std::endl;
    std::cout << "2. Play 'Guess the Number'" << std::endl;
    std::cout << "3. Quit" << std::endl;
    std::cout << "4. Play Crontab" << std::endl; // Add the new menu option
}