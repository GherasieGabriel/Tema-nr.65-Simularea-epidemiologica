// Simulare.h
#ifndef SIMULATION_H
#define SIMULATION_H

#include "Person.h"
#include <vector>

class Simulation
{
public:
    int nr_people;
    int infection_duration;
    float infection_rate;
    int simulation_days;

    // Vector pentru obiecte person
    std::vector<Person> people;
    // Constructor
	
    Simulation(int nr_people, int infection_duration, float infection_rate, int simulation_days);

    // Simulare Pandemici
    void Pandemic_Simulation();

    // printa rezultatelor
    void print();

    void Draw();

    // Destructor
    ~Simulation();
};void Begin_Simulation();
#endif // SIMULARE_H    