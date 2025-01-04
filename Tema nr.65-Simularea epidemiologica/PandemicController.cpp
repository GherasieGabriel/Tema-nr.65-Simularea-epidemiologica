// --- PandemicController.cpp ---
#include "PandemicController.h"
#include "InputValidator.h"
#include <iostream>

PandemicController::PandemicController() {}

void PandemicController::runSimulation() {
    int n, d, z; // n=number of people, d=infection duration, z=simulation days,
    float r, q;  // r=infection rate, q=quarantine ratio

    view.renderMenu();
    std::cout << "Enter y for default values or n for custom values: ";
    if (std::cin.get() == 'y') {
        model = Simulation();
    }
    else {
        validateIntInput(n, "Enter the number of people: ");
        validateIntInput(d, "Enter infection duration (days): ");
        validateFloatInput(r, "Enter infection rate [0-1]: ");
        validateFloatInput(q, "Enter quarantine ratio [0-1]: ");
        validateIntInput(z, "Enter the number of simulation days: ");

        model = Simulation(n, d, r, z, q);
    }

    char displayMode;
    std::cout << "Enter 'g' for graphical display or 't' for textual display: ";
    std::cin >> displayMode;

    if (displayMode == 't') {
        view.renderTextSimulation(model); // Display textual simulation
    }
    else if (displayMode == 'g') {
        view.renderGraphicalSimulation(model); // Display graphical simulation
    }
    else {
        std::cerr << "Invalid display mode!" << std::endl; // Invalid input
    }
}
