#include <iostream>

class Compteur {
private:
int valeur;
int *historique; // tableau dynamique
int taille;
public:
Compteur(int n) { // CONSTRUCTEUR
valeur = 0; taille = n;
historique = new int[n]; // alloue sur le tas
std::cout << "Compteur cree\n";
}
~Compteur() { // DESTRUCTEUR
delete[] historique; // libere la memoire
std::cout << "Compteur detruit\n";
}
void incrementer() { valeur++; }
int lire() const { return valeur; }
};
int main() {
Compteur c(100); // constructeur appele automatiquement
c.incrementer(); c.incrementer();
std::cout << c.lire() << "\n";
// Destructeur appele AUTOMATIQUEMENT a la sortie
}