#include <iostream>
#include <vector>
#include <stdexcept>
#include "Alumne1.h"
#include "Alumne2.h"
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
        tornActual = alumne1->getSimbol();
    }

    void inicialitzarTauler() {
        tauler = vector<char>(9, ' ');
    }

    void imprimirTauler() const {
        cout << "\n";
        cout << " " << tauler[0] << " | " << tauler[1] << " | " << tauler[2] << endl;
        cout << "---|---|---" << endl;
        cout << " " << tauler[3] << " | " << tauler[4] << " | " << tauler[5] << endl;
        cout << "---|---|---" << endl;
        cout << " " << tauler[6] << " | " << tauler[7] << " | " << tauler[8] << endl;
        cout << "\n";
    }

    bool esMovimentValid(int pos) const {
        return (pos >= 0 && pos < 9 && tauler[pos] == ' ');
    }

    void ferMoviment(int pos) {
        if (!esMovimentValid(pos))
            throw invalid_argument(" Posició no vàlida!");
        tauler[pos] = tornActual;
    }

    bool comprovarGuanyador() const {
        char s = tornActual;

        for (int i = 0; i < 3; i++)
            if (tauler[i * 3] == s && tauler[i * 3 + 1] == s && tauler[i * 3 + 2] == s)
                return true;

        for (int i = 0; i < 3; i++)
            if (tauler[i] == s && tauler[i + 3] == s && tauler[i + 6] == s)
                return true;

        if ((tauler[0] == s && tauler[4] == s && tauler[8] == s) ||
            (tauler[2] == s && tauler[4] == s && tauler[6] == s))
            return true;

        return false;
    }

    bool esTaulerPle() const {
        for (char c : tauler)
            if (c == ' ') return false;
        return true;
    }

    void canviarTorn() {
        tornActual = (tornActual == alumne1->getSimbol()) ? alumne2->getSimbol() : alumne1->getSimbol();
    }

    void jugar() {
        int pos;
        while (true) {
            imprimirTauler();

            if (tornActual == alumne1->getSimbol())
                pos = alumne1->triarMoviment();
            else
                pos = alumne2->triarMoviment();

            try {
                ferMoviment(pos);

                if (comprovarGuanyador()) {
                    imprimirTauler();
                    if (tornActual == alumne1->getSimbol()) {
                        cout << " " << alumne1->getNom() << " ha guanyat!\n";
                        alumne1->incrementarVictories();
                    }
                    else {
                        cout << " " << alumne2->getNom() << " ha guanyat!\n";
                        alumne2->incrementarVictories();
                    }
                    break;
                }

                if (esTaulerPle()) {
                    imprimirTauler();
                    cout << " Empat!\n";
                    break;
                }

                canviarTorn();
            }
            catch (const invalid_argument& e) {
                cout << e.what() << endl;
            }
        }
    }
};

// ---------- MAIN ----------
int main() {
    string nom1, nom2;
    cout << "Nom Alumne1 (X): ";
    cin >> nom1;
    cout << "Nom Alumne2 (O): ";
    cin >> nom2;

    Alumne1 a1(nom1);
    Alumne2 a2(nom2);

    Joc joc(&a1, &a2);
    joc.jugar();

    cout << "\n--- RESULTATS FINALS ---\n";
    cout << a1.getNom() << " victòries: " << a1.getVictories() << endl;
    cout << a2.getNom() << " victòries: " << a2.getVictories() << endl;

    return 0;
}
