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
    string getNomJug1() const;
    char getSimbolJug1() const;
    int getVictoriesJug1() const;
    void incrementarVictoriesJug1();
    int triarMovimentJug1() const; // demanar posició
};

#endif
