#ifndef PANDEMICVIEWHELPER_H
#define PANDEMICVIEWHELPER_H

#include <SFML/Graphics.hpp>
#include "Simulation.h"

class PandemicViewHelper {
public:
	PandemicViewHelper(sf::RenderWindow& window, const sf::Font& font); // Constructor
	void draw(sf::RenderWindow& window, const Simulation& sim); // Draw the simulation
	void updateBars(Simulation& sim); // Update the bars
	void handleEvents(sf::RenderWindow& window, bool& isRunning); // Handle events

private:
    sf::RectangleShape exitButton;
    sf::Text exitText;
    sf::Text healthyLabel, infectedLabel, quarantinedLabel, immuneLabel;
    sf::RectangleShape healthyBar, infectedBar, immuneBar, quarantinedBar;
    std::vector<sf::Vector2f> circlePositions;
    float barHeight;
};

#endif // PANDEMICVIEWHELPER_H
