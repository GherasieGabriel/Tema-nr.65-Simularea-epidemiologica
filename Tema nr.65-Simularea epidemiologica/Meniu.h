#ifndef MENIU_H
#define MENIU_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include "Persoane.h"
#include "Simulare.h"
using namespace sf;
int ConfigParams();
int Epidemie();
class Individ  //clasa pentru desenarea individului
{
private:
	CircleShape cerc; //forma individului
	Vector2f viteza; //viteza individului

public:
    Individ(float raza, float x, float y) 
    {
        cerc.setRadius(raza);
		cerc.setFillColor(Color::Green); //culoarea individului
		cerc.setPosition(x, y); //pozitia individului
		viteza.x = (rand() % 5) - 2; //viteza pe axa x
		viteza.y = (rand() % 5) - 2; //viteza pe axa y
    }

    void miscare(RenderWindow& window)
    {
        cerc.move(viteza);
        if (cerc.getPosition().x <= 0 || cerc.getPosition().x + cerc.getRadius() * 2 >= window.getSize().x) {
			viteza.x = -viteza.x;  //schimbarea directiei pe axa x
        }
        if (cerc.getPosition().y <= 0 || cerc.getPosition().y + cerc.getRadius() * 2 >= window.getSize().y) {
			viteza.y = -viteza.y; //schimbarea directiei pe axa y
        }
    }

    void deseneaza(RenderWindow& window) const
    {
		window.draw(cerc); //desenarea individului
    }
};
int Imagine();
void desenare();
#endif
