#include "Person.h"
#include <cstdlib>
#include <ctime>
#include "Status.h"

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
void Person::probabilitate_infectare(float infection_rate, int infection_duration)
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
void Person::Quarantine()
{
    if (State == Status::Infected)
    {
        if (rand() % 100 < 40) // 40% sansa de a fi in carantinat
        {
            this->setState(Status::Quarantined);
        }
    }
}

// Destructor
Person::~Person()
{
}
