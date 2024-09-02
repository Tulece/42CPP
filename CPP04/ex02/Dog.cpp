#include "Dog.hpp"

Dog::Dog() {
	try {
		brain = new Brain();
		type = "Dog";
		std::cout << "Dog constructor called" << std::endl;
	} catch (const std::bad_alloc& e) {
		std::cerr << "Failed to allocate memory for Dog's Brain: " << e.what() << std::endl;
		brain = nullptr;
	}
}

Dog::Dog(const Dog& other) : AAnimal(other), brain(new Brain(*other.brain)) {
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
	std::cout << "Dog assignment operator called" << std::endl;
	if (this != &other) {
		AAnimal::operator=(other);
		delete brain;
		brain = new Brain(*other.brain);
	}
	return *this;
}

Dog::~Dog() {
	delete brain;
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Woof Woof!" << std::endl;
}
