// Simulare.h
#ifndef SIMULATION_H
#define SIMULATION_H

#include "Person.h"
#include <vector>

class Simulation
{
private:
    int nr_people;
    int infection_duration;
    float infection_rate;
    int simulation_days;
    // Vector pentru obiecte person
    std::vector<Person> people;
public:
    // Constructor
	Simulation();
    Simulation(int nr_people, int infection_duration, float infection_rate, int simulation_days);

    // Simulare Pandemici
    void Pandemic_Simulation();

    // printa rezultatelor
    void print();

    void Draw();

    int getPeople() const; 

    int getInfection_duration();

	int getInfection_rate();

    void setInfection_rate(float infection_rate);

    int getSimulation_days();

	int getPerson();

	void Initializer(int nr_people, int infection_duration, float infection_rate, int simulation_days);

    Person& getPerson(int index);

    // Destructor
    ~Simulation();
};
#endif // SIMULARE_H    