#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
	const Animal* animals[4];

	// Création de Dog et Cat et stockage dans le tableau d'Animal*
	animals[0] = new Dog();
	animals[1] = new Cat();
	animals[2] = new Dog();
	animals[3] = new Cat();

	// Utilisation de la méthode makeSound() pour chaque Animal
	for (int i = 0; i < 4; i++) {
		std::cout << animals[i]->getType() << " says: ";
		animals[i]->makeSound();
	}

	// Nettoyage de la mémoire allouée dynamiquement
	for (int i = 0; i < 4; i++) {
		delete animals[i];
	}

	return 0;
}
