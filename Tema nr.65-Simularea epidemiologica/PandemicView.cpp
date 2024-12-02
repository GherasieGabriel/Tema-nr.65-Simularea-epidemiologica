// TODO: MVC(pe net) - Model View Controller desparte clasa Simulation in 3 clase: Model, View, Controller
#include "Pandemic.h"
int previously_infected;
void  Simulation::print()
{
    int nr_Healthy = 0, nr_Infected = 0, nr_Imune = 0, nr_Quarantine = 0;
    for (const auto& person : people)
    {
        if (person.GetState() == Healthy)
            nr_Healthy++;
        else if (person.GetState() == Infected)
            nr_Infected++;
        else if (person.GetState() == Imune)
            nr_Imune++;
        else if (person.GetState() == Quarantined)
            nr_Quarantine++;
    }
    if (previously_infected < nr_Infected)
    {

        infection_rate = infection_rate + ((nr_Infected - previously_infected) * 0.5) / nr_people;
        previously_infected = nr_Infected;
    }
    else if (nr_Infected < previously_infected)
    {
        infection_rate = infection_rate - ((previously_infected - nr_Infected) * 0.5) / nr_people;
        previously_infected = nr_Infected;
    }
    previously_infected = nr_Infected;
    if (infection_rate < 0.01)
    {
        infection_rate = 0.01;
    }
    else if (infection_rate > 0.90)
    {
        infection_rate = 0.90;
    }
    std::cout << "Infection rate: " << infection_rate << "\n";
    std::cout << "Healthy: " << nr_Healthy << "\n";
    std::cout << "Infected: " << nr_Infected << "\n";
    std::cout << "Quarantine: " << nr_Quarantine << "\n";
    std::cout << "Imunee: " << nr_Imune << "\n";
}