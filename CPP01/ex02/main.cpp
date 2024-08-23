#include <iostream>
#include <string>

int main() {
	// Déclaration et initialisation de la variable string
	std::string str = "HI THIS IS BRAIN";

	// Déclaration du pointeur vers la string
	std::string* stringPTR = &str;

	// Déclaration de la référence à la string
	std::string& stringREF = str;

	// Affichage des adresses mémoire
	std::cout << "Address of str        : " << &str << std::endl;
	std::cout << "Address held by stringPTR: " << stringPTR << std::endl;
	std::cout << "Address held by stringREF: " << &stringREF << std::endl;

	// Affichage des valeurs
	std::cout << "Value of str        : " << str << std::endl;
	std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value pointed to by stringREF: " << stringREF << std::endl;

	return 0;
}
