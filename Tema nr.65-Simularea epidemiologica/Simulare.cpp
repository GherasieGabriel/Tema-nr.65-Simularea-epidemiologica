#include "Simulare.h"
#include "Persoane.h"
#include <iostream>
#include <vector>
using namespace std;
int nr_infectati;
// Implementarea constructorului
Simulare::Simulare(int nr_persoane, int durata_infectare, float rata_infectare, int zile_simulare)
    : nr_persoane(nr_persoane), durata_infectare(durata_infectare), rata_infectare(rata_infectare), zile_simulare(zile_simulare)
{
    for (int i = 0; i < nr_persoane; i++)
    {
        persoane.push_back(Persoane());
    }
}

// Simularea epidemiei
void Simulare::simulare_epidemie() {
    for (auto& persoana : persoane) {
        if (persoana.getStare() == sanatos) {
            persoana.probabilitate_infectare(rata_infectare);
        }
        else if (persoana.getStare() == infectat) {
            persoana.Recuperare();
        }
    }
}

// Afisarea rezultatelor
void  Simulare::afisare()
{
    int sanatosi = 0, infectati = 0, imuni = 0;
    for (const auto& persoana : persoane)
    {
        if (persoana.getStare() == sanatos)
            sanatosi++;
        else if (persoana.getStare() == infectat)
            infectati++;
        else if (persoana.getStare() == imun)
            imuni++;
    }
    if (infectati > nr_infectati)
    {
        
            rata_infectare = rata_infectare + (infectati-nr_infectati)*0.02;
        nr_infectati = infectati;
    }
    else if (infectati < nr_infectati)
    {
        rata_infectare = rata_infectare - (nr_infectati - infectati )*0.02;
		nr_infectati = infectati;
    }
    cout << "Sanatosi: " << sanatosi << "\n";
    cout << "Infectati: " << infectati << "\n";
    cout << "Imuni: " << imuni << "\n";
}

Simulare::~Simulare()
{
}
