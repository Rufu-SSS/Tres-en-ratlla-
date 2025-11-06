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

string Alumne2::getNomJug2() const { return nom; }
char Alumne2::getSimbolJug2() const { return simbol; }
int Alumne2::getVictoriesJug2() const { return victories; }
void Alumne2::incrementarVictoriesJug2() { victories++; }
int Alumne2::triarMovimentJug2() const {
    int pos;
    cout << nom << " (" << simbol << "), tria una posició (0-8): ";
    cin >> pos;
    return pos;
}
