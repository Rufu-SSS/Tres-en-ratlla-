#ifndef ALUMNE1_H
#define ALUMNE1_H

#include <string>
using namespace std;
class Alumne1 {
private:
    string nom;
    char simbol;
    int victories;

public:
    Alumne1(string nom);
    string getNom() const;
    char getSimbol() const;
    int getVictories() const;
    void incrementarVictories();
    int triarMoviment() const; // demanar posició
};

#endif
