#ifndef PERSON_H
#define PERSON_H
#include "Status.h"
#include <cstdlib>
#include <ctime>
class Person
{
private :
    int days_Infected; // Numarul de zile pana cand persoana devine Imunea
    Status State;
public:
    // Constructor fara parametrii
    Person() : State(Healthy) {}

    // Constructor cu parametrii
    Person(int nr_people, int infection_duration);

    // Getter pentru 'State'
    Status GetState() const;

    // Schimbator pentru 'State'
    void setState(Status newState);
    // Probabilitate de infectie
    void probabilitate_infectare(float infection_rate, int infection_duration);

    // Recovery
    void Recovery();

   void Quarantine();// Functie pentru a pune personle Infectede in Quarantine
    
   int getdays_infected(int days_infected);// Functie pentru a obtine numarul de zile infectate

   void setDaysInfected(int days_infected);// Functie pentru a seta numarul de zile infectate
    // Destructor
    ~Person();
};

#endif // person_H