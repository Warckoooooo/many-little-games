#include "crontab.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

void playCrontab() {
    // implementation of Crontab game goes here
    std::string months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int minute = rand() % 60;
    int hour = rand() % 24;
    int day = rand() % 28 + 1; // assuming a 28-day month
    int month = rand() % 12;

    std::string cronExpression;
    cronExpression += std::to_string(minute) + " ";
    cronExpression += std::to_string(hour) + " ";
    cronExpression += std::to_string(day) + " ";
    cronExpression += std::to_string(month + 1) + " *";

    std::cout << "At " << hour << ":" << minute << " in " << months[month] << ". What is the Crontab expression?" << std::endl;
    std::cout << "Enter your answer (in the format 'minute hour day month *'): ";
    std::string userAnswer;
    std::getline(std::cin, userAnswer);

    if (userAnswer == cronExpression) {
        std::cout << " Congratulations! You got it right!" << std::endl;
    } else {
        std::cout << " Sorry, that's not correct. The correct Crontab expression was: " << cronExpression << std::endl;
    }
}