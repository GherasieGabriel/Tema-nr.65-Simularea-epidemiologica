#include "PandemicView.h"
#include <iostream>
#include <thread>
#include <chrono>
void PandemicView::renderMenu() {
    std::cout << "======================\n";
    std::cout << "    Pandemic Menu\n";
    std::cout << "======================\n";
}

void PandemicView::renderTextSimulation(Simulation& simulation) {
    simulation.initializeInfected();;
    for (int day = 0; day < simulation.getSimulation_days(); day++) {
        std::cout << "Day " << day + 1 << ":\n";
		simulation.runSimulation();
        simulation.displaySimulationStatus();
        std::cout << "\n";
        if (!simulation.hasActiveInfections()) {
            std::cout << "No more infected people. Ending simulation.\n";
            break;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}