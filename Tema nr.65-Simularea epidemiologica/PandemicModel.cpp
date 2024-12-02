#include "Pandemic.h"
Simulation::Simulation(int nr_people, int infection_duration, float infection_rate, int simulation_days)
    : nr_people(nr_people), infection_duration(infection_duration), infection_rate(infection_rate), simulation_days(simulation_days)
{
    for (int i = 0; i < nr_people; i++)
    {
        people.push_back(Person());
    }
}

// Simularea Pandemici
void Simulation::Pandemic_Simulation() {
    for (int i = 1; i < getPeople(); i++)
    {
        if (people[i].GetState() == Healthy) {
            people[i].probabilitate_infectare(infection_rate, infection_duration);
        }
        else if (people[i].GetState() == Infected) {
            people[i].Quarantine();
        }
        people[i].Recovery();
    }
}

