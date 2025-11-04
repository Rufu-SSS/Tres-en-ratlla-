#ifndef ALUMNE2_H
#define ALUMNE2_H

#include <string>
using namespace std;
class Alumne2 {
private:
     string nom;
    char simbol;
    int victories;

public:
    Alumne2( string nom);
     string getNom() const;
    char getSimbol() const;
    int getVictories() const;
    void incrementarVictories();
    int triarMoviment() const; // pot ser jugador o IA
};

#endif
