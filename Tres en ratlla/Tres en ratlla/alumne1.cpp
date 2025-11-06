#include "Alumne1.h"
#include <iostream>

using namespace std;

Alumne1::Alumne1(string nom) {
    this->nom = nom;
    this->simbol = 'X';
    this->victories = 0;
}
string Alumne1::getNomJug1() const { return nom; }
char Alumne1::getSimbolJug1() const { return simbol; }
int Alumne1::getVictoriesJug1() const { return victories; }
void Alumne1::incrementarVictoriesJug1() { victories++; }
int Alumne1::triarMovimentJug1() const {
    int pos;
    cout << nom << " (" << simbol << "), tria una posició (0-8): ";
    cin >> pos;
    return pos;
}
