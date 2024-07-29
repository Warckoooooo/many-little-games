#include <iostream>
#include <cstdlib>
#include <ctime>

// Function to play the "Guess the Number" game
void playGuessTheNumber() {
    std::cout << "Starting 'Guess the Number' game..." << std::endl;
    srand(time(0));
    int numberToGuess = rand() % 1001;
    int guess;
    int attempts = 0;
    
    do {
        std::cout << "Guess the number (between 0 and 1000): ";
        std::cin >> guess;
        attempts++;
        
        if (guess > numberToGuess) {
            std::cout << "Too high!" << std::endl;
        } else if (guess < numberToGuess) {
            std::cout << "Too low!" << std::endl;
        } else {
            std::cout << "Congratulations! You guessed the number in " << attempts << " attempts." << std::endl;
        }
    } while (guess != numberToGuess);
}
