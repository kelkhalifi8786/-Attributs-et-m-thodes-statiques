#include <iostream>
#include <string>
using namespace std;

class Universite {
private:
    string nom;

public:
    Universite(const string& n) : nom(n) {}
    void afficherNom() const {
        cout << nom;
    }
};

class Etudiant {
private:
    string nom;
    int age;
    Universite* universite;
    static int nbEtudiants;

public:
    Etudiant(const string& n, int a, Universite* u)
        : nom(n), age(a), universite(u) {
        nbEtudiants++;
    }

    void afficher() const {
        cout << "Nom : " << nom << ", Âge : " << age << ", Université : ";
        universite->afficherNom();
        cout << endl;
    }

    static void afficherTotal() {
        cout << "Nombre total d’étudiants : " << nbEtudiants << endl;
    }
};

int Etudiant::nbEtudiants = 0;

int main() {
    Universite u("Université de Casablanca");
    Etudiant e1("Amine", 20, &u);
    Etudiant e2("Sara", 21, &u);

    e1.afficher();
    e2.afficher();

    Etudiant::afficherTotal();
}
