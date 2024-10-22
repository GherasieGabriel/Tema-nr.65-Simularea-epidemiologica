#include "Persoane.h"
#include <ctime>
#include <cstdlib>

Persoane::Persoane(int nr_persoane,int durata_infectare)
{
    // Initializam obiectele intital ca sanatoase
    stare = sanatos;
    zile_infectat = durata_infectare;
}

Persoane::~Persoane()
{
}
