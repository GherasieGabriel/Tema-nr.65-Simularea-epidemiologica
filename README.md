# Tema nr.65-Simularea epidemiologica
Acest proiect este o simulare a răspândirii unei boli infectioase într-o populație. Scopul este de a modela și vizualiza modul în care o boală se poate răspândi, precum și efectul unor măsuri precum carantina, rata de infecție și vaccinarea.

## Cuprins

1. [Descriere](#descriere)
2. [Caracteristici](#caracteristici)
3. [Cum să rulezi proiectul](#cum-să-rulezi-proiectul)
4. [Structura proiectului](#structura-proiectului)
5. [Tehnologii utilizate](#tehnologii-utilizate)

## Descriere

Proiectul simulează răspândirea unei boli infectioase într-o populație de dimensiune variabilă. Utilizatorul poate ajusta parametri precum numărul de persoane, durata infecției, rata de infecție, rata de carantină și numărul de zile de simulare. Simularea poate fi vizualizată atât în mod text, cât și grafic, folosind biblioteca **SFML** pentru randare.

## Caracteristici

- **Simulare textuală**: Afișează evoluția zilnică a stării populației (sănătoși, infectați, imuni, în carantină).
- **Simulare grafică**: Vizualizare interactivă a stării populației folosind cercuri colorate pentru a reprezenta starea fiecărei persoane.
- **Parametri personalizați**: Utilizatorul poate introduce numărul de persoane, rata de infecție, rata de carantină și alți parametri.
- **Bare de stare**: Afișează procentul de persoane sănătoase, infectate, imune și în carantină.
- **Buton de ieșire**: Permite utilizatorului să oprească simularea în orice moment.

## Cum să rulezi proiectul
Opțiuni de rulare
La pornire, vei fi întrebat dacă dorești să folosești valorile implicite sau să introduci valori personalizate.

Poți alege intre un exemplu prestabilit sau variabile alese de tine.

Apoi,alege între afișarea textuală (t) sau grafică (g) a simulării.
### Cerințe preliminare

- **Compiler C++**: Asigură-te că ai un compiler C++ instalat (de exemplu, `g++` sau `clang`).
- **SFML**: Proiectul folosește biblioteca SFML pentru randarea grafică. Asigură-te că ai instalat SFML pe sistemul tău.( În proiect în acest caz)
## Structura proiectului
main.cpp: Punctul de intrare al programului.

Pandemic.h / Pandemic.cpp: Conține logica de bază a simulării.

Simulation.h / Simulation.cpp: Gestionează simularea populației și starea fiecărei persoane.

Person.h / Person.cpp: Reprezintă o persoană în simulare, cu starea sa (sănătos, infectat, imun, în carantină).

PandemicView.h / PandemicView.cpp: Gestionează afișarea simulării (atât textuală, cât și grafică).

PandemicController.h / PandemicController.cpp: Gestionează interacțiunea cu utilizatorul și controlul simulării.

PandemicViewText.cpp: Rendarea text a simulării

PandemicViewGraphical.cpp: Rendarea grafică a simulării folosind SFML

PandemicViewHelper.h / PandemicViewHelper.cpp: Ajută la randarea elementelor grafice (bare de stare, butoane etc.).

## Tehnologii utilizate
- **C+**+: Limbajul de programare principal folosit pentru dezvoltarea proiectului.

- **SFML** (Simple and Fast Multimedia Library): Folosit pentru randarea grafică și gestionarea evenimentelor.

- **STL** (Standard Template Library): Folosit pentru structuri de date precum std::vector.


