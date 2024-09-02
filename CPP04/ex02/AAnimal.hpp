#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include <string>

class AAnimal {
protected:
	std::string type;

public:
	AAnimal();
	virtual ~AAnimal();
	std::string getType() const;
	virtual void makeSound() const = 0; // Méthode virtuelle pure, rendant AAnimal abstraite
};

#endif
