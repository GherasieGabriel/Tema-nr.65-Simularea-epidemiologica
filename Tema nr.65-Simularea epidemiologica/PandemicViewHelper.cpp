#include "PandemicViewHelper.h"
#include "Simulation.h"
#include <iostream>

PandemicViewHelper::PandemicViewHelper(sf::RenderWindow& window, const sf::Font& font) {
    // Initialize exit button
    exitButton.setSize(sf::Vector2f(150.f, 50.f));
    exitButton.setPosition(1120.f, 640.f);
    exitButton.setFillColor(sf::Color::Transparent);
    exitButton.setOutlineThickness(5.f);
    exitButton.setOutlineColor(sf::Color::White);

    // Initialize exit text
    exitText.setFont(font);
    exitText.setString("Exit");
    exitText.setCharacterSize(30);
    exitText.setFillColor(sf::Color::Red);
    exitText.setPosition(
        exitButton.getPosition().x + exitButton.getSize().x / 2 - exitText.getGlobalBounds().width / 2,
        exitButton.getPosition().y + exitButton.getSize().y / 2 - exitText.getGlobalBounds().height / 2
    );

    // Initialize labels
    healthyLabel.setFont(font);
    healthyLabel.setString("Healthy");
    healthyLabel.setCharacterSize(20);
    healthyLabel.setFillColor(sf::Color::Green);
    healthyLabel.setPosition(10.f, window.getSize().y - 80.f);

    infectedLabel.setFont(font);
    infectedLabel.setString("Infected");
    infectedLabel.setCharacterSize(20);
    infectedLabel.setFillColor(sf::Color::Red);
    infectedLabel.setPosition(10.f, window.getSize().y - 60.f);

    quarantinedLabel.setFont(font);
    quarantinedLabel.setString("Quarantined");
    quarantinedLabel.setCharacterSize(20);
    quarantinedLabel.setFillColor(sf::Color::Yellow);
    quarantinedLabel.setPosition(10.f, window.getSize().y - 40.f);

    immuneLabel.setFont(font);
    immuneLabel.setString("Immune");
    immuneLabel.setCharacterSize(20);
    immuneLabel.setFillColor(sf::Color::Blue);
    immuneLabel.setPosition(10.f, window.getSize().y - 20.f);

    // Initialize bars
    barHeight = 20.f;
    healthyBar.setFillColor(sf::Color::Green);
    infectedBar.setFillColor(sf::Color::Red);
    quarantinedBar.setFillColor(sf::Color::Yellow);
    immuneBar.setFillColor(sf::Color::Blue);

    healthyBar.setPosition(0.f, 0.f);
    infectedBar.setPosition(0.f, barHeight);
    quarantinedBar.setPosition(0.f, 2 * barHeight);
    immuneBar.setPosition(0.f, 3 * barHeight);
}

void PandemicViewHelper::draw(sf::RenderWindow& window, const Simulation& sim) {
    window.draw(exitButton);
    window.draw(exitText);
    window.draw(healthyLabel);
    window.draw(infectedLabel);
    window.draw(quarantinedLabel);
    window.draw(immuneLabel);
    window.draw(healthyBar);
    window.draw(infectedBar);
    window.draw(quarantinedBar);
    window.draw(immuneBar);
}

void PandemicViewHelper::updateBars(Simulation& sim) {
    int healthyCount = 0, infectedCount = 0, immuneCount = 0, quarantinedCount = 0;
    sim.count(healthyCount, infectedCount, immuneCount, quarantinedCount);
    float windowWidth = 1280.f; // Window width
    healthyBar.setSize(sf::Vector2f(windowWidth * (healthyCount / (float)sim.getPeople()), this->barHeight));
    infectedBar.setSize(sf::Vector2f(windowWidth * (infectedCount / (float)sim.getPeople()), this->barHeight));
    quarantinedBar.setSize(sf::Vector2f(windowWidth * (quarantinedCount / (float)sim.getPeople()), this->barHeight));
    immuneBar.setSize(sf::Vector2f(windowWidth * (immuneCount / (float)sim.getPeople()), this->barHeight));

    infectedBar.setPosition(healthyBar.getSize().x, 0.f);
    quarantinedBar.setPosition(healthyBar.getSize().x + infectedBar.getSize().x, 0.f);
    immuneBar.setPosition(healthyBar.getSize().x + infectedBar.getSize().x + quarantinedBar.getSize().x, 0.f);
}

void PandemicViewHelper::handleEvents(sf::RenderWindow& window, bool& isRunning) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();

        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        if (exitButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
            exitButton.setFillColor(sf::Color(100, 100, 100));
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                isRunning = false;
                window.close();
            }
        }
        else {
            exitButton.setFillColor(sf::Color::Transparent);
        }
    }
}
