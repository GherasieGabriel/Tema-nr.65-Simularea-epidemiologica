#include "Person.h"
// Constructor
Person::Person(int nr_people, int infection_duration)
{
    // Initializare obiect ca sanatos
    State = Status::Healthy;
    days_Infected = infection_duration;
}

// Getter pentru starea curenta a persoanei
Status Person::GetState() const
{
    return State;
}

// Setter pentru starea persoanei
void Person::setState(Status newState)
{
    this->State = newState;
}

// Probabilitate de infectare
void Person::attemptInfection(float infection_rate, int infection_duration)
{
    int probabilitate = rand() % 100;
    if (probabilitate < infection_rate * 100)
    {
        this->setState(Status::Infected);
        this->days_Infected = infection_duration; // Setam durata infectarii
    }
}

// Verificare recuperare
void Person::Recovery()
{
    if (State == Status::Infected || State == Status::Quarantined)
    {
        if (days_Infected == 0)
        {
            this->setState(Status::Imune);
        }
        else
        {
            days_Infected--;
        }
    }
}

// Aplicare carantina daca este infectat
void Person::applyQuarantine(float quarantine_ratio)
{
    if (State == Status::Infected)
    {
        if (rand() % 100 < quarantine_ratio * 100) // Sansa de a fi in carantinat
        {
            this->setState(Status::Quarantined);
        }
    }
}

int Person::getDaysinfected(int days_infected) const
{
	return days_infected;
}

void Person::setDaysInfected(int days_infected)
{
	this->days_Infected = days_infected;
}

// Destructor
Person::~Person()
{
}
