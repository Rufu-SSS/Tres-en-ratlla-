#include "Alumne2.h"
#include <iostream>
#include <cstdlib> // per a random (si vols fer IA)
#include <ctime>

using namespace std;

Alumne2::Alumne2(string nom) {
    this->nom = nom;
    this->simbol = 'O';
    this->victories = 0;
    srand(time(nullptr));
}

string Alumne2::getNom() const { return nom; }
char Alumne2::getSimbol() const { return simbol; }
int Alumne2::getVictories() const { return victories; }
void Alumne2::incrementarVictories() { victories++; }
// Versió manual (pots canviar a IA si vols)
int Alumne2::triarMoviment() const {
    int pos;
    cout << nom << " (" << simbol << "), tria una posició (0-8): ";
    cin >> pos;
    return pos;
}
