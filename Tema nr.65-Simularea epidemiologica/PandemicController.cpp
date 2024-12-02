#include "Pandemic.h"
using namespace std;
void Begin_Simulation()
{
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
	char c; // variabila pentru alegerea modului de reprezentare
    cout << "Introduceti 'g' pentru reprezentare grafica si 't' pentru reprezentare text" << endl;
    cin >> c;
    while (c != 'g' && c != 't')
    {
        cout << "Nu ai introdus o optiune corecta,intoduce 'g' pentru reprezentare grafica,respectiv 't' pentru repezentare text" << endl;
        cin >> c;
    }
    if (c == 't')
    {
		Text_Menu(n, d, r, z);
    }
    else if (c == 'g')
    {
        Main_Menu(n, d, r, z);
    }
}
void Text_Menu(int n, int d, float r, int z)
{
    srand(time(0));
    Simulation sim(n, d, r, z); // crearea obiectului sim

    // Rularea simularii pentru numarul specificat de zile
    int initial_Infected = n * 0.01; // 1% din populatie Infecteda initial
    for (int i = 0; i < initial_Infected; i++) { // infectare initiala
        int first_Infected = rand() % n;
        sim.getPerson(first_Infected).setState(Infected);
        sim.getPerson(first_Infected).setDaysInfected(d);
    }
    for (int zi = 0; zi < z; zi++) { // simulare
        cout << "Ziua " << zi + 1 << ":\n";
        sim.Pandemic_Simulation();
        sim.print();
        cout << "\n";
        bool infected_people_remaining = false; // verificare daca mai exista person Infectede
        for (int person = 0; person < sim.getPeople(); person++)
        {
            if (sim.getPerson(person).GetState() == Infected || sim.getPerson(person).GetState() == Quarantined) {
                infected_people_remaining = true;
                break;
            }
        }

        if (infected_people_remaining == false) { // oprirea simularii daca nu mai exista person Infectede
            cout << "Nu mai exista persoane Infectate. Oprirea simularii.\n";
            break;
        }
        this_thread::sleep_for(chrono::milliseconds(1000)); // pauza de 1 secunda
    }
}