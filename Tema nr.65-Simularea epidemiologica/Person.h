#ifndef PERSON_H
#define PERSON_H
#include <stdlib.h>
#include <iostream>
#include "Status.h"
class Person
{
public:
    int days_Infected; // Numarul de zile pana cand persoana devine Imunea
    Status State;

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
    

    // Destructor
    ~Person();
};

#endif // person_H