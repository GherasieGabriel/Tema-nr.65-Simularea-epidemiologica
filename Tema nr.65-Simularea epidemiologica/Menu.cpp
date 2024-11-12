#include "Menu.h"
#include "Simulation.h"
#include <vector>

std::vector<Individual> indivizi;  // Vector global pentru indivizi

Individual::Individual(float raza, float x, float y) {
    circle.setRadius(raza);
    circle.setFillColor(Color::Green); // Culoarea initiala a individului
    circle.setPosition(x, y); // Pozitia initiala a individului
    speed.x = (rand() % 5) - 2; // Viteza pe axa X
    speed.y = (rand() % 5) - 2; // Viteza pe axa Y
}

void Individual::miscare(RenderWindow& window) {
    circle.move(speed); // Misca Individualul
    if (circle.getPosition().x <= 0 || circle.getPosition().x + circle.getRadius() * 2 >= window.getSize().x) {
        speed.x = -speed.x;  // Schimba directia pe axa X
    }
    if (circle.getPosition().y <= 0 || circle.getPosition().y + circle.getRadius() * 2 >= window.getSize().y) {
        speed.y = -speed.y; // Schimba directia pe axa Y
    }
}

void Individual::draw(RenderWindow& window) const {
    window.draw(circle); // Deseneaza Individualul pe fereastra SFML
}

int Menu() {
    RenderWindow window(VideoMode(1280, 720), "Meniu Principal", Style::Titlebar); // Fereastra meniului

    // incarca imaginea de fundal
    Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("Meniu.png")) {
        std::cout << "Eroare la incarcarea imaginii de fundal" << std::endl;
        return -1;
    }
    Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setScale(
        window.getSize().x / backgroundSprite.getLocalBounds().width,
        window.getSize().y / backgroundSprite.getLocalBounds().height
    );

    // incarca fontul pentru text
    Font font;
    if (!font.loadFromFile("arial.ttf")) {
        std::cout << "Eroare la incarcarea fontului" << std::endl;
        return -1;
    }

    // Creaza butonul "Play"
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

    // Creaza butonul "Exit"
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
                window.close(); // inchide fereastra daca utilizatorul apasa pe "X"

            Vector2i mousePos = Mouse::getPosition(window);
            if (playButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                playButton.setFillColor(Color(100, 100, 100)); // Schimba culoarea butonului
                if (Mouse::isButtonPressed(Mouse::Left)) {
                    Draw(); // Deschide simularea
                }
            }
            else {
                playButton.setFillColor(Color::Black);
            }

            if (exitButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                exitButton.setFillColor(Color(100, 100, 100));
                if (Mouse::isButtonPressed(Mouse::Left)) {
                    window.close(); // inchide aplicatia
                }
            }
            else {
                exitButton.setFillColor(Color::Black);
            }
        }

        window.clear();
        window.draw(backgroundSprite); // Deseneaza fundalul
        window.draw(playButton); // Deseneaza butonul "Play"
        window.draw(exitButton); // Deseneaza butonul "Exit"
        window.draw(playText); // Deseneaza textul de pe butonul "Play"
        window.draw(exitText); // Deseneaza textul de pe butonul "Exit"
        window.display(); // Actualizeaza fereastra
    }

    return 0; // inchide meniul
}

void Draw() 
{
    RenderWindow window(VideoMode(1280, 720), "Simulare Epidemiologica", Style::Fullscreen);

    // Initializare indivizi
    for (int i = 0; i < 100; ++i) {
        float x = rand() % (int)(window.getSize().x - 20) + 10; // Pozitia X
        float y = rand() % (int)(window.getSize().y - 20) + 10; // Pozitia Y
        indivizi.emplace_back(10.f, x, y); // Adauga indivizi
    }

    Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("Simplemap.png")) {
        std::cout << "Eroare la incarcarea imaginii de fundal" << std::endl;
    }

    Font font;
    if (!font.loadFromFile("arial.ttf")) {
        std::cout << "Eroare la incarcarea fontului" << std::endl;
    }

    Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setScale(
        window.getSize().x / backgroundSprite.getLocalBounds().width,
        window.getSize().y / backgroundSprite.getLocalBounds().height
    );

    // Butonul de Exit
    RectangleShape exitButton(Vector2f(150.f, 50.f));
    exitButton.setPosition(900.f, 600.f);
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
                window.close(); // Inchide fereastra daca utilizatorul apasa pe "X"
        }

        // Miscarea fiecarui Individual
        for (auto& Individual : indivizi) {
            Individual.miscare(window);
        }
        Vector2i mousePos = Mouse::getPosition(window);
        if (exitButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
            exitButton.setFillColor(Color(100, 100, 100));
            if (Mouse::isButtonPressed(Mouse::Left)) {
                window.close(); // inchide aplicatia
            }
        window.clear();
        window.draw(backgroundSprite); // Deseneaza fundalul
        // Deseneaza fiecare Individual
        for (const auto& Individual : indivizi) {
            Individual.draw(window);
        }

        window.draw(exitButton); // Deseneaza butonul de exit
        window.draw(exitText); // Deseneaza textul de pe butonul de exit
        window.display(); // Actualizeaza fereastra
    }
	}
}
