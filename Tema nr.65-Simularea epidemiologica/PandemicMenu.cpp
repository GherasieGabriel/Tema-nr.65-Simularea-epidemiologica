#include "PandemicController.h"
#include <iostream>

using namespace sf;

int Main_Menu() {
    RenderWindow window(VideoMode(1280, 720), "Meniu Principal", Style::Titlebar);

    Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("Meniu.png")) {
        std::cerr << "Eroare la incarcarea imaginii de fundal\n";
        return -1;
    }

    Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setScale(
        window.getSize().x / backgroundSprite.getLocalBounds().width,
        window.getSize().y / backgroundSprite.getLocalBounds().height
    );

    Font font;
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Eroare la incarcarea fontului\n";
        return -1;
    }

    RectangleShape playButton(Vector2f(300.f, 100.f));
    playButton.setPosition(490.f, 300.f);
    playButton.setFillColor(Color::Black);
    playButton.setOutlineThickness(10.f);
    playButton.setOutlineColor(Color::White);

    Text playText;
    playText.setFont(font);
    playText.setString("Play");
    playText.setCharacterSize(40);
    playText.setFillColor(Color::Red);
    playText.setPosition(
        playButton.getPosition().x + playButton.getSize().x / 2 - playText.getGlobalBounds().width / 2,
        playButton.getPosition().y + playButton.getSize().y / 2 - playText.getGlobalBounds().height / 2
    );

    RectangleShape exitButton(Vector2f(300.f, 100.f));
    exitButton.setPosition(490.f, 450.f);
    exitButton.setFillColor(Color::Transparent);
    exitButton.setOutlineThickness(10.f);
    exitButton.setOutlineColor(Color::White);

    Text exitText;
    exitText.setFont(font);
    exitText.setString("Exit");
    exitText.setCharacterSize(40);
    exitText.setFillColor(Color::Red);
    exitText.setPosition(
        exitButton.getPosition().x + exitButton.getSize().x / 2 - exitText.getGlobalBounds().width / 2,
        exitButton.getPosition().y + exitButton.getSize().y / 2 - exitText.getGlobalBounds().height / 2
    );

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();

            Vector2i mousePos = Mouse::getPosition(window);
            if (playButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                playButton.setFillColor(Color(100, 100, 100));
                if (Mouse::isButtonPressed(Mouse::Left)) {
                    PandemicController controller;
                    controller.runSimulation();
                }
            }
            else {
                playButton.setFillColor(Color::Black);
            }

            if (exitButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                exitButton.setFillColor(Color(100, 100, 100));
                if (Mouse::isButtonPressed(Mouse::Left)) {
                    window.close();
                }
            }
            else {
                exitButton.setFillColor(Color::Transparent);
            }
        }

        window.clear();
        window.draw(backgroundSprite);
        window.draw(playButton);
        window.draw(exitButton);
        window.draw(playText);
        window.draw(exitText);
        window.display();
    }

    return 0;
}
