#include "InputValidator.h"

bool validateIntInput(int& value, const std::string& prompt) {
    while (true) {
        std::cout << prompt;
        std::cin >> value;
        if (std::cin.fail() || value <= 0) {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
            std::cerr << "Invalid input. Please enter a positive integer." << std::endl;
        }
        else {
            return true;
        }
    }
}

bool validateFloatInput(float& value, const std::string& prompt, float min, float max) {
    while (true) {
        std::cout << prompt;
        std::cin >> value;
        if (std::cin.fail() || value < min || value > max) {
			std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
            std::cerr << "Invalid input. Please enter a float between " << min << " and " << max << "." << std::endl;
        }
        else {
            return true;
        }
    }
}
