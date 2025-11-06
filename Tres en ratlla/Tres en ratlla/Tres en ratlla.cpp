#include <iostream>
#include <vector>
#include <stdexcept>
#include "Alumne1.h"
#include "Alumne2.h"
#include <algorithm>
using namespace std;

class Joc {
private:
    vector<char> tauler;
    Alumne1* alumne1;
    Alumne2* alumne2;
    char tornActual;

public:
    Joc(Alumne1* a1, Alumne2* a2) {
        alumne1 = a1;
        alumne2 = a2;
        inicialitzarTauler();
        tornActual = alumne1->getSimbolJug1();
    }

    void inicialitzarTauler() { tauler = vector<char>(9, ' '); }
    void imprimirTauler() const {
        cout << "\n";
        cout << " " << tauler[0] << " | " << tauler[1] << " | " << tauler[2] << endl;
        cout << "---|---|---" << endl;
        cout << " " << tauler[3] << " | " << tauler[4] << " | " << tauler[5] << endl;
        cout << "---|---|---" << endl;
        cout << " " << tauler[6] << " | " << tauler[7] << " | " << tauler[8] << endl;
        cout << "\n";
    }
    bool esMovimentValid(int pos) const { return (pos >= 0 && pos < 9 && tauler[pos] == ' '); }
    void ferMoviment(int pos) {
        if (!esMovimentValid(pos))
            throw invalid_argument(" Posició no vàlida!");
        tauler[pos] = tornActual;
    }
    bool comprovarGuanyador() const {
        char s = tornActual;
        for (int i = 0; i < 3; i++) {
            if (tauler[i * 3] == s && tauler[i * 3 + 1] == s && tauler[i * 3 + 2] == s)
                return true;
        }

        for (int i = 0; i < 3; i++) {
            if (tauler[i] == s && tauler[i + 3] == s && tauler[i + 6] == s)
                return true;}

        if ((tauler[0] == s && tauler[4] == s && tauler[8] == s) ||
            (tauler[2] == s && tauler[4] == s && tauler[6] == s))
            return true;

        return false;
    }
    bool taulaPlena() const {
        for (char c : tauler)
            if (c == ' ') return false;
        return true;
    }
    void canviarTorn() {
        tornActual = (tornActual == alumne1->getSimbolJug1()) ? alumne2->getSimbolJug2() : alumne1->getSimbolJug1();
    }
    void reiniciarPartida() {
        inicialitzarTauler();
        tornActual = alumne1->getSimbolJug1();
    }
    void jugar() {
        int pos;
        while (true) {
            imprimirTauler();

            if (tornActual == alumne1->getSimbolJug1()) { pos = alumne1->triarMovimentJug1(); }
            else { pos = alumne2->triarMovimentJug2(); }
            try { ferMoviment(pos);
                if (comprovarGuanyador()) { imprimirTauler();
                    if (tornActual == alumne1->getSimbolJug1()) {
                        cout << " " << alumne1->getNomJug1() << " ha guanyat!\n";
                        alumne1->incrementarVictoriesJug1(); }
                    else { cout << " " << alumne2->getNomJug2() << " ha guanyat!\n";
                        alumne2->incrementarVictoriesJug2(); }
                    break; }
                if (taulaPlena()) { imprimirTauler(); cout << " Empat!\n"; break; }
                canviarTorn(); }
            catch (const invalid_argument& e) { cout << e.what() << endl; } } 
        reiniciarPartida();
    } 
};

// ---------- MAIN ----------
int main() {
    bool jugant=true;
    string resposta;
    string nom1, nom2; cout << "Nom Alumne1 (X): "; cin >> nom1;
    cout << "Nom Alumne2 (O): "; cin >> nom2; 
    Alumne1 a1(nom1); Alumne2 a2(nom2);
    Joc joc(&a1, &a2); 
    
    while (jugant == true) {
        joc.jugar();
        cout << "\n Vols continuar jugant? (S/Si/SI o N/No/NO): ";
        cin >> resposta;
        transform(resposta.begin(), resposta.end(), resposta.begin(), ::toupper);
        if (resposta == "S"  || resposta == "SI") {
            cout << "El joc continua!" << endl;

        }
        else if (resposta == "N" || resposta == "NO") {
            cout << "Has triat plegar!" << endl;
            jugant = false;
            break;
        }
        else {
            cout << "Resposta no vàlida!" << endl;
        }
    }
    cout << "\n--- RESULTATS FINALS ---\n";
    cout << a1.getNomJug1() << " victòries: " << a1.getVictoriesJug1() << endl;
    cout << a2.getNomJug2() << " victòries: " << a2.getVictoriesJug2() << endl;

    if (a1.getVictoriesJug1() > a2.getVictoriesJug2()) {
        cout << "El jugador " << a1.getNomJug1() << " ha guanyat més partides que el jugador " << a2.getNomJug2(); }
    else {
        cout << "El jugador " << a2.getNomJug2() << " ha guanyat més partides que el jugador " << a1.getNomJug1();
    }
    return 0;
}
