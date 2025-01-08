#include "Simulation.h"
#include <iostream>
#include <algorithm> 
template <typename T>
T clamp(T value, T low, T high) {
	return std::max(low, std::min(value, high));
}
void Simulation::runSimulation() { // Simulation loop
    for (auto& person : people) {
        if (person.GetState() == Healthy) {
			person.attemptInfection(infection_rate, infection_duration); // Check if the person gets infected
        }
        else if (person.GetState() == Infected) {
			person.applyQuarantine(quarantine_ratio); // Apply quarantine if infected
        }
		person.Recovery(); // Check if the person recovers
    } 
	adjustInfectionRate(); // Adjust the infection rate based on the number of infected people
}

void Simulation::adjustInfectionRate() { // Adjust the infection rate based on the number of infected people
	int infectedCount = 0;
	for (const auto& person : people) {
		if (person.GetState() == Infected) {
			infectedCount++;
		}
	}
	float adjustment = ((infectedCount - last_infected_count) / static_cast<float>(nr_people)) * 0.1f; // Reduce the scaling factor to 0.01f
	last_infected_count = infectedCount; // Update the last infected count
	infection_rate = clamp(infection_rate + adjustment, 0.01f, 0.90f); // Adjust the infection rate
}
void Simulation::initializeInfected() { // Set the initial infected people
	int initialInfected = nr_people * 0.01; // 1% infected initially
	last_infected_count = initialInfected;
	for (int i = 0; i < initialInfected; i++) {
		int idx = rand() % nr_people;
		people[idx].setState(Infected);
		people[idx].setDaysInfected(infection_duration);
	}
}
bool Simulation:: hasActiveInfections()
{
	bool infected_people_remaining = false;
	for (auto& person : people)
	{
		if (person.GetState() == Infected || person.GetState()==Quarantined)
		{
			infected_people_remaining = true;
			break;
		}
	}
	if (!infected_people_remaining) {
		std::cout << "No more infected people. Ending simulation.\n";
		return 0;
	}
}
void Simulation::getStateCounts(int& healthy, int& infected, int& immune, int& quarantined) { // Count the number of people in each state
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
void Simulation::displaySimulationStatus() { // Print the number of people in each state
    int healthy = 0, infected = 0, immune = 0, quarantined = 0;
	getStateCounts(healthy, infected, immune, quarantined);
    std::cout << "Healthy: " << healthy << ", Infected: " << infected
		<< ", Immune: " << immune << ", Quarantined: " << quarantined << std::endl << "Infection rate:" << infection_rate << std::endl; // Print the number of people in each state
}
