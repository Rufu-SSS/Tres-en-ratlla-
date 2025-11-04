#include "Alumne1.h"
#include <iostream>

using namespace std;

Alumne1::Alumne1(string nom) {
    this->nom = nom;
    this->simbol = 'X';
    this->victories = 0;
}
string Alumne1::getNom() const { return nom; }
char Alumne1::getSimbol() const { return simbol; }
int Alumne1::getVictories() const { return victories; }
void Alumne1::incrementarVictories() { victories++; }
int Alumne1::triarMoviment() const {
    int pos;
    cout << nom << " (" << simbol << "), tria una posició (0-8): ";
    cin >> pos;
    return pos;
}
