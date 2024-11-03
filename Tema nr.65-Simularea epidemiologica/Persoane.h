#ifndef PERSOANE_H
#define PERSOANE_H
#include <stdlib.h>
#include <iostream>

enum Status { sanatos, infectat, imun, carantinat };

class Persoane
{
public:
    int zile_infectat; // Numarul de zile pana cand persoana devine imuna
    Status stare;

    // Constructor fara parametrii
    Persoane() : stare(sanatos) {}

    // Constructor cu parametrii
    Persoane(int nr_persoane, int durata_infectare);

    // Getter pentru 'stare'
    Status getStare() const
    {
        return stare;
    }

    // Schimbator pentru 'stare'
    void setStare(Status stare)
    {
        this->stare = stare;
    }

    // Probabilitate de infectie
    void probabilitate_infectare(float rata_infectare, int durata_infectare);

    // Recuperare
    void Recuperare();

   void Carantina();// Functie pentru a pune persoanele infectate in carantina
    

    // Destructor
    ~Persoane();
};

#endif // PERSOANE_H