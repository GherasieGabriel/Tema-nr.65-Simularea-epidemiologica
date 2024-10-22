// Simulare.h
#ifndef SIMULARE_H
#define SIMULARE_H

#include "Persoane.h"
#include <vector>

class Simulare
{
public:
    int nr_persoane;
    int durata_infectare;
    float rata_infectare;
    int zile_simulare;

    // Vector pentru obiecte persoane
    std::vector<Persoane> persoane;

    // Constructor
    Simulare(int nr_persoane, int durata_infectare, float rata_infectare, int zile_simulare);

    // Simulare epidemiei
    void simulare_epidemie();

    // Afisarea rezultatelor
    void afisare();

    // Destructor
    ~Simulare();
};

#endif // SIMULARE_H
