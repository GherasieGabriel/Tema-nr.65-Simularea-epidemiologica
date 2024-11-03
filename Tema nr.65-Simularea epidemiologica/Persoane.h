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
    void probabilitate_infectare(float rata_infectare, int durata_infectare)
    {
        int probabilitate = rand() % 100;
        if (probabilitate < rata_infectare * 100)
        {
            this->setStare(infectat);
            this->zile_infectat = durata_infectare; // Setam durata infectarii
        }
    }

    // Recuperare
    void Recuperare()
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

    void Carantina()
    {
        if (stare == infectat)
        {
			if (rand() % 100 < 70) // 70% sansa de a fi carantinat , ar putea fi pus ca si parametru in viitor
            {
                this->setStare(carantinat);
            }
        }
    }

    // Destructor
    ~Persoane();
};

#endif // PERSOANE_H