#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

class Etudiant {
    std::string nom;
    int age;
    double note;

public:
    Etudiant(const std::string& n = "", int a = 0, double no = 0.0)
        : nom(n), age(a), note(no) {}

    const std::string& getNom() const { return nom; }
    int getAge() const { return age; }
    double getNote() const { return note; }

    void afficher() const {
        std::cout << "Nom: " << nom << "\n"
                  << "Age: " << age << "\n"
                  << "Note: " << std::fixed << std::setprecision(2) << note << "\n";
    }
};

int main() {
    const int taille = 5;
    std::vector<Etudiant> etudiants;
    etudiants.reserve(taille);

    for (int i = 0; i < taille; ++i) {
        std::string nom;
        int age;
        double note;

        std::cout << "Etudiant " << (i + 1) << "\n";
        std::cout << "Nom: ";
        std::getline(std::cin >> std::ws, nom);
        std::cout << "Age: ";
        std::cin >> age;
        std::cout << "Note: ";
        std::cin >> note;
        etudiants.emplace_back(nom, age, note);
    }

    std::cout << "\nListe des etudiants:\n";
    double somme = 0.0;
    int meilleurIndex = 0;

    for (int i = 0; i < taille; ++i) {
        etudiants[i].afficher();
        std::cout << "\n";
        somme += etudiants[i].getNote();
        if (etudiants[i].getNote() > etudiants[meilleurIndex].getNote()) {
            meilleurIndex = i;
        }
    }

    double moyenne = somme / taille;
    std::cout << "Note moyenne de la promotion: " << std::fixed << std::setprecision(2) << moyenne << "\n";
    std::cout << "\nMeilleur etudiant:\n";
    etudiants[meilleurIndex].afficher();

    return 0;
}