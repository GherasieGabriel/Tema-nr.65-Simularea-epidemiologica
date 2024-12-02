#include "Simulation.h"
using namespace std;
int Simulation::getPeople() const
{
	return this->nr_people;
}

int Simulation::getInfection_rate()
{
	return this->infection_rate;
}

void Simulation::setInfection_rate(float infection_rate)
{
	this->infection_rate = infection_rate;
}

int Simulation::getSimulation_days()
{
	return this->simulation_days;
}

int Simulation::getInfection_duration()
{
	return this->infection_duration;
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
