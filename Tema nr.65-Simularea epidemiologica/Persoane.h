// Persoane.h
#ifndef PERSOANE_H
#define PERSOANE_H
#include <stdlib.h>
enum Status { sanatos, infectat, imun };

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
    void probabilitate_infectare(float rata_infectare)
    {
        int probabilitate = rand() % 100;
        if (probabilitate < rata_infectare * 100)
        {
            this->setStare(infectat);
        }
    }

    // Recuperare
    void Recuperare()
    {
        if (stare == infectat)
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

    // Destructor
    ~Persoane();
};

#endif // PERSOANE_H
