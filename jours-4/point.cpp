// point.cpp
#include <iostream>

class Point {
    private:
    double x; // attributs caches (encapsulation)
    double y;

    public:
    // Constructeur : appele a la creation d'un Point
    Point(double xi, double yi) { x = xi; y = yi; }
    
    // Methodes : actions sur l'objet
    double getX() const { return x; }
    double getY() const { return y; }
    
    void afficher() const {
        std::cout << "(" << x << ", " << y << ")\n";
    }
};

int main() {
    Point p1(3.0, 4.0);
    Point p2(10.0, 20.0);
    p1.afficher(); p2.afficher();
    return 0;
}