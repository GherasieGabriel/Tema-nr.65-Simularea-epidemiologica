#include "Menu.h"
#include <thread>
#include <iostream>
using namespace std;
int Main_menu() {
    srand(time(0));
    int n, d, z; // n=nr person, d=durata infectare, z=zile simulare
    float r; // rata infectare
    cout << "Introduceti numarul de persoane: ";
    cin >> n;
    cout << "Introduceti durata de infectare [zile]: ";
    cin >> d;
    cout << "Introduceti rata de infectare [valori de la 0 la 1 (ex. 0.05 = 5%)]: ";
    cin >> r;
    cout << "Introduceti numarul de zile de simulare: ";
    cin >> z;
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

void Draw(int n, int d, float r, int z)
{
    Simulation sim(n, d, r, z); // crearea obiectului sim

    // Rularea simularii pentru numarul specificat de zile
    int initial_Infected = n * 0.01; // 1% din populatie Infecteda initial
    for (int i = 0; i < initial_Infected; i++) { // infectare initiala
        int first_Infected = rand() % n;
        sim.getPerson(first_Infected).setState(Infected);
        sim.getPerson(first_Infected).setDaysInfected(d);
    }
    RenderWindow window(VideoMode(1280, 720), "Simulare Epidemiologica", Style::Fullscreen);
    Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("Simplemap.png"))
    {
        std::cout << "Eroare la incarcarea imaginii de fundal" << std::endl;
    }


    Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setScale(
        window.getSize().x / backgroundSprite.getLocalBounds().width,
        window.getSize().y / backgroundSprite.getLocalBounds().height
    );


    RectangleShape exitButton(Vector2f(150.f, 50.f));
    exitButton.setPosition(1120.f, 640.f);
    exitButton.setFillColor(Color::Transparent);
    exitButton.setOutlineThickness(5.f);
    exitButton.setOutlineColor(Color::White);

    Font font;
    if (!font.loadFromFile("arial.ttf")) {
        std::cout << "Eroare la incarcarea fontului" << std::endl;
    }

    Text exitText;
    exitText.setFont(font);
    exitText.setString("Exit");
    exitText.setCharacterSize(30);
    exitText.setFillColor(Color::Red);
    exitText.setPosition(
        exitButton.getPosition().x + exitButton.getSize().x / 2 - exitText.getGlobalBounds().width / 2,
        exitButton.getPosition().y + exitButton.getSize().y / 2 - exitText.getGlobalBounds().height / 2
    );
    bool initialization=true;
    const std::chrono::seconds interval(2);
        auto start_time = std::chrono::steady_clock::now();
        int finish_simulation = 1;
        while (window.isOpen() && finish_simulation != sim.getSimulation_days()) {
            Event event;
            while (window.pollEvent(event)) {
                if (event.type == Event::Closed)
                    window.close();

                Vector2i mousePos = Mouse::getPosition(window);
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
            if (initialization==true)
            {
                for (int i = 0; i < sim.getPeople(); ++i)
                {
                    Person& person = sim.getPerson(i);
                    CircleShape circle(10.f);
                    circle.setPosition(
                        rand() % (window.getSize().x - 20),
                        rand() % (window.getSize().y - 20)
                    );
                }
				initialization = false;
            }
            window.clear();
            window.draw(backgroundSprite);
            // Draw people
            for (int i = 0; i < sim.getPeople(); ++i) {
                Movement();
                switch (person.GetState()) {
                case Healthy:
                    circle.setFillColor(Color::Green);
                    break;
                case Infected:
                    circle.setFillColor(Color::Red);
                    break;
                case Imune:
                    circle.setFillColor(Color::Blue);
                    break;
                case Quarantined:
                    circle.setFillColor(Color::Yellow);
                    break;
                }

                window.draw(circle);

            }
            auto current_time = std::chrono::steady_clock::now();
            if (current_time - start_time > interval) {
                cout << "Ziua: " << finish_simulation << endl;
                start_time = current_time;
                sim.Pandemic_Simulation();
                sim.print();
                finish_simulation++;
            }

            window.draw(exitButton);
            window.draw(exitText);

            window.display();

        }
}
