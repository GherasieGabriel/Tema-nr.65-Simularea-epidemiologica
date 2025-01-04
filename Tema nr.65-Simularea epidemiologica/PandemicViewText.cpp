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
    int initialInfected = simulation.getPeople() * 0.01; // 1% infected initially

    for (int i = 0; i < initialInfected; i++) {
        int idx = rand() % simulation.getPeople();
        simulation.getPerson(idx).setState(Infected);
        simulation.getPerson(idx).setDaysInfected(simulation.getInfection_duration());
    }

    for (int day = 0; day < simulation.getSimulation_days(); day++) {
        std::cout << "Day " << day + 1 << ":\n";
        simulation.Pandemic_Simulation();
        simulation.print();
        std::cout << "\n";

        bool hasInfected = false;
        for (int i = 0; i < simulation.getPeople(); i++) {
            if (simulation.getPerson(i).GetState() == Infected || simulation.getPerson(i).GetState() == Quarantined) {
                hasInfected = true;
                break;
            }
        }

        if (!hasInfected) {
            std::cout << "No more infected people. Ending simulation.\n";
            break;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}