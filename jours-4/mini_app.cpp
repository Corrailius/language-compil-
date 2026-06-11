#include <iostream>
#include <string>

class Etudiant {
std::string nom;
int age; double moyenne;
public:
Etudiant(std::string n, int a) : nom(n), age(a), moyenne(0.0) {}
void ajouterNote(double note) { moyenne = (moyenne + note) / 2.0; }
bool estMajeur() const { return age >= 18; }
void afficher() const {
std::cout << nom << " (" << age << " ans)"
<< " - moyenne: " << moyenne << "\n";
}
};

int main() {
Etudiant ayoub("Ayoub", 25);
ayoub.ajouterNote(15);
ayoub.ajouterNote(17);
ayoub.afficher();
if (ayoub.estMajeur()) std::cout << "Majeur\n";
return 0;
}