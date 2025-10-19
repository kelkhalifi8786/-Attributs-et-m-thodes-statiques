#include <iostream>
#include <string>
using namespace std;

class Utilisateur {
private:
    string nom;
    string role;
    static int nbUtilisateursConnectes;

public:
    Utilisateur(const string& n, const string& r) : nom(n), role(r) {
        nbUtilisateursConnectes++;
    }

    ~Utilisateur() {
        nbUtilisateursConnectes--;
    }

    static int getNbUtilisateursConnectes() {
        return nbUtilisateursConnectes;
    }

    void afficher() const {
        cout << nom << " (" << role << ")" << endl;
    }
};

int Utilisateur::nbUtilisateursConnectes = 0;

int main() {
    cout << "Utilisateurs connectés : " << Utilisateur::getNbUtilisateursConnectes() << endl;

    Utilisateur u1("Amine", "admin");
    cout << "Utilisateurs connectés : " << Utilisateur::getNbUtilisateursConnectes() << endl;

    {
        Utilisateur u2("Sara", "visiteur");
        Utilisateur u3("Khalid", "visiteur");
        cout << "Utilisateurs connectés : " << Utilisateur::getNbUtilisateursConnectes() << endl;
    }

    cout << "Utilisateurs connectés : " << Utilisateur::getNbUtilisateursConnectes() << endl;
}
