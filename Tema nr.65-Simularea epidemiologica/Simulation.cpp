#include "Simulation.h"
#include "Person.h"
#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <ctime>
using namespace std;
int Total_Infected;
void Begin_Simulation()
{
    srand(time(0));
    int n, d, z; // n=nr person, d=durata infectare, z=zile simulare
    float r; // rata infectare
    cout << "Introduceti numarul de persoane: ";
    cin >> n;
    cout << "Introduceti durata de infectare [zile]: ";
    cin >> d;
    cout << "Introduceti rata de infectare [valori de la 0 la 1 (ex. 0.05 = 5%)]: ";
    cin >> r;
    cout << "Introduceti numarul de zile de simulare: ";
    cin >> z;
    //Menu(); // Putem sa comentam ca sa rulam doar simularea
    Simulation sim(n, d, r, z); // crearea obiectului sim

    // Rularea simularii pentru numarul specificat de zile
    int initial_Infected = n * 0.01; // 1% din populatie Infecteda initial
    for (int i = 0; i < initial_Infected; i++) { // infectare initiala
        int first_Infected = rand() % n;
        sim.people[first_Infected].setState(Infected);
        sim.people[first_Infected].days_Infected = d;
    }
    for (int zi = 0; zi < z; zi++) { // simulare
        cout << "Ziua " << zi + 1 << ":\n";
        sim.Pandemic_Simulation();
        sim.print();
        cout << "\n";
        bool infected_people_remaining = false; // verificare daca mai exista person Infectede
        for (const auto& person: sim.people) {
            if (persoana.GetState() == Infected || persoana.GetState() == Quarantined) {
                infected_people_remaining = true;
                break;
            }
        }

        if (infected_people_remaining == false) { // oprirea simularii daca nu mai exista person Infectede
            cout << "Nu mai exista person Infectede. Oprirea simularii.\n";
            break;
        }
        this_thread::sleep_for(chrono::milliseconds(500)); // pauza de 500ms
    }
}
// Implementarea constructorului
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
    for (int i=1;i<nr_people;i++)
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

// printa rezultatelor
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
    if (Total_Infected < nr_Infected)
    {

        infection_rate = infection_rate + ((nr_Infected - Total_Infected)*0.5)/nr_people;
        Total_Infected = nr_Infected;
    }
    else if (nr_Infected < Total_Infected)
    {
        infection_rate = infection_rate - ((Total_Infected - nr_Infected)*0.5)/nr_people;
        Total_Infected = nr_Infected;
    }
	Total_Infected = nr_Infected;
    if (infection_rate < 0.01)
    {
		infection_rate = 0.01;
    }
	else if (infection_rate > 0.90)
	{
		infection_rate = 0.90;
	}
	cout << "Infection rate: " << infection_rate << "\n";
    cout << "Healthy: " << nr_Healthy << "\n";
    cout << "Infected: " << nr_Infected << "\n";
    cout << "Quarantine: " << nr_Quarantine << "\n";
    cout << "Imunee: " << nr_Imune << "\n";
}

Simulation::~Simulation()
{
}