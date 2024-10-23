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
    for (int i = 0; i < nr_persoane; i++) {
        if (persoane[i].getStare() == sanatos) {
            persoane[i].probabilitate_infectare(rata_infectare, durata_infectare);
        }
        else if (persoane[i].getStare() == infectat) {
            persoane[i].Carantina();
        }
        persoane[i].Recuperare();
    }
}

// Afisarea rezultatelor
void  Simulare::afisare()
{
    int sanatosi = 0, infectati = 0, imuni = 0,nr_carantinati=0;
    for (const auto& persoana : persoane)
    {
        if (persoana.getStare() == sanatos)
            sanatosi++;
        else if (persoana.getStare() == infectat)
            infectati++;
        else if (persoana.getStare() == imun)
            imuni++;
        else if (persoana.getStare() == carantinat)
            nr_carantinati++;
    }
    if (infectati > nr_infectati)
    {
        
            rata_infectare = rata_infectare + (infectati-nr_infectati)*0.01;
        nr_infectati = infectati;
    }
    else if (infectati < nr_infectati)
    {
        rata_infectare = rata_infectare - (nr_infectati - infectati )*0.01;
		nr_infectati = infectati;
    }
    cout << "Sanatosi: " << sanatosi << "\n";
    cout << "Infectati: " << infectati << "\n";
	cout << "Carantinati: " << nr_carantinati << "\n";
    cout << "Imuni: " << imuni << "\n";
}

Simulare::~Simulare()
{
}
