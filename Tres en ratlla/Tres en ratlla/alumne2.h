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
     string getNomJug2() const;
    char getSimbolJug2() const;
    int getVictoriesJug2() const;
    void incrementarVictoriesJug2();
    int triarMovimentJug2() const;
};

#endif
