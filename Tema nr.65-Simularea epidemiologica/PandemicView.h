// --- PandemicView.h ---
#ifndef PANDEMICVIEW_H
#define PANDEMICVIEW_H

#include "Simulation.h"
#include <SFML/Graphics.hpp>

class PandemicView {
public:
	void renderMenu(); // Render the input menu
	void renderTextSimulation(Simulation& simulation); // Render the text-based simulation
	void renderGraphicalSimulation(Simulation& simulation); // Render the graphical simulation
};

#endif // PANDEMICVIEW_H