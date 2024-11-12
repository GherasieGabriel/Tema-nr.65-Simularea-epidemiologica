#ifndef MENIU_H
#define MENIU_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include "Person.h"
#include "Simulation.h"

using namespace sf;

int ConfigParams();
int Pandemic();

class Individual {
public:
    CircleShape circle; // Forma individului
    Vector2f speed; // Viteza individului

    Individual(float raza, float x, float y); // Constructorul clasei Individual
    void miscare(RenderWindow& window); // Misca Individualul
    void draw(RenderWindow& window) const; // Deseneaza Individualul
};

int Menu(); // Functia pentru desenarea meniului
void Draw(); // Functia pentru a desena si simula indivizii
#endif
