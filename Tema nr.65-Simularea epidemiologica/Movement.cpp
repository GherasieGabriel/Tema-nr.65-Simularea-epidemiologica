#include "Movement.h"


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

Movement::Movement(sf::CircleShape circle) : circle(circle) 
    {
        speed.x = (rand() % 5) - 2;
        speed.y = (rand() % 5) - 2;
    }
	