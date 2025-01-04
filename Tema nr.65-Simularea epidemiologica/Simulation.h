#ifndef SIMULATION_H
#define SIMULATION_H
#include "Person.h"
#include <vector>
#include <iostream>

class Simulation {
private:
	int nr_people; // Number of people
	int infection_duration; // Duration of infection
	float infection_rate; // Infection rate
	float quarantine_ratio; // Quarantine ratio
	int simulation_days; // Number of days to simulate
	std::vector<Person> people; // Vector of Person objects

public:
	Simulation(); // Default constructor
	Simulation(int nr_people, int infection_duration, float infection_rate, int simulation_days, float quarantine_ratio); // Constructor with parameters
	void Pandemic_Simulation(); // Simulation loop
	void count(int& healthy, int& infected, int& immune, int& quarantined); // Count the number of people in each state
	void print(); // Print the number of people in each state
	void updateInfectionRate(); // Adjust the infection rate based on the number of infected people
	int getPeople() const; // Getter for the number of people
	int getInfection_duration(); // Getter for the infection duration
	float getInfection_rate(); // Getter for the infection rate
	void setInfection_rate(float infection_rate); // Setter for the infection rate
	float getQuarantine_ratio() const;	// Getter for the quarantine ratio
	void setQuarantine_ratio(float quarantine_ratio); // Setter for the quarantine ratio
	int getSimulation_days(); // Getter for the number of simulation days
	Person& getPerson(int index); // Getter for a Person object at a specific index

	~Simulation();
};
#endif // SIMULATION_H
