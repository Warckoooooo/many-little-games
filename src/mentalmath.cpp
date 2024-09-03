#include "mentalmath.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

// Function to generate a random integer between min and max (inclusive)
int getRandomNumber(int min, int max) {
    return min + std::rand() % (max - min + 1);
}

// Function to start the mental math game
void playMentalMath() {
    std::srand(std::time(0)); // Seed the random number generator
    int numQuestions = 5;
    int correctAnswers = 0;

    std::cout << "Welcome to the Mental Math Game!" << std::endl;

    for (int i = 0; i < numQuestions; ++i) {
        int a = getRandomNumber(1, 10);
        int b = getRandomNumber(1, 10);
        char op = getRandomNumber(0, 1) == 0 ? '+' : '-';
        int answer;
        int correctAnswer;

        std::cout << "Question " << (i + 1) << ": What is " << a << " " << op << " " << b << "? ";

        if (op == '+') {
            correctAnswer = a + b;
        } else {
            correctAnswer = a - b;
        }

        std::cin >> answer;

        if (answer == correctAnswer) {
            std::cout << "Correct!" << std::endl;
            ++correctAnswers;
        } else {
            std::cout << "Incorrect. The correct answer was " << correctAnswer << "." << std::endl;
        }
    }

    std::cout << "Game Over! You got " << correctAnswers << " out of " << numQuestions << " correct." << std::endl;
}
