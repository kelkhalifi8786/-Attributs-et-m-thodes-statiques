#include <iostream>
#include <string>
using namespace std;

class Produit {
private:
    string nom;
    float prixHT;
    static float tauxTVA;

public:
    Produit(const string& n, float p) : nom(n), prixHT(p) {}

    float getPrixTTC() const {
        return prixHT * (1 + tauxTVA / 100);
    }

    static void modifierTVA(float nouveauTaux) {
        tauxTVA = nouveauTaux;
    }

    void afficher() const {
        cout << nom << " - Prix TTC : " << getPrixTTC() << "€" << endl;
    }
};

float Produit::tauxTVA = 20.0f;

int main() {
    Produit p1("Stylo", 2.0);
    Produit p2("Cahier", 5.0);

    p1.afficher();
    p2.afficher();

    Produit::modifierTVA(10.0);

    cout << "Après modification de la TVA : " << endl;
    p1.afficher();
    p2.afficher();
}
