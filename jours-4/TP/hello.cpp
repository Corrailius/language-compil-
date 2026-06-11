// hello.cpp
#include <iostream>
#include <string>
int main() {
std::string nom;
std::cout << "Quel est ton nom ? ";
std::cin >> nom;
std::cout << "Bonjour " << nom << " !" << std::endl;
int age = 19;
std::cout << "Tu as " << age << " ans" << std::endl;
return 0;
}