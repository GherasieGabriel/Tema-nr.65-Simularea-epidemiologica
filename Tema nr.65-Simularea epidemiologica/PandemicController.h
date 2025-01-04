#ifndef PANDEMICCONTROLLER_H
#define PANDEMICCONTROLLER_H

#include "PandemicView.h"
#include "Simulation.h"

class PandemicController {
private:
	PandemicView view; // View object
	Simulation model; // Model object

public:
    PandemicController();
    void runSimulation();
};

#endif // PANDEMICCONTROLLER_H