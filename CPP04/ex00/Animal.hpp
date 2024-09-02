#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {
protected:
	std::string type;

public:
	Animal();
	virtual ~Animal(); // destructeur virtuel pour garantir la destruction appropriée des objets dérivés
	std::string getType() const;
	virtual void makeSound() const; // méthode virtuelle pour le polymorphisme
};

#endif
