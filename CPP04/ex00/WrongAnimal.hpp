#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal {
protected:
	std::string type;

public:
	WrongAnimal();
	~WrongAnimal();
	std::string getType() const;
	void makeSound() const; // Pas de virtual, montre le problème du polymorphisme incorrect
};

#endif
