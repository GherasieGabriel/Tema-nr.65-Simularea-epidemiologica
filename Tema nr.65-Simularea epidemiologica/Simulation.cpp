#include "Simulation.h"
#include <stdexcept>

Simulation::Simulation() 
	: nr_people(100), infection_duration(5), infection_rate(0.05f), simulation_days(30), quarantine_ratio(0.4f) // Default constructor with default values
{
    for (int i = 0; i < nr_people; i++)
    {
        people.push_back(Person());
    }
}

Simulation::Simulation(int nr_people, int infection_duration, float infection_rate, int simulation_days, float quarantine_ratio)
    : nr_people(nr_people), infection_duration(infection_duration), infection_rate(infection_rate), simulation_days(simulation_days), quarantine_ratio(quarantine_ratio)
{
    for (int i = 0; i < nr_people; i++)
    {
        people.push_back(Person()); // Add 'nr_people' Person objects to the 'people' vector
    }
}

int Simulation::getPeople() const
{
    return nr_people;
}

int Simulation::getInfection_duration()
{
    return infection_duration;
}

float Simulation::getInfection_rate()
{
    return infection_rate;
}

void Simulation::setInfection_rate(float rate)
{
    infection_rate = rate;
}

int Simulation::getSimulation_days()
{
    return simulation_days;
}

float Simulation::getQuarantine_ratio() const
{
    return quarantine_ratio;
}

void Simulation::setQuarantine_ratio(float ratio)
{
    quarantine_ratio = ratio;
}

Person& Simulation::getPerson(int index)
{
    if (index < 0 || index >= people.size())
    {
        throw std::out_of_range("Index out of bounds.");
    }
    return people[index];
}

Simulation::~Simulation()
{
}
