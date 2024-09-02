#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();

	std::cout << j->getType() << " says: ";
	j->makeSound();

	std::cout << i->getType() << " says: ";
	i->makeSound();

	delete j;
	delete i;

	return 0;
}
