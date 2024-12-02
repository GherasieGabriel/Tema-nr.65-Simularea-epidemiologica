#include "Menu.h"
void Draw(int n, int d, float r, int z)
{
    Simulation sim(n, d, r, z);
    // Configurarea initiala a infectiei
    int initial_Infected = n * 0.01; // 1% din populatie este initial infectata
    for (int i = 0; i < initial_Infected; i++) {
        int first_Infected = rand() % n;
        sim.getPerson(first_Infected).setState(Infected);
        sim.getPerson(first_Infected).setDaysInfected(d);
    }

    RenderWindow window(VideoMode(1280, 720), "Simulare Epidemiologica", Style::Fullscreen);
    Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("Simplemap.png")) {
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

    // Vector pentru a stoca pozitiile cercurilor
    std::vector<Vector2f> circlePositions(n);
    bool initialization = true;
    const std::chrono::seconds interval(1);
    auto start_time = std::chrono::steady_clock::now();
    int finish_simulation = 1;
    for (int i = 0; i < n; ++i) {
        circlePositions[i] = Vector2f(rand() % (window.getSize().x - 20), rand() % (window.getSize().y - 20));
    }
    RectangleShape healthyBar(Vector2f(0.f, 20.f));
    RectangleShape infectedBar(Vector2f(0.f, 20.f));
    RectangleShape imuneBar(Vector2f(0.f, 20.f));
    RectangleShape quarantinedBar(Vector2f(0.f, 20.f));

    // Setarea culorilor
    healthyBar.setFillColor(Color::Green);
    infectedBar.setFillColor(Color::Red);
    quarantinedBar.setFillColor(Color::Yellow);
    imuneBar.setFillColor(Color::Blue);

    // Setarea pozitiei initiale
    float barHeight = 20.f;
    healthyBar.setPosition(0.f, 0.f);
    infectedBar.setPosition(0.f, barHeight);
    quarantinedBar.setPosition(0.f, 2 * barHeight);
    imuneBar.setPosition(0.f, 3 * barHeight);
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

        // Calculam dimensiunea cercului in functie de numarul de persoane
        float circleSize = std::max(2.f, 1000.f / n); // Dimensiune minima de 3 pentru cerc
        int healthyCount = 0, infectedCount = 0, immuneCount = 0, quarantinedCount = 0;

        // Numaram persoanele in functie de starea lor
        for (int i = 0; i < sim.getPeople(); ++i) {
            switch (sim.getPerson(i).GetState()) {
            case Healthy:
                healthyCount++;
                break;
            case Infected:
                infectedCount++;
                break;
            case Imune:
                immuneCount++;
                break;
            case Quarantined:
                quarantinedCount++;
                break;
            }
        }
        float windowWidth = window.getSize().x;
        healthyBar.setSize(Vector2f(windowWidth * (healthyCount / (float)sim.getPeople()), barHeight));
        infectedBar.setSize(Vector2f(windowWidth * (infectedCount / (float)sim.getPeople()), barHeight));
        quarantinedBar.setSize(Vector2f(windowWidth * (quarantinedCount / (float)sim.getPeople()), barHeight));
        imuneBar.setSize(Vector2f(windowWidth* (immuneCount / (float)sim.getPeople()), barHeight));

        // Setam pozitiile pentru a fi una langa cealalta
        infectedBar.setPosition(healthyBar.getSize().x, 0.f);
        quarantinedBar.setPosition(healthyBar.getSize().x + infectedBar.getSize().x, 0.f);
        imuneBar.setPosition(healthyBar.getSize().x + infectedBar.getSize().x + quarantinedBar.getSize().x, 0.f);
        // Desenam fundalul o singura data pe cadru
        window.clear(); // Curatam fereastra
        window.draw(backgroundSprite); // Desenam fundalul

        for (int i = 0; i < sim.getPeople(); ++i) {
            Person& person = sim.getPerson(i);
            CircleShape circle(circleSize); // Folosim circleSize pentru dimensiunea cercului
            circle.setPosition(circlePositions[i]);

            // Setam culoarea cercului in functie de starea persoanei
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
            }
            window.draw(circle); // Desenam cercul
        }

        auto current_time = std::chrono::steady_clock::now();
        if (current_time - start_time > interval) {
            std::cout << "Ziua: " << finish_simulation + 1 << std::endl;
            start_time = current_time;
            sim.Pandemic_Simulation();
            sim.print();
            finish_simulation++;
        }
        bool infected_people_remaining = false; // verificare daca mai exista person Infectete
        for (int person = 0; person < sim.getPeople(); person++)
        {
            if (sim.getPerson(person).GetState() == Infected || sim.getPerson(person).GetState() == Quarantined) {
                infected_people_remaining = true;
                break;
            }
        }

        if (infected_people_remaining == false) { // oprirea simularii daca nu mai exista person Infectede
            std::cout << "Nu mai exista persoane Infectate. Oprirea simularii.\n";
            break;
        }

        window.draw(exitButton); // Desenam butonul de iesire
        window.draw(exitText); // Desenam textul de iesire
        window.draw(healthyBar);
        window.draw(infectedBar);
        window.draw(quarantinedBar);
        window.draw(imuneBar); 
        window.display(); // Afisam totul pe fereastra
    }
}