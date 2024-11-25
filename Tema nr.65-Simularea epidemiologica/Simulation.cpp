#include "Simulation.h"

using namespace std;
int previously_infected;
void Begin_Simulation()
{
    char c;
    cout << "Introduceti 'g' pentru reprezentare grafica si 't' pentru reprezentare text"<<endl;
    cin >> c;  
    while (c != 'g' && c != 't')
        {
            cout << "Nu ai introdus o optiune corecta,intoduce 'g' pentru reprezentare grafica,respectiv 't' pentru repezentare text"<<endl;
            cin >> c;
        }
    if (c == 't')
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

        Simulation sim(n, d, r, z); // crearea obiectului sim

        // Rularea simularii pentru numarul specificat de zile
        int initial_Infected = n * 0.01; // 1% din populatie Infecteda initial
        for (int i = 0; i < initial_Infected; i++) { // infectare initiala
            int first_Infected = rand() % n;
            sim.getPerson(first_Infected).setState(Infected);
            sim.getPerson(first_Infected).setDaysInfected(d);
        }
        for (int zi = 0; zi < z; zi++) { // simulare
            cout << "Ziua " << zi + 1 << ":\n";
            sim.Pandemic_Simulation();
            sim.print();
            cout << "\n";
            bool infected_people_remaining = false; // verificare daca mai exista person Infectede
            for (int person = 0; person < sim.getPeople(); person++)
            {
                if (sim.getPerson(person).GetState() == Infected || sim.getPerson(person).GetState() == Quarantined) {
                    infected_people_remaining = true;
                    break;
                }
            }

            if (infected_people_remaining == false) { // oprirea simularii daca nu mai exista person Infectede
                cout << "Nu mai exista persoane Infectate. Oprirea simularii.\n";
                break;
            }
            this_thread::sleep_for(chrono::milliseconds(1000)); // pauza de 1 secunda
        }
    }
    else if (c == 'g')
    {
        Main_menu();
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
    cout << "Infection rate: " << infection_rate << "\n";
    cout << "Healthy: " << nr_Healthy << "\n";
    cout << "Infected: " << nr_Infected << "\n";
    cout << "Quarantine: " << nr_Quarantine << "\n";
    cout << "Imunee: " << nr_Imune << "\n";
}

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
void Simulation::Initializer(int nr_people, int infection_duration, float infection_rate, int simulation_days)
{
    this->nr_people = nr_people;
    this->infection_duration = infection_duration;
    this->infection_rate = infection_rate;
    this->simulation_days = simulation_days;

    people.clear();
    for (int i = 0; i < nr_people; i++) {
        people.push_back(Person());
    }
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
Simulation::Simulation()
    : nr_people(0), infection_duration(0), infection_rate(0.0f), simulation_days(0) {
	// Initializare vector gol
}
Simulation::~Simulation()
{
}
