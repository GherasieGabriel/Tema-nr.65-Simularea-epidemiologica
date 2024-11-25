#ifndef MOVEMENT_H
#define MOVEMENT_H
#include <SFML/Graphics.hpp>
using namespace sf;
class Movement {
private:
	sf::CircleShape circle;  // Aparenta individului
	sf::Vector2f speed;      // Viteza individului

public:
	Movement(); // Constructor implicit
	Movement(sf::CircleShape circle); // Constructor de initializare

	void miscare(sf::RenderWindow& window); // Miscarea individului

	sf::Vector2f getSpeed() const; // Getter pentru viteza
	void setSpeed(const sf::Vector2f& newSpeed); // Setter pentru viteza
	float getRadius() const; // Getter pentru raza
	void setRadius(float radius); // Setter pentru raza

    sf::Vector2f getPosition() const; // Getter pentru pozitie
	void setPosition(const sf::Vector2f& position); // Setter pentru pozitie
};

#endif // MOVEMENT_H