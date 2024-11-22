#include "Movement.h"
#include "Simulation.h"

sf::Vector2f Movement::getSpeed() const {
    return speed;
}

void Movement::setSpeed(const sf::Vector2f& newSpeed) {
    speed = newSpeed;
}

float Movement::getRadius() const {
    return circle.getRadius();
}

void Movement::setRadius(float radius) {
    circle.setRadius(radius);
}

sf::Vector2f Movement::getPosition() const {
    return circle.getPosition();
}

void Movement::setPosition(const sf::Vector2f& position) {
    circle.setPosition(position);
}
Movement::Movement() {
	circle.setRadius(10.f);
	circle.setFillColor(sf::Color::Green);
	circle.setPosition(0.f, 0.f);
	speed.x = (rand() % 5)-2;
	speed.y = (rand() % 5)-2;
}