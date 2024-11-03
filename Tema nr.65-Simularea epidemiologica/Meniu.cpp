#include "Meniu.h"
#include "Simulare.h"
#include <vector>
// Vector global pentru indivizi
std::vector<Individ> indivizi;  //vector pentru indivizi
int Imagine() //functie pentru desenarea meniului
{
    ContextSettings settings;
    settings.antialiasingLevel = 8;
	RenderWindow window(VideoMode(1280, 720), "Meniu Principal", Style::Titlebar);  //fereastra cu dimensiunile 1280x720

    // Încarcare imagine de fundal
    Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("Meniu.png"))
    {
		std::cout << "Eroare la incarcarea imaginii de fundal" << std::endl; //mesaj de eroare
        return -1;
    }
	Sprite backgroundSprite; //sprite pentru imaginea de fundal
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setScale(
        window.getSize().x / backgroundSprite.getLocalBounds().width,
        window.getSize().y / backgroundSprite.getLocalBounds().height
    );

    Font font;
    if (!font.loadFromFile("arial.ttf"))
    {
		std::cout << "Eroare la incarcarea fontului" << std::endl; //mesaj de eroare
        return -1;
    }

	RectangleShape playButton(Vector2f(300.f, 100.f)); //buton pentru a incepe jocul
    playButton.setPosition(490.f, 300.f);
    playButton.setFillColor(Color::Black);
    playButton.setOutlineThickness(10.f);
    playButton.setOutlineColor(Color::White);

	Text playText; //text pentru butonul de play
    playText.setFont(font);
    playText.setString("Play");
    playText.setCharacterSize(40);
    playText.setFillColor(Color::Red);
    playText.setPosition(
		playButton.getPosition().x + playButton.getSize().x / 2 - playText.getGlobalBounds().width / 2, //pozitia textului
		playButton.getPosition().y + playButton.getSize().y / 2 - playText.getGlobalBounds().height / 2  //pozitia textului
    );

	RectangleShape exitButton(Vector2f(300.f, 100.f)); //buton pentru a iesi din joc
    exitButton.setPosition(490.f, 450.f);
    exitButton.setFillColor(Color::Transparent);
    exitButton.setOutlineThickness(10.f);
    exitButton.setOutlineColor(Color::White);

	Text exitText; //text pentru butonul de exit
    exitText.setFont(font);
    exitText.setString("Exit");
    exitText.setCharacterSize(40);
    exitText.setFillColor(Color::Red);
    exitText.setPosition(
        exitButton.getPosition().x + exitButton.getSize().x / 2 - exitText.getGlobalBounds().width / 2,
        exitButton.getPosition().y + exitButton.getSize().y / 2 - exitText.getGlobalBounds().height / 2
    );

	while (window.isOpen()) //cat timp fereastra este deschisa
    {
		Event event; //eveniment
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
				window.close(); //inchiderea ferestrei

            Vector2i mousePos = Mouse::getPosition(window);
            if (playButton.getGlobalBounds().contains(mousePos.x, mousePos.y))
            {
                playButton.setFillColor(Color(100, 100, 100)); 
				if (Mouse::isButtonPressed(Mouse::Left)) //daca se apasa butonul de play
                {
					desenare();  // Deschide ecranul de desenare a indivizilor
                }
            }
            else
            {
				playButton.setFillColor(Color::Black); //culoarea butonului
            }

            if (exitButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) 
            {
                exitButton.setFillColor(Color(100, 100, 100)); 
				if (Mouse::isButtonPressed(Mouse::Left)) //daca se apasa butonul de exit
				{
					window.close(); //inchiderea ferestrei
				}
            }
            else
            {
                exitButton.setFillColor(Color::Black);
            }
        }

		window.clear(); //curatarea ferestrei
		window.draw(backgroundSprite); //desenarea imaginii de fundal
		window.draw(playButton); //desenarea butonului de play
		window.draw(exitButton); //desenarea butonului de exit
		window.draw(playText); //desenarea textului pentru butonul de play
		window.draw(exitText); //desenarea textului pentru butonul de exit
		window.display(); //afisarea ferestrei
    }

	return 0; //returneaza 0
}
//functie pentru desenarea indivizilor //TODO: implementare cu infectia/epidemia(desenarea infectatilor,imunilor,sanatosilor,etc)
void desenare()
{
    ContextSettings settings;
    settings.antialiasingLevel = 8;
    RenderWindow window(VideoMode(1280, 720), "Simulare Epidemiologica", Style::Fullscreen);

    // Ini?ializarea indivizilor
    for (int i = 0; i < 100; ++i) { // 100 de indivizi
        float x = rand() % (int)(window.getSize().x - 20) + 10; // pentru a evita coliziunile cu marginile
        float y = rand() % (int)(window.getSize().y - 20) + 10; // pentru a evita coliziunile cu marginile
        indivizi.emplace_back(10.f, x, y); // buline cu raza de 10 pixeli
    }

    Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("Simplemap.png"))
    {
        std::cout << "Eroare la incarcarea imaginii de fundal" << std::endl;
    }

    Font font;
    if (!font.loadFromFile("arial.ttf"))
    {
        std::cout << "Eroare la incarcarea fontului" << std::endl;
    }

    Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setScale(
        window.getSize().x / backgroundSprite.getLocalBounds().width,
        window.getSize().y / backgroundSprite.getLocalBounds().height
    );

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

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        Vector2i mousePos = Mouse::getPosition(window);
        if (exitButton.getGlobalBounds().contains(mousePos.x, mousePos.y))
        {
            exitButton.setFillColor(Color(100, 100, 100));
			if (Mouse::isButtonPressed(Mouse::Left)) //daca se apasa butonul de exit
            {
                window.close();
            }
        }
        else
        {
            exitButton.setFillColor(Color::Black);
        }

		// Miscarea fiecarui individ
        for (auto& individ : indivizi)
        {
            individ.miscare(window);
        }

        window.clear();
        window.draw(backgroundSprite);
        // Deseneaza fiecare individ
        for (const auto& individ : indivizi)
        {
            individ.deseneaza(window);
        }
        window.draw(exitButton);
        window.draw(exitText);
        window.display();
    }
}
