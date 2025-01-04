#ifndef PERSON_H
#define PERSON_H
#include "Status.h"
#include <cstdlib>
#include <ctime>
class Person
{
private :
	int days_Infected; // Days infected per person
    Status State;
public:
	// Default constructor
    Person() : State(Healthy) {}

	// Constructor with parameters
    Person(int nr_people, int infection_duration);

	// Getter for 'State'
    Status GetState() const;

	// Setter for 'State'
    void setState(Status newState);
	// Infection probability
    void probabilitate_infectare(float infection_rate, int infection_duration);

    // Recovery
    void Recovery();

	void Quarantine(float quarantine_ratio);// Function to apply quarantine if infected
    
	int getdays_infected(int days_infected);// Function to get the number of days infected

	void setDaysInfected(int days_infected);// Function to set the number of days infected
    // Destructor
    ~Person();
};

#endif // person_H