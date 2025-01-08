#include "PandemicView.h"
#include "PandemicViewHelper.h"
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;
using namespace sf;

void PandemicView::renderGraphicalSimulation(Simulation& sim) { // Render the graphical simulation
   
	sim.initializeInfected(); // Set the initial infected people
    RenderWindow window(VideoMode(1280, 720), "Simulare Epidemiologica", Style::Fullscreen); // Fullscreen window

    Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("Simplemap.png")) {
        std::cerr << "Eroare la incarcarea imaginii de fundal\n";
        return;
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
        return;
    }

    PandemicViewHelper viewHelper(window, font);

    std::vector<Vector2f> circlePositions(sim.getPeople()); // Vector to store circle positions
    for (int i = 0; i < sim.getPeople(); ++i) {
        circlePositions[i] = Vector2f(rand() % (window.getSize().x - 20), rand() % (window.getSize().y - 20));
    }

    const std::chrono::seconds interval(1);
    auto start_time = std::chrono::steady_clock::now();
    bool isRunning = true;
	int days = 1;
    while (window.isOpen() && isRunning) {
        viewHelper.handleEvents(window, isRunning);

        float circleSize = std::max(2.f, 1000.f / sim.getPeople());
        window.clear();
        window.draw(backgroundSprite);
        for (int i = 0; i < sim.getPeople(); ++i) {
            Person& person = sim.getPerson(i);
            CircleShape circle(circleSize);
            circle.setPosition(circlePositions[i]);

            switch (person.GetState()) { // Set circle color based on person state
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

        viewHelper.updateBars(sim);
        viewHelper.draw(window, sim);
        window.display();

        if (std::chrono::steady_clock::now() - start_time > interval) { // Update simulation every second
			sim.runSimulation();
			cout << "Day " << days << ":\n";
            sim.displaySimulationStatus();
            start_time = std::chrono::steady_clock::now();
			days++;
        }

		if (sim.hasActiveInfections() == false) {
			isRunning = false;
		}
    }
}
