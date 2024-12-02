#include "Menu.h"

using namespace std;
int Main_Menu(int n,int d,float r,int z) {
    srand(time(0));
    
    RenderWindow window(VideoMode(1280, 720), "Meniu Principal", Style::Titlebar); // Fereastra meniului
	// Incarcare imagine de fundal
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

	// Incarcare font
    Font font;
    if (!font.loadFromFile("arial.ttf")) {
        std::cout << "Eroare la incarcarea fontului" << std::endl;
        return -1;
    }

	// Creare buton "Play"
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

	// Creare buton "Exit"
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
				window.close(); // Inchide fereastra daca utilizatorul apasa pe "X"

            Vector2i mousePos = Mouse::getPosition(window);
            if (playButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
				playButton.setFillColor(Color(100, 100, 100)); // Schimba culoarea butonului la hover
                if (Mouse::isButtonPressed(Mouse::Left)) {
                    Draw(n,d,r,z); // Deseneaza simularea
                }
            }
            else {
                playButton.setFillColor(Color::Black);
            }

            if (exitButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                exitButton.setFillColor(Color(100, 100, 100));
                if (Mouse::isButtonPressed(Mouse::Left)) {
					window.close(); // Inchide fereastra
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

	return 0; // Inchide aplicatia
}
