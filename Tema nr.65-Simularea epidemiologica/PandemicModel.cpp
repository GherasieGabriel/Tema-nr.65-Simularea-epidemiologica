#include "Simulation.h"
#include <iostream>
#include <algorithm> 
template <typename T>
T clamp(T value, T low, T high) {
	return std::max(low, std::min(value, high));
}
void Simulation::Pandemic_Simulation() { // Simulation loop
    for (auto& person : people) {
        if (person.GetState() == Healthy) {
			person.probabilitate_infectare(infection_rate, infection_duration); // Check if the person gets infected
        }
        else if (person.GetState() == Infected) {
			person.Quarantine(quarantine_ratio); // Apply quarantine if infected
        }
		person.Recovery(); // Check if the person recovers
    } 
	updateInfectionRate(); // Adjust the infection rate based on the number of infected people
}

void Simulation::updateInfectionRate() { // Adjust the infection rate based on the number of infected people
    int infectedCount = 0;
    for (const auto& person : people) {
        if (person.GetState() == Infected) {
            infectedCount++;
        }
    }
	float adjustment = (infectedCount / static_cast<float>(nr_people)) * 0.10f; // Scale the adjustment based on the number of infected people
	infection_rate = clamp(infection_rate + adjustment - 0.01f, 0.01f, 0.90f); // Decay after each day
}
void Simulation::count(int& healthy, int& infected, int& immune, int& quarantined) { // Count the number of people in each state
	healthy = 0;
	infected = 0;
	immune = 0;
	quarantined = 0;
	for (const auto& person : people) {
		switch (person.GetState()) {
		case Healthy:
			healthy++;
			break;
		case Infected:
			infected++;
			break;
		case Imune:
			immune++;
			break;
		case Quarantined:
			quarantined++;
			break;
		}
	}
}
void Simulation::print() { // Print the number of people in each state
    int healthy = 0, infected = 0, immune = 0, quarantined = 0;
	count(healthy, infected, immune, quarantined);
    std::cout << "Healthy: " << healthy << ", Infected: " << infected
		<< ", Immune: " << immune << ", Quarantined: " << quarantined << std::endl << "Infection rate:" << infection_rate << std::endl; // Print the number of people in each state
}
