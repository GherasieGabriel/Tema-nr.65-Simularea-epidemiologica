#include "Persoane.h"
#include <ctime>
#include <cstdlib>

Persoane::Persoane(int nr_persoane, int durata_infectare)
{
    // Initializam obiectele intital ca sanatoase
    stare = sanatos;
    zile_infectat = durata_infectare;
}
void Persoane::probabilitate_infectare(float rata_infectare, int durata_infectare)
{
    int probabilitate = rand() % 100;
    if (probabilitate < rata_infectare * 100)
    {
        this->setStare(infectat);
        this->zile_infectat = durata_infectare; // Setam durata infectarii
    }
}
void Persoane::Recuperare()
{
    if (stare == infectat || stare == carantinat)
    {
        if (zile_infectat == 0)
        {
            this->setStare(imun);
        }
        else
        {
            zile_infectat--;
        }
    }
}
void Persoane::Carantina()
{
    if (stare == infectat)
    {
        if (rand() % 100 < 70) // 70% sansa de a fi carantinat , ar putea fi pus ca si parametru in viitor
        {
            this->setStare(carantinat);
        }
    }
}
Persoane::~Persoane()
{
}