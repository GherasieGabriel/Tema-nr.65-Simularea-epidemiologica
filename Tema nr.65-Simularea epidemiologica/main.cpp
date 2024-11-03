#pragma warning (disable:4996)
#include "Simulare.h"
#include "Persoane.h"
#include <ctime>
using namespace std;
#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>
#include <thread>
#include "Meniu.h"
int main()
{
    srand(time(0));
    int n, d, z; // n=nr persoane, d=durata infectare, z=zile simulare
    float r; // rata infectare
    cout << "Introduceti numarul de persoane: ";
    cin >> n;
    cout << "Introduceti durata de infectare [zile]: ";
    cin >> d;
    cout << "Introduceti rata de infectare [valori de la 0 la 1 (ex. 0.05 = 5%)]: ";
    cin >> r;
    cout << "Introduceti numarul de zile de simulare: ";
    cin >> z;
	Imagine(); // Putem sa comentam ca sa rulam doar simularea
    Simulare sim(n, d, r, z); // crearea obiectului sim

    // Rularea simularii pentru numarul specificat de zile
    int initial_infectati = n * 0.01; // 1% din populatie infectata initial
    for (int i = 0; i < initial_infectati; i++) { // infectare initiala
        int primii_infectati = rand() % n;
        sim.persoane[primii_infectati].setStare(infectat);
        sim.persoane[primii_infectati].zile_infectat = d;
    }
    for (int zi = 0; zi < z; zi++) { // simulare
        cout << "Ziua " << zi + 1 << ":\n";
        sim.simulare_epidemie();
        sim.afisare();
        cout << "\n";
        bool persone_infectate_ramase = false; // verificare daca mai exista persoane infectate
        for (const auto& persoana : sim.persoane) {
            if (persoana.getStare() == infectat || persoana.getStare() == carantinat) {
                persone_infectate_ramase = true;
                break;
            }
        }

        if (persone_infectate_ramase == false) { // oprirea simularii daca nu mai exista persoane infectate
            cout << "Nu mai exista persoane infectate. Oprirea simularii.\n";
            break;
        }
        this_thread::sleep_for(chrono::milliseconds(500)); // pauza de 500ms
    }

    return 0;
}